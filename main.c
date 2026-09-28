/* main.c
 * Demonstrates dynamic allocation of a custom array structure,
 * shifting values, averaging adjacent values, and freeing memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[]) {

    /* Step 1: Validate command line arguments */
    if (argc != 2) {
        printf("Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: array size must be a positive integer.\n");
        return 1;
    }

    /* Step 2: Allocate the structure */
    Array *a = malloc(sizeof(Array));
    if (!a) {
        printf("Memory allocation failed for structure.\n");
        return 1;
    }

    a->size = n;

    /* Allocate the internal array */
    a->data = malloc(sizeof(double) * n);
    if (!a->data) {
        printf("Memory allocation failed for array data.\n");
        free(a);
        return 1;
    }

    /* Fill array with values (example: index * 1.5) */
    for (int i = 0; i < n; i++) {
        a->data[i] = i * 1.5;
    }

    /* Step 3: Call output_array */
    printf("Original array:\n");
    output_array(a);

    /* Step 4: Shift array */
    shift_array(a);

    printf("\nArray after shifting left:\n");
    output_array(a);

    /* Step 5: Average adjacent elements */
    Array *avg = average_adjacent(a);

    printf("\nAveraged adjacent array:\n");
    output_array(avg);

    /* Step 6: Free all allocated memory */
    free(a->data);
    free(a);

    free(avg->data);
    free(avg);

    return 0;
}

