//
// Created by 刘宇轩 on 2023/5/20.
//

#ifndef TINYCOMPILER_TYPE_CHECKS_H
#define TINYCOMPILER_TYPE_CHECKS_H



//void SetType(const char *name, void *llvm_type);
//
//void* GetType(const char *name);
//
//void AddTypeAlias(const char *name, void *llvm_type);
//
//void AddHiddenTypeAlias(const char *name, void *llvm_type);


#ifdef __cplusplus
extern "C" {
#endif
#include <assert.h>

void add_type(const char *type_name);

void add_hidden_type(const char *type_name);

int has_type(const char *type_name);


#ifdef __cplusplus
}
#endif


#endif //TINYCOMPILER_TYPE_CHECKS_H
