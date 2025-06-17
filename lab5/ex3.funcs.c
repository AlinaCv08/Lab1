#include <stdio.h>
#include <string.h>
#include <time.h>
#include "funcs.h"


void bigint_init(BigInt *num, const char *str) {
    int len = strlen(str);
    num->length = len;
    for (int i = 0; i < len; i++) {
        num->digits[i] = str[len - 1 - i] - '0'; 
    }
}
void bigint_print(const BigInt *num) {
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
}

void bigint_add(const BigInt *a, const BigInt *b, BigInt *result) {
    int carry = 0;
    int i;
    int max_len = (a->length > b->length) ? a->length : b->length;
    for (i = 0; i < max_len || carry; i++) {
        int digit_sum = carry;
        if (i < a->length) digit_sum += a->digits[i];
        if (i < b->length) digit_sum += b->digits[i];
        result->digits[i] = digit_sum % 10;
        carry = digit_sum / 10;
    }
    result->length = i;
}

void fibonacci(int n, BigInt *result) {
    if (n == 0) {
        bigint_init(result, "0");
        return;
    }
    if (n == 1) {
        bigint_init(result, "1");
        return;
    }
    BigInt a, b, c;
    bigint_init(&a, "0");
    bigint_init(&b, "1");

    for (int i = 2; i <= n; i++) {
        bigint_add(&a, &b, &c);
        a = b;
        b = c;
    }
    *result = b;
}

void analyze_fibonacci() {
    int test_values[] = {50, 100, 1000};
    int len = sizeof(test_values) / sizeof(test_values[0]);
    BigInt result;

    printf("\nN\tTime (ms)\n");
    for (int i = 0; i < len; i++) {
        clock_t start = clock();
        fibonacci(test_values[i], &result);
        clock_t end = clock();

        double time_ms = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d\t%.3f\n", test_values[i], time_ms);
    }
}
