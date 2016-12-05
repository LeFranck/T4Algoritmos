#include <stdlib.h>
#include <string.h>
#include "../common/input.h"

int main(int argc, int *argv[])
{
	if(argc == 3)
	{
		//Entero* e = init_entero(strlen(argv[1]),argv[1]);
		int k = atoi(argv[2]);
	}else{
		Input* input = create_input(argv[1]);
		destroy_input(input);
	}
}
