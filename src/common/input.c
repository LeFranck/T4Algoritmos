#include "input.h"
#include <string.h>

Input* create_input(char* filename)
{
	Input* i = malloc(sizeof(Input));
	set_cantidad_de_elementos(i,filename);
	fill_input(i,filename);
	return i;
}

void fill_input(Input* i, char* filename)
{
	FILE* fr = fopen(filename,"r");
	int j = 0;
	char Basura[128];
	int* param;
	for(j = 0; j < i->cantidad; j++)
	{
		fscanf(fr,"%d %s",&param,Basura);
		i->L[j] = param;
	}
	fscanf(fr,"%d",&param);
	i->k = param;
	fclose(fr);
}

void set_cantidad_de_elementos(Input* i, char* filename)
{
	FILE* fr = fopen(filename, "r");
	char c = 'c';
	int k = 0;
	if(fr == NULL)
	{
		printf("Archivo no existente\n");
	}else{
		while(c != EOF)
		{
			c = fgetc(fr);
			if(c == ',')
			{
				k = k + 1;
			}
		}
	}
	fclose(fr);
	i->cantidad = (k + 1);
	i->L = malloc(sizeof(int*)*i->cantidad);
}

void print_input(Input* i)
{
	printf("El input tiene %d elementos\n",i->cantidad);
	int j = 0;
	printf("[ ");
	for(j = 0; j < i->cantidad-1; j++)
	{
		printf("%d,",i->L[j]);
	}
	printf(" ]\n");
}

void destroy_input(Input* i)
{
	free(i->L);
	free(i);
}
