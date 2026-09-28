/* array.h
 * Defines a custom array structure containing size and a pointer to data.
 */

#ifndef ARRAY_H
#define ARRAY_H

struct _my_array {
    int size;       /* number of elements in the array */
    double *data;   /* dynamically allocated array of doubles */
};

typedef struct _my_array Array;

/* Function prototypes */
void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

#endif

