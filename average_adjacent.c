/* average_adjacent.c
 * Creates a new array containing averages of adjacent pairs.
 * If the original size is odd, the last element is ignored.
 */

#include <stdlib.h>
#include "array.h"

Array *average_adjacent(Array *a) {
    int new_size = a->size / 2;  /* integer division handles odd sizes */

    Array *new_arr = malloc(sizeof(Array));
    if (!new_arr) return NULL;

    new_arr->size = new_size;
    new_arr->data = malloc(sizeof(double) * new_size);
    if (!new_arr->data) {
        free(new_arr);
        return NULL;
    }

    for (int i = 0; i < new_size; i++) {
        double x = a->data[2 * i];
        double y = a->data[2 * i + 1];
        new_arr->data[i] = (x + y) / 2.0;
    }

    return new_arr;
}

