//
// Created by 刘宇轩 on 2023/5/20.
//

#ifndef TINYCOMPILER_TYPE_H
#define TINYCOMPILER_TYPE_H

#include <string>
#include <utility>
#include <map>
#include <llvm/IR/Type.h>
#include <concepts>

static const int BLOCK_SIZE = 64;
static const int CONST_MASK = 1 << 1;
static std::map<uint64_t, std::shared_ptr<char>> blocks;

static inline void SetConst(char *block, bool is_const = true) {
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
T *GetMyType(T *ptr, bool is_const = false) {
    auto hash = GetHash(ptr, is_const);
    if (blocks.contains(hash))
        return reinterpret_cast<T *>(blocks.at(hash).get());
    auto size = sizeof(T);
    assert(size < BLOCK_SIZE - 1);
    std::shared_ptr<char[]> block(new char[BLOCK_SIZE]());
    memcpy(block.get(), ptr, size);
    SetConst(block.get(), is_const);
    hash = GetHash(block.get(), is_const);
    blocks[hash] = block;
    return reinterpret_cast<T *>(blocks[hash].get());
}

template<typename T>
requires
std::is_base_of_v<llvm::Type, T>
bool IsConst(T *ptr) {
    return _IsConst(reinterpret_cast<char *>(ptr));
}

//struct TCType<llvm::Type> p;

//namespace tc {
//    class Type {
//    public:
//        Type() = default;
//
//        Type(llvm::Type *type) : type_(type) {}
//
//        Type(llvm::Type *type, bool is_const) : type_(type), is_const_(is_const) {}
//
//        operator llvm::Type *() {
//            return type_;
//        }
//
//        bool IsConst() const{
//            return is_const_;
//        }
//
//        Type MarkConst() {
//            is_const_ = true;
//            return *this;
//        }
//
//    private:
//        llvm::Type *type_ = nullptr;
//        bool is_const_ = false;
//
//    };
//}

#endif //TINYCOMPILER_TYPE_H
