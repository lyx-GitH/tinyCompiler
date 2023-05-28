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

static std::map<uint64_t, std::shared_ptr<char>> blocks;
static const int BLOCK_SIZE = 64;

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
    static T *GetMyType(T *ptr, bool is_const = false, bool direct = false) {
        if(direct)
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

};


#endif //TINYCOMPILER_TYPE_FACTORY_H
