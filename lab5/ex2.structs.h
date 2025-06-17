#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int *array;
    int size;
} IntArray;

enum CHOICE {
    EXIT = 0,
    INIT_ARRAY = 1,
    DISPLAY_ARRAY,
    FREE_ARRAY,
    LINEAR_SEARCH,
    BINARY_SEARCH,
    RUN_ANALYSIS
};

#endif
