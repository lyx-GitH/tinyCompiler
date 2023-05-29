//
// Created by 刘宇轩 on 2023/5/20.
//

#include "type_factory.h"
//
//std::map<uint64_t, std::shared_ptr<char>> TypeStorage::blocks;
//std::map<uint64_t, uint64_t> TypeStorage::const_to_trivial;
std::map<uint64_t, uint64_t> TypeCache::const_to_trivial;