#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

BinaryTree *create_binary_tree() {
    return calloc(1, sizeof(BinaryTree));
}

Student read_student() {
    Student *new_student = malloc(sizeof(Student));
    new_student->first_name = malloc(50);
    new_student->last_name = malloc(50);
    printf("First name: ");
    scanf("%s", new_student->first_name);
    printf("Last name: ");
    scanf("%s", new_student->last_name);
    printf("Birth year: ");
    scanf("%d", &new_student->birth_year);
    printf("Average grade: ");
    scanf("%f", &new_student->average);
    return *new_student;
}

Node *create_node(Student new_student, int key) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->student_info = new_student;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(Node *current_node, Node *new_node) {
    if (new_node->key < current_node->key) {
        if (current_node->left)
            insert_node(current_node->left, new_node);
        else
            current_node->left = new_node;
    } else if (new_node->key > current_node->key) {
        if (current_node->right)
            insert_node(current_node->right, new_node);
        else
            current_node->right = new_node;
    }
}

void insert_node_in_tree(BinaryTree *tree, Node *new_node) {
    if (!tree->root)
        tree->root = new_node;
    else
        insert_node(tree->root, new_node);
}

void print_student(Student s) {
    printf("First name: %s\n", s.first_name);
    printf("Last name: %s\n", s.last_name);
    printf("Birth year: %d\n", s.birth_year);
    printf("Average: %.2f\n", s.average);
}

void print_node(const Node *node) {
    printf("Key: %d\n", node->key);
    print_student(node->student_info);
}

void print_tree_helper(Node *node) {
    if (!node) return;
    print_node(node);
    print_tree_helper(node->left);
    print_tree_helper(node->right);
}

void print_binary_tree(const BinaryTree *tree) {
    if (!tree->root) return;
    print_tree_helper(tree->root);
}

void svd_traversal_helper(const Node *node) {
    if (!node) return;
    svd_traversal_helper(node->left);
    printf("%d ", node->key);
    svd_traversal_helper(node->right);
}

void svd_traversal(const BinaryTree *tree) {
    printf("In-order traversal: ");
    svd_traversal_helper(tree->root);
    printf("\n");
}

void vsd_traversal_helper(const Node *node) {
    if (!node) return;
    printf("%d ", node->key);
    vsd_traversal_helper(node->left);
    vsd_traversal_helper(node->right);
}

void vsd_traversal(const BinaryTree *tree) {
    printf("Pre-order traversal: ");
    vsd_traversal_helper(tree->root);
    printf("\n");
}

void sdv_traversal_helper(const Node *node) {
    if (!node) return;
    sdv_traversal_helper(node->left);
    sdv_traversal_helper(node->right);
    printf("%d ", node->key);
}

void sdv_traversal(const BinaryTree *tree) {
    printf("Post-order traversal: ");
    sdv_traversal_helper(tree->root);
    printf("\n");
}

void store_nodes_in_array_helper(Node *node, Node **array, int *index) {
    if (!node) return;
    store_nodes_in_array_helper(node->left, array, index);
    array[(*index)++] = node;
    store_nodes_in_array_helper(node->right, array, index);
}

Node **store_BST_in_array(const BinaryTree *tree, int count) {
    int index = 0;
    Node **array = malloc(sizeof(Node *) * count);
    store_nodes_in_array_helper(tree->root, array, &index);
    return array;
}

Node *convert_array_to_BST(Node **nodes, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node *root = nodes[mid];
    root->left = convert_array_to_BST(nodes, start, mid - 1);
    root->right = convert_array_to_BST(nodes, mid + 1, end);
    return root;
}

Node *balance_tree(const BinaryTree *tree) {
    int count = 0;
    Node *tmp = tree->root;
    while (tmp) {
        count++;
        tmp = tmp->right;
    }
    Node **array = store_BST_in_array(tree, count);
    Node *new_root = convert_array_to_BST(array, 0, count - 1);
    free(array);
    return new_root;
}

void mirror_tree_helper(Node *node) {
    if (!node) return;
    mirror_tree_helper(node->left);
    mirror_tree_helper(node->right);
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void mirror_tree(const BinaryTree *tree) {
    mirror_tree_helper(tree->root);
}

Node *search_by_key_helper(Node *node, int key) {
    if (!node || node->key == key) return node;
    if (key < node->key) return search_by_key_helper(node->left, key);
    return search_by_key_helper(node->right, key);
}

Node *search_node_by_key(BinaryTree *tree, int key) {
    return search_by_key_helper(tree->root, key);
}

void delete_node(Node *node) {
    if (!node) return;
    delete_node(node->left);
    delete_node(node->right);
    free(node);
}

void delete_tree(BinaryTree *tree) {
    delete_node(tree->root);
    tree->root = NULL;
}

int get_height(const Node *node) {
    if (!node) return 0;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return (left > right ? left : right) + 1;
}

void print_level(const Node *node, int level) {
    if (!node) return;
    if (level == 1)
        printf("%d ", node->key);
    else {
        print_level(node->left, level - 1);
        print_level(node->right, level - 1);
    }
}

void bsf_traversal_recursive(const BinaryTree *tree) {
    int h = get_height(tree->root);
    for (int i = 1; i <= h; i++)
        print_level(tree->root, i);
    printf("\n");
}

void print_menu() {
    printf("\n%d) Add student\n", READ_TREE);
    printf("%d) Show tree\n", PRINT_TREE);
    printf("%d) Search student by key\n", SEARCH_NODE);
    printf("%d) In-order traversal\n", SVD);
    printf("%d) Pre-order traversal\n", VSD);
    printf("%d) Post-order traversal\n", SDV);
    printf("%d) Breadth-first traversal\n", BSF);
    printf("%d) Depth-first traversal\n", DSF);
    printf("%d) Balance tree\n", TREE_BALANCE);
    printf("%d) Mirror tree\n", TREE_MIRROR);
    printf("%d) Clear tree\n", CLEAN_TREE);
    printf("%d) Exit\n", EXIT);
}

void switch_choice(int choice, BinaryTree *tree) {
    int key;
    Student student_info;
    Node *node;

    switch (choice) {
        case READ_TREE:
            student_info = read_student();
            printf("Enter student key: ");
            scanf("%d", &key);
            node = create_node(student_info, key);
            insert_node_in_tree(tree, node);
            break;
        case PRINT_TREE:
            print_binary_tree(tree);
            break;
        case SEARCH_NODE:
            printf("Enter key to search: ");
            scanf("%d", &key);
            node = search_node_by_key(tree, key);
            if (node)
                print_node(node);
            else
                printf("Student not found.\n");
            break;
        case SVD:
            svd_traversal(tree);
            break;
        case VSD:
            vsd_traversal(tree);
            break;
        case SDV:
            sdv_traversal(tree);
            break;
        case BSF:
            bsf_traversal_recursive(tree);
            break;
        case TREE_BALANCE:
            tree->root = balance_tree(tree);
            break;
        case TREE_MIRROR:
            mirror_tree(tree);
            break;
        case CLEAN_TREE:
            delete_tree(tree);
            break;
        case EXIT:
            delete_tree(tree);
            free(tree);
            exit(0);
        default:
            printf("Invalid choice.\n");
    }
}
