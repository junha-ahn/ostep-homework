#include <stdio.h>

int main() {
    int *ptr = NULL; // Initialize a pointer to an integer with NULL
    printf("result : %d\n", *ptr); // Dereference a NULL pointer

    return 0;
    // result : Segmentation fault (core dumped)
}