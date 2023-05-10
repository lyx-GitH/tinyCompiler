//
// Created by 刘宇轩 on 2023/5/10.
//

#ifndef TINYCOMPILER_AST_H
#define TINYCOMPILER_AST_H

#include <memory>
#include <utility>

/**
 * This file describes all ast structures used in the TinyCompiler
 */

// base for all asts
class ExprAst {
public:
    using UniqueAstPtr = std::unique_ptr<ExprAst>;

    ExprAst() = default;

    virtual ~ExprAst() = default;
};

// Example of an extended Ast
class IfStmtAst : public ExprAst {
public:
    IfStmtAst() = default;

private:
    UniqueAstPtr condition_;
    UniqueAstPtr cond_true_expr_;
    UniqueAstPtr cond_false_expr_;
};

#endif //TINYCOMPILER_AST_H
