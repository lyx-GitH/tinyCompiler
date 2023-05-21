//
// Created by 刘宇轩 on 2023/5/20.
//

#ifndef TINYCOMPILER_TYPE_CHECKS_H
#define TINYCOMPILER_TYPE_CHECKS_H



#ifdef __cplusplus
extern "C" {
#endif

void add_type(const char *type_name);

int has_type(const char *type_name);

#ifdef __cplusplus
}
#endif


#endif //TINYCOMPILER_TYPE_CHECKS_H
