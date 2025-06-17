#include <stdio.h>
#include "funcs.h"

int main() {
    IntArray arr;
    arr.array = NULL;
    arr.size = 0;

    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch_choice(choice, &arr);
    }
    return 0;
}
