#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

BinaryTree *create_binary_tree();
Student read_student();
Node *create_node(Student new_student, int key);
void insert_node(Node *current_node, Node *new_node);
void insert_node_in_tree(BinaryTree *tree, Node *new_node);
void print_student(Student student_info);
void print_node(const Node *node);
void print_binary_tree(const BinaryTree *tree);
void svd_traversal(const BinaryTree *tree);
void vsd_traversal(const BinaryTree *tree);
void sdv_traversal(const BinaryTree *tree);
Node **store_BST_in_array(const BinaryTree *tree, int nodes_count);
Node *convert_array_to_BST(Node **nodes, int start, int end);
Node *balance_tree(const BinaryTree *tree);
void mirror_tree(const BinaryTree *tree);
Node *search_node_by_key(BinaryTree *tree, int key);
void delete_node(Node *node);
void delete_tree(BinaryTree *tree);
int get_height(const Node *node);
void print_level(const Node *node, int level);
void bsf_traversal_recursive(const BinaryTree *tree);
void print_menu();
void switch_choice(int choice, BinaryTree *tree);

#endif
