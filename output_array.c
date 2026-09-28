/* output_array.c
 * Prints all elements of the array.
 */

#include <stdio.h>
#include "array.h"

void output_array(Array *a) {
    for (int i = 0; i < a->size; i++) {
        printf("%.2f ", a->data[i]);
    }
    printf("\n");
}

