//
// Created by 刘宇轩 on 2023/5/21.
//

#ifndef TINYCOMPILER_SEMATICS_H
#define TINYCOMPILER_SEMATICS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../ast/ast.h"
#include "../types/type_checks.h"

void semantics_init();

int is_const_expr(pAstNode node);

int64_t eval_const_expr(pAstNode node);

void assert_valid_typedefs(pAstNode declares);

#ifdef __cplusplus
}
#endif

#endif //TINYCOMPILER_SEMATICS_H
