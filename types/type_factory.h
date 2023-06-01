//
// Created by 刘宇轩 on 2023/5/20.
//

#ifndef TINYCOMPILER_TYPE_FACTORY_H
#define TINYCOMPILER_TYPE_FACTORY_H

#include <string>
#include <utility>
#include <map>
#include <llvm/IR/Type.h>
#include <concepts>
#include <llvm/IR/Value.h>

static std::map<uint64_t, std::shared_ptr<char>> blocks;
static const int BLOCK_SIZE = 64;

class TypeCache {
public:
    static std::map<uint64_t, uint64_t> const_to_trivial;
};

class TypeFactory {


private:
    static inline void _SetConst(char *block, bool is_const = true) {
        block[BLOCK_SIZE - 1] |= static_cast<char>(is_const);
    }

    static inline bool _IsConst(char *block) {
        return static_cast<bool>(block[BLOCK_SIZE - 1]);
    }

    static inline uint64_t GetHash(void *p, bool is_c) {
        return reinterpret_cast<uint64_t>(p) | static_cast<uint64_t>(is_c);
    }

    template<typename T>
    requires
    std::is_base_of_v<llvm::Type, T>
    static T *GetMyType(T *ptr, bool is_const = false, bool direct = true) {
        if (direct)
            return ptr;
        auto hash = GetHash(ptr, is_const);
        if (blocks.contains(hash))
            return reinterpret_cast<T *>(blocks.at(hash).get());
        auto size = sizeof(T);
        assert(size < BLOCK_SIZE - 1);
        std::shared_ptr<char[]> block(new char[BLOCK_SIZE]());
        memcpy(block.get(), ptr, size);
        _SetConst(block.get(), is_const);

        blocks[hash] = block;
        hash = GetHash(block.get(), is_const);
        blocks[hash] = block;
        if (is_const) {
            TypeCache::const_to_trivial[(uint64_t) block.get()] = (uint64_t) ptr;
        }
        return reinterpret_cast<T *>(blocks[hash].get());

    }

public:


    template<typename T, typename... Args>
    requires
    std::is_base_of_v<llvm::Type, T>
    static T *Get(Args &&...args) {
        return GetMyType<T>(T::get(std::forward<Args>(args)...));
    }

    template<typename T, typename... Args>
    requires
    std::is_base_of_v<llvm::Type, T>
    static T *GetConst(Args &&...args) {
        return GetMyType<T>(T::get(std::forward<Args>(args)...), true);
    }

    template<typename T, typename... Args>
    requires
    std::is_base_of_v<llvm::Type, T>
    static T *Get(T *ptr) {
        return GetMyType<T>(ptr);
    }


    template<typename T>
    requires
    std::is_base_of_v<llvm::Type, T>
    static T *GetConstTypeOf(T *ptr) {
        return GetMyType(ptr, true);
    }

    template<typename T>
    requires
    std::is_base_of_v<llvm::Type, T>
    static bool IsConst(T *ptr) {
        return _IsConst(reinterpret_cast<char *>(ptr));
    }

    template<typename T>
    requires
    std::is_base_of_v<llvm::Type, T>
    static bool IsActuallySameType(T *t1, T *t2) {
        if (t1 == t2)
            return true;
        auto t1_i = reinterpret_cast<uint64_t>(t1);
        auto t2_i = reinterpret_cast<uint64_t>(t2);
        if (TypeCache::const_to_trivial.contains(t1_i) && TypeCache::const_to_trivial[t1_i] == t2_i)
            return true;
        if (TypeCache::const_to_trivial.contains(t2_i) && TypeCache::const_to_trivial[t2_i] == t1_i)
            return true;
        return false;

    }

    static llvm::Type *GetNonArrayType(llvm::Type *type) {
        if (type->isArrayTy()) {
            auto ele_type = type->getArrayElementType();
            return (llvm::Type *) ele_type->getPointerTo();
        }
        return type;
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

};


#endif //TINYCOMPILER_TYPE_FACTORY_H
