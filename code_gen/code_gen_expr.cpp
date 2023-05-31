//
// Created by 刘宇轩 on 2023/5/28.
//

#include "code_generator.h"


// This hash assures no conflicts
static inline uint32_t GetOpHash(const char *str) {
    return (static_cast<uint32_t>(str[1])) ^ (str[0] << 1);
}

static inline bool IsNumeric(llvm::Value *v) {
    return v->getType()->isIntegerTy()
           || v->getType()->isPointerTy()
           || v->getType()->isFloatingPointTy();
}



//static const char *binary_ops[] = {
//        "+", "-", "*", "/", "%", "<<", ">>", "&&", "||", "&", "|", "^",
//        ">", "<", ">=", "<=", "==", "!="
//};
//
//static const char *unary_ops[] = {
//        "+", "-", "!", "~", "*", "&", "sizeof"
//};
//
//static const char *assign_ops[] = {
//        "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "|=", "^="
//};


extern CodeGenerator::pValue CallGenerator(const AstNode *node);

void CodeGenerator::InitBinaryOperators() {
    LOAD_BINARY_OP("+", Plus);
    LOAD_BINARY_OP("-", Sub);
    LOAD_BINARY_OP("*", Mult);
    LOAD_BINARY_OP("/", Div);
    LOAD_BINARY_OP("%", Mod);
    LOAD_BINARY_OP("<<", Shl);
    LOAD_BINARY_OP(">>", Shr);
    LOAD_BINARY_OP("|", BitOr);
    LOAD_BINARY_OP("&", BitAnd);
    LOAD_BINARY_OP("^", BitXor);
}

void CodeGenerator::InitUnaryOperators() {
    LOAD_UNARY_OP("+", UPlus);
    LOAD_UNARY_OP("-", UMinus);
    LOAD_UNARY_OP("&", AddrOf);
    LOAD_UNARY_OP("*", DeRef);
    LOAD_UNARY_OP("~", UBitNot);
    LOAD_UNARY_OP("!", ULogNot);
    LOAD_UNARY_OP("sizeof", SizeOf);
}

void CodeGenerator::InitAssignOperators() {
    LOAD_ASSIGN_OP("=", Assign);
//    LOAD_ASSIGN_OP("+=", AssignPlus);
//    LOAD_ASSIGN_OP("-=", AssignSub);
//    LOAD_ASSIGN_OP("*=", AssignMult);
//    LOAD_ASSIGN_OP("/=", AssignDiv);
}


Symbol CodeGenerator::GenExpression(const AstNode *node, bool r_value) {
    if (!node)
        return {};

    switch (node->type_) {
        case kExpr:
            return GenExpression(node->child_, r_value);
        case kId: {
            auto value = CallGenerator(node);
            if (value.IsFunction()) {
                return value;
            } else {
                return r_value ? CastToRightValue(value.GetVariable()) : value.GetVariable();
            }
        }
        case kSubScript: {
            auto value = CallGenerator(node);
            return r_value ? CastToRightValue(value.GetVariable()) : value;
        }
        case kDemNumber:
        case kHexNumber:
        case kOctNumber:
        case kCharLiteral:
        case kStrLiteral:
        case kFuncCall:
        case kFloatNumber:
        case kCast: {
            if (!r_value)
                throw_code_gen_exception(node, "term must be a right value");
            return CallGenerator(node).GetVariable();
        }
        case kUop: {
            if (r_value)
                return CodeGenerator::unary_gen_right.at(GetOpHash(node->val_))(node);
            else return CodeGenerator::unary_gen_left.at(GetOpHash(node->val_))(node);
        }
        case kBinOp: {
            if (r_value)
                return CodeGenerator::binary_gen_right.at(GetOpHash(node->val_))(node);
            else return CodeGenerator::binary_gen_left.at(GetOpHash(node->val_))(node);
        }
        case kTriOp: {
            if (r_value)
                return CodeGenerator::RGenTrinaryExpr(node);
            else return CodeGenerator::LGenTrinaryExpr(node);
        }
        case kAssign: {
            auto op_hash = GetOpHash(node->val_);
            if (op_hash == GetOpHash("=")) {
                if (r_value)
                    return RGenAssign(node);
                else return LGenAssign(node);
            } else {
                auto op_func = binary_gen_right.at(op_hash);
                if (r_value)
                    return CastToRightValue(DefaultAssignGen(node, op_func).GetVariable());
                else return DefaultAssignGen(node, op_func);
            }
        }
        case KUAsign: {
            /*
             * prefix: left value, post_fix: right value
             * _++, _--, ++_, --_
             */
            bool is_add = node->val_[1] == '+';
            bool is_prefix = node->val_[0] != '_';
            auto result = SelfPSValue(node, is_prefix, is_add).GetVariable();
            if (r_value) {
                return is_prefix ? CastToRightValue(result) : result;
            } else {
                if (!is_prefix)
                    throw_code_gen_exception(node, "postfix cannot be a right value");
                return result;
            }


        }
        case kStructMember: {
            if (r_value)
                return CodeGenerator::RGenMemOf(node);
            else return CodeGenerator::LGenMemOf(node);
        }
        default:
            assert(false && "Not Implemented yet");

    }
}

inline static bool IsPtrOperation(llvm::Value *&lhs, llvm::Value *&rhs) {
    if (lhs->getType()->isPointerTy() && rhs->getType()->isIntegerTy())
        return true;
    if (lhs->getType()->isIntegerTy() && rhs->getType()->isPointerTy()) {
        std::swap(lhs, rhs);
        return true;
    } else return false;
}

inline static bool IsSameTypePtr(llvm::Value *lhs, llvm::Value *rhs) {
    return lhs->getType()->isPointerTy() && rhs->getType()->isPointerTy()
           && lhs->getType() == rhs->getType();
}

llvm::Value *CodeGenerator::RunAdd(llvm::Value *lhs, llvm::Value *rhs) {
    if (IsPtrOperation(lhs, rhs)) {
        auto type = lhs->getType()->getNonOpaquePointerElementType();
        return IR_builder.CreateGEP(type, lhs, rhs);
    }
    auto f_add = PACK_METHOD(IR_builder.CreateFAdd);
    auto i_add = PACK_METHOD(IR_builder.CreateAdd);
    return RunOpNumNum(i_add, f_add, lhs, rhs);
}

llvm::Value *CodeGenerator::RunSub(llvm::Value *lhs, llvm::Value *rhs) {
    if (IsPtrOperation(lhs, rhs)) {
        auto type = lhs->getType()->getNonOpaquePointerElementType();
        return IR_builder.CreateGEP(type, lhs, IR_builder.CreateNeg(rhs));
    }
    if (IsSameTypePtr(lhs, rhs)) {
        auto type = lhs->getType()->getNonOpaquePointerElementType();
        return IR_builder.CreatePtrDiff(type, lhs, rhs);
    }
    auto f_sub = PACK_METHOD(IR_builder.CreateFSub);
    auto i_sub = PACK_METHOD(IR_builder.CreateSub);
    return RunOpNumNum(i_sub, f_sub, lhs, rhs);
}

Symbol CodeGenerator::AssignValue(llvm::Value *lhs, llvm::Value *rhs, const AstNode *node) {
    rhs = CastToType(lhs->getType()->getNonOpaquePointerElementType(), rhs);
    if (!rhs) {
        throw_code_gen_exception(node, "incompatible assignment");
    }
    IR_builder.CreateStore(rhs, lhs);
    return lhs;
}

Symbol CodeGenerator::SelfPSValue(const AstNode *node, bool is_prefix, bool is_add) {
    auto prefix_val = GenExpression(node->child_, false).GetVariable();
    if (!prefix_val || !IsNumeric(prefix_val))
        throw_code_gen_exception(node, R"('++' or '--' must be applied to number or pointers)");
    auto postfix_val = CastToRightValue(prefix_val);
    auto one = IR_builder.getInt1(true); // lowest priority
    llvm::Value *result;

    auto f_add = PACK_METHOD(IR_builder.CreateFAdd);
    auto f_sub = PACK_METHOD(IR_builder.CreateFSub);
    auto i_add = PACK_METHOD(IR_builder.CreateAdd);
    auto i_sub = PACK_METHOD(IR_builder.CreateSub);
    if (is_add)
        result = RunOpNumNum(i_add, f_add, postfix_val, one);
    else
        result = RunOpNumNum(i_sub, f_sub, postfix_val, one);
    IR_builder.CreateStore(result, prefix_val);

    return is_prefix ? prefix_val : postfix_val;
}

Symbol CodeGenerator::DefaultAssignGen(const AstNode *node, const GenFunc &bin_op) {
    auto to_assign = GenExpression(node->child_, false);
    auto value_got = bin_op(node);
    return AssignValue(to_assign.GetVariable(), value_got.GetVariable(), node);
}


Symbol CodeGenerator::LGenMemOf(const AstNode *node) {
    ASSERT_TYPE(node, kStructMember);
    llvm::Value *struct_id;

    if (node->val_[0] == '.')
        struct_id = GenExpression(node->child_, false).GetVariable();
    else struct_id = GenExpression(node->child_, true).GetVariable();
    assert(struct_id);

    auto mem_name = std::string{getNChildSafe(node, 1)->val_};
    if (!struct_id->getType()->isPointerTy()
        || !struct_id->getType()->getNonOpaquePointerElementType()->isStructTy()
            ) {
        throw_code_gen_exception(node, R"(operator '.' or '->' must be applied to structures)");
    }
    auto name = struct_id->getType()->getNonOpaquePointerElementType()->getStructName().str();
    assert(struct_type_table.contains(name));

    auto members = struct_type_table[name];
    cur_node = GetSymbolTypeTree(name + mem_name);

    if (!members.contains(mem_name)) {
        throw_code_gen_exception(node, "unrecognized member name");
    }

    auto mem_idx = members[mem_name].first;

    std::vector<llvm::Value *> index_list;
    index_list.push_back(IR_builder.getInt32(0));
    index_list.push_back(IR_builder.getInt32(mem_idx));

    return IR_builder.CreateGEP(struct_id->getType()->getNonOpaquePointerElementType(),
                                struct_id, index_list);

}

Symbol CodeGenerator::RGenTrinaryExpr(const AstNode *node) {
    auto cond = CastToBool(GenExpression(getNChildSafe(node, 0)).GetVariable());
    if (!cond) {
        throw_code_gen_exception(node, "invalid conversion to bool");
    }
    auto clause_t = GenExpression(getNChildSafe(node, 1)).GetVariable();
    auto clause_f = GenExpression(getNChildSafe(node, 2)).GetVariable();
    try {
        AlignType(clause_f, clause_t);
    } catch (std::exception &e) {
        throw_code_gen_exception(node, e.what());
    }
    return IR_builder.CreateSelect(cond, clause_t, clause_f);
}

Symbol CodeGenerator::LGenTrinaryExpr(const AstNode *node) {
    auto cond = CastToBool(GenExpression(getNChildSafe(node, 0)).GetVariable());
    if (!cond) {
        throw_code_gen_exception(node, "invalid conversion to bool");
    }
    auto clause_t = GenExpression(getNChildSafe(node, 1), false).GetVariable();
    auto clause_f = GenExpression(getNChildSafe(node, 2), false).GetVariable();
    try {
        AlignType(clause_f, clause_t);
    } catch (std::exception &e) {
        throw_code_gen_exception(node, e.what());
    }
    return IR_builder.CreateSelect(cond, clause_t, clause_f);
}







/*Binary Operators*/

