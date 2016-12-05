#include <stdlib.h>
#include <string.h>
#include "../common/input.h"

int main(int argc, int *argv[])
{
	if(argc == 2)
	{
		//Entero* e = init_entero(strlen(argv[1]),argv[1]);
		Input* input = create_input(argv[1]);
		print_input(input);
		printf("ahora ordenare con mergesort\n");
		input->L = mergesort(input->L,input->cantidad);
		print_input(input);
		destroy_input(input);
	}else{
		Input* input = create_input(argv[1]);
		destroy_input(input);
	}
}
