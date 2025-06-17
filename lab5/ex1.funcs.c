#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

// Inițializarea vectorului
void init_array(IntArray *arr, int size) {
    if (arr->array != NULL) {
        free(arr->array);
    }
    arr->array = malloc(size * sizeof(int));
    arr->size = size;
    if (!arr->array) {
        printf("Eroare la alocarea memoriei!\n");
        exit(1);
    }
}

// Umplerea vectorului cu numere aleatorii
void fill_array_random(IntArray *arr) {
    if (!arr->array) {
        printf("Vectorul nu este initializat!\n");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % 100000; // valori random intre 0 și 99999
    }
}

// Afișarea vectorului
void display_array(const IntArray *arr) {
    if (!arr->array) {
        printf("Vectorul nu este initializat!\n");
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

// Eliberarea memoriei vectorului
void free_array(IntArray *arr) {
    if (arr->array) {
        free(arr->array);
        arr->array = NULL;
        arr->size = 0;
    }
}

// --- Sortare simplă: Selection sort ---

void simple_sort(IntArray *arr) {
    if (!arr->array) {
        printf("Vectorul nu este initializat!\n");
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

// --- Sortare avansată: Quick sort ---

static void quick_sort_recursive(int *arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quick_sort_recursive(arr, low, i - 1);
    quick_sort_recursive(arr, i + 1, high);
}

void advanced_sort(IntArray *arr) {
    if (!arr->array) {
        printf("Vectorul nu este initializat!\n");
        return;
    }
    quick_sort_recursive(arr->array, 0, arr->size - 1);
}


void analyze_sorting_times() {
    int sizes[] = {100, 1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("N\tSelectionSort(ms)\tQuickSort(ms)\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        IntArray arr1 = {NULL, 0};
        IntArray arr2 = {NULL, 0};
        init_array(&arr1, n);
        init_array(&arr2, n);

        for (int j = 0; j < n; j++) {
            int val = rand() % 100000;
            arr1.array[j] = val;
            arr2.array[j] = val;
        }

        clock_t start = clock();
        simple_sort(&arr1);
        clock_t end = clock();
        double time_selection = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        start = clock();
        advanced_sort(&arr2);
        end = clock();
        double time_quick = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        printf("%d\t%.2f\t\t\t%.2f\n", n, time_selection, time_quick);

        free_array(&arr1);
        free_array(&arr2);
    }
}
