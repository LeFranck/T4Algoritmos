#ifndef T3_LIB_INPUT_H
#define T3_LIB_INPUT_H

#include <stdio.h>
#include <stdlib.h>

struct input
{
	int** L;
	int* cantidad;
	int* k;
	int* n_minimo;
	int* largo_R;
};

typedef struct input Input;

Input* create_input(char* filename);

void fill_input(Input* i,char* filename);

void set_cantidad_de_elementos(Input* i, char* filename);

void print_input(Input* i);

void destroy_input(Input* i);

#endif
