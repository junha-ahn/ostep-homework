#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Allocate memory
    *ptr = 5; // Store a value in the allocated memory

    // No memory deallocation here

    printf("Value: %d\n", *ptr); // Access the allocated memory

    return 0;
}
