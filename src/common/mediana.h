#ifndef T4_LIB_MEDIANA_H
#define T4_LIB_MEDIANA_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
#include <math.h>

int** calcular_mediana(int** L, double n);

int get_d_index(double n);

int get_u_index(double n);

int get_largo_R(double n);

#endif
