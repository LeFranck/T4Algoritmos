#ifndef T4_LIB_MERGESORT_H
#define T4_LIB_MERGESORT_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>

int** mergesort(int** L, int n);

int** merge(int** l1, int** l2, int n1, int n2);

void print_l(int** l, int n);

#endif
