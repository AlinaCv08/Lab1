#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void print_menu() {
    printf("\n1) Calculate Fibonacci number\n");
    printf("2) Analyze calculation time\n");
    printf("0) Exit\n");
}

int main() {
    int choice;
    int n;
    BigInt fib_result;

    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Fibonacci position (50-1000): ");
                scanf("%d", &n);
                if (n < 50 || n > 1000) {
                    printf("Position out of range! Must be between 50 and 1000.\n");
                    break;
                }
                fibonacci(n, &fib_result);
                printf("Fibonacci(%d) = ", n);
                bigint_print(&fib_result);
                printf("\n");
                break;
            case 2:
                analyze_fibonacci();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
