#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <memory_size_in_MB>\n", argv[0]);
        return 1;
    }

    int memory_size_MB = atoi(argv[1]);
    long long num_elements = (memory_size_MB * 1024 * 1024) / sizeof(int);

    printf("Allocating approximately %d MB of memory...\n", memory_size_MB);

    int *data = (int *)malloc(num_elements * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocated successfully.\n");

    // Filling the array with values
    for (long long i = 0; i < num_elements; i++) {
        data[i] = i;
    }

    // Infinite loop to keep printing array elements
    while (1) {
        // for (long long i = 0; i < num_elements; i++) {
        //     printf("%d ", data[i]);
        // }
        // printf("\n");
    }

    free(data);

    return 0;
}
