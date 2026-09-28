/* shift_array.c
 * Shifts all elements left by one position.
 * The first element becomes the last.
 */

#include "array.h"

void shift_array(Array *a) {
    if (a->size <= 1) return;

    double first = a->data[0];

    for (int i = 0; i < a->size - 1; i++) {
        a->data[i] = a->data[i + 1];
    }

    a->data[a->size - 1] = first;
}

