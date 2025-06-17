#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

void init_array(IntArray *arr, int size) {
    if (arr->array != NULL) {
        free(arr->array);
        arr->array = NULL;
        arr->size = 0;
    }
    arr->array = malloc(size * sizeof(int));
    arr->size = size;
}

void fill_array_random(IntArray *arr) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < arr->size; i++) {
        arr->array[i] = rand() % 100000; 
    }
}

void display_array(const IntArray *arr) {
    if (arr->array == NULL) {
        printf("Array is not initialized.\n");
        return;
    }
    printf("Array elements:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

void free_array(IntArray *arr) {
    if (arr->array) {
        free(arr->array);
        arr->array = NULL;
    }
    arr->size = 0;
}

int linear_search(const IntArray *arr, int key) {
    if (arr->array == NULL) return -1;
    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(const IntArray *arr, int key) {
    if (arr->array == NULL) return -1;
    int left = 0, right = arr->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr->array[mid] == key) {
            return mid;
        } else if (arr->array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return -1;
}

void bubble_sort(IntArray *arr) {
    if (arr->array == NULL) return;
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->array[j] > arr->array[j + 1]) {
                int temp = arr->array[j];
                arr->array[j] = arr->array[j + 1];
                arr->array[j + 1] = temp;
            }
        }
    }
}

void print_menu() {
    printf("\nMenu:\n");
    printf("%d) Initialize array with random numbers\n", INIT_ARRAY);
    printf("%d) Display array\n", DISPLAY_ARRAY);
    printf("%d) Free array memory\n", FREE_ARRAY);
    printf("%d) Linear search\n", LINEAR_SEARCH);
    printf("%d) Binary search\n", BINARY_SEARCH);
    printf("%d) Run empirical time analysis\n", RUN_ANALYSIS);
    printf("%d) Exit\n", EXIT);
    printf("Enter your choice: ");
}

void switch_choice(int choice, IntArray *arr) {
    int key, index;
    clock_t start, end;
    double time_taken;

    switch(choice) {
        case INIT_ARRAY:
            if (arr->array != NULL) {
                free_array(arr);
            }
            printf("Enter array size: ");
            scanf("%d", &arr->size);
            if (arr->size <= 0) {
                printf("Invalid size.\n");
                arr->size = 0;
                return;
            }
            init_array(arr, arr->size);
            fill_array_random(arr);
            printf("Array initialized with %d random elements.\n", arr->size);
            break;

        case DISPLAY_ARRAY:
            display_array(arr);
            break;

        case FREE_ARRAY:
            free_array(arr);
            printf("Array memory freed.\n");
            break;

        case LINEAR_SEARCH:
            if (arr->array == NULL) {
                printf("Array is not initialized.\n");
                break;
            }
            printf("Enter number to search (linear): ");
            scanf("%d", &key);

            start = clock();
            index = linear_search(arr, key);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            if (index != -1) {
                printf("Found at index %d\n", index);
            } else {
                printf("Not found.\n");
            }
            printf("Linear search took %.6f seconds.\n", time_taken);
            break;

        case BINARY_SEARCH:
            if (arr->array == NULL) {
                printf("Array is not initialized.\n");
                break;
            }
            // sort array first
            bubble_sort(arr);
            printf("Array sorted for binary search.\n");
            printf("Enter number to search (binary): ");
            scanf("%d", &key);

            start = clock();
            index = binary_search(arr, key);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            if (index != -1) {
                printf("Found at index %d\n", index);
            } else {
                printf("Not found.\n");
            }
            printf("Binary search took %.6f seconds.\n", time_taken);
            break;

        case RUN_ANALYSIS:
            run_analysis();
            break;

        case EXIT:
            free_array(arr);
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
    }
}

void run_analysis() {
    int sizes[] = {100, 1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int searches = 10000;

    printf("\nEmpirical analysis of search times (in seconds) for %d searches:\n", searches);
    printf(" N\tLinear Search\tBinary Search\n");

    for (int i = 0; i < num_sizes; i++) {
        IntArray arr;
        arr.array = NULL;
        arr.size = 0;

        init_array(&arr, sizes[i]);
        fill_array_random(&arr);

        // Linear search time
        clock_t start = clock();
        for (int j = 0; j < searches; j++) {
            int key = rand() % 100000; 
            linear_search(&arr, key);
        }
        clock_t end = clock();
        double linear_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        bubble_sort(&arr);
        start = clock();
        for (int j = 0; j < searches; j++) {
            int key = rand() % 100000;
            binary_search(&arr, key);
        }
        end = clock();
        double binary_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\n", sizes[i], linear_time, binary_time);

        free_array(&arr);
    }
}
