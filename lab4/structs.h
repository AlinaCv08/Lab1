#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct student {
    char *first_name;
    char *last_name;
    int birth_year;
    float average;
} Student;

typedef struct Node {
    int key;
    struct student student_info;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinaryTree {
    Node *root;
} BinaryTree;

enum CHOICE {
    EXIT = 0,
    READ_TREE,
    PRINT_TREE,
    SEARCH_NODE,
    SVD,
    VSD,
    SDV,
    BSF,
    DSF,
    TREE_BALANCE,
    TREE_MIRROR,
    CLEAN_TREE,
    FREE_MEMORY
};

#endif
