#ifndef FUNCS_H
#define FUNCS_H

#include "structs.h"

void bigint_init(BigInt *num, const char *str);
void bigint_print(const BigInt *num);
void bigint_add(const BigInt *a, const BigInt *b, BigInt *result);

void fibonacci(int n, BigInt *result);

void analyze_fibonacci();

#endif
