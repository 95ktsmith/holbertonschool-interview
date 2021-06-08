#ifndef SORT_H
#define SORT_H
#include <stddef.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *left, size_t left_s, int *right, size_t right_s);


#endif /* SORT_H */
