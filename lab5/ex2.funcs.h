#ifndef FUNCS_H
#define FUNCS_H

#include "structs.h"

void init_array(IntArray *arr, int size);
void fill_array_random(IntArray *arr);
void display_array(const IntArray *arr);
void free_array(IntArray *arr);
int linear_search(const IntArray *arr, int key);
int binary_search(const IntArray *arr, int key);
void bubble_sort(IntArray *arr);
void print_menu();
void switch_choice(int choice, IntArray *arr);
void run_analysis();

#endif
