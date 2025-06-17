#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main() {
    IntArray arr = {NULL, 0};
    int choice;

    while (1) {
        printf("\n");
        printf("%d) Initialize array with random numbers\n", INIT_ARRAY);
        printf("%d) Display array\n", DISPLAY_ARRAY);
        printf("%d) Free array memory\n", FREE_ARRAY);
        printf("%d) Simple sort (Selection Sort)\n", SORT_SIMPLE);
        printf("%d) Advanced sort (Quick Sort)\n", SORT_ADVANCED);
        printf("%d) Analyze sorting times\n", ANALYZE_TIME);
        printf("%d) Exit\n", EXIT);
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case INIT_ARRAY: {
                printf("Enter array size: ");
                int size;
                if (scanf("%d", &size) != 1 || size <= 0) {
                    printf("Invalid size.\n");
                    break;
                }
                init_array(&arr, size);
                fill_array_random(&arr);
                printf("Array initialized with random values.\n");
                break;
            }
            case DISPLAY_ARRAY:
                display_array(&arr);
                break;
            case FREE_ARRAY:
                free_array(&arr);
                printf("Memory freed.\n");
                break;
            case SORT_SIMPLE: {
                if (!arr.array) {
                    printf("Array not initialized!\n");
                    break;
                }
                clock_t start = clock();
                simple_sort(&arr);
                clock_t end = clock();
                double elapsed_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
                printf("Array sorted with Selection Sort in %.2f ms.\n", elapsed_ms);
                break;
            }
            case SORT_ADVANCED: {
                if (!arr.array) {
                    printf("Array not initialized!\n");
                    break;
                }
                clock_t start = clock();
                advanced_sort(&arr);
                clock_t end = clock();
                double elapsed_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
                printf("Array sorted with Quick Sort in %.2f ms.\n", elapsed_ms);
                break;
            }
            case ANALYZE_TIME:
                analyze_sorting_times();
                break;
            case EXIT:
                free_array(&arr);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
