#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[100];

    int *ptr = &data[50];

    free(ptr);

    printf("Value at invalid pointer: %d\n", *ptr);

    return 0;
}
