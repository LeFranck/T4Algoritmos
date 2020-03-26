#include <stdlib.h>
#include <string.h>
#include "../common/input.h"
#include "../common/mergesort.h"
#include "../common/mediana.h"

int main(int argc, int *argv[])
{
	if(argc == 2)
	{
		Input* input = create_input(argv[1]);

		//print_input(input);
		//printf("ahora ordenare con mergesort\n");
		//input->L = mergesort(input->L,input->cantidad);
		//print_input(input);
		
		int c = input->cantidad;
		double c2 = (double)c;
    int contador = 1;
		int** resultado = calcular_mediana(input->L,c2);
    while(resultado[0] == 0)
    {
      int** resultado = calcular_mediana(input->L,c2);
      contador = contador + 1;
    }
		printf("La mediana es %d\n", resultado[1]);
    printf("El algoritmo tuvo que correr %d veces\n",contador);
		destroy_input(input);
	}else{
		Input* input = create_input(argv[1]);
		destroy_input(input);
	}
}
