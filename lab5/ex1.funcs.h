#ifndef FUNCS_H
#define FUNCS_H

#include "structs.h"

#include <time.h>
void init_array(IntArray *arr, int size);
void fill_array_random(IntArray *arr);
void display_array(const IntArray *arr);
void free_array(IntArray *arr);
void simple_sort(IntArray *arr);
void advanced_sort(IntArray *arr);
void analyze_sorting_times();

#endif
