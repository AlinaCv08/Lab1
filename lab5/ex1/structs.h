#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int *array;
    int size;
} IntArray;

enum CHOICE {
    EXIT = 0,
    INIT_ARRAY,
    DISPLAY_ARRAY,
    FREE_ARRAY,
    SORT_SIMPLE,
    SORT_ADVANCED,
    ANALYZE_TIME
};

#endif
