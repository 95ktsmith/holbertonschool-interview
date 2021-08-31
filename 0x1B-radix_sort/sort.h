#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void recursive_radix(int *array, int *buffer, size_t size, int place);

#endif /* SORT_H */
