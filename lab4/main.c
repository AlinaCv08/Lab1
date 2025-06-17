#include "funcs.h"
#include <stdio.h>

int main() {
    BinaryTree* tree = create_binary_tree();
    int choice;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch_choice(choice, tree);
    }
}
