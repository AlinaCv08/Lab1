#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

void init_array(IntArray *arr, int size) {
    if (arr->array != NULL) {
        free(arr->array);
    }
    arr->array = malloc(size * sizeof(int));
    arr->size = size;
    if (!arr->array) {
        printf("Memory allocation error!\n");
        exit(1);
    }
}
void fill_array_random(IntArray *arr) {
    if (!arr->array) {
        printf("Array is not initialized!\n");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % 100000; 
    }
}
void display_array(const IntArray *arr) {
    if (!arr->array) {
        printf("Array is not initialized!\n");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

void free_array(IntArray *arr) {
    if (arr->array) {
        free(arr->array);
        arr->array = NULL;
        arr->size = 0;
    }
}

// Selection sort

void simple_sort(IntArray *arr) {
    if (!arr->array) {
        printf("Array is not initialized!\n");
        return;
    }
    int i, j, min_idx, temp;
    for (i = 0; i < arr->size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < arr->size; j++) {
            if (arr->array[j] < arr->array[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr->array[i];
            arr->array[i] = arr->array[min_idx];
            arr->array[min_idx] = temp;
        }
    }
}

// Quick sort

static void quick_sort_recursive(int *arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j
