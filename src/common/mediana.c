#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mergesort.h"
#include "mediana.h"

int** calcular_mediana(int** L, double n1)
{
	//el primer int dira si hay resultado
	//y el segundo nos dara dicho resultado
  int debug = 0;
  time_t t;
  srand((unsigned) time(&t));
	int** retorno = malloc(sizeof(int*)*2);
	int n = round(n1);
	if(n1 < 2001.0)
	{
		int** l1 = mergesort(L,n);
		retorno[0] = 1;
		int uuu = round(ceil(n1/2));
		retorno[1] = l1[uuu-1];
		return retorno;
	}else{
		int largo = get_largo_R(n1);
		int d_index = get_d_index(n1);
		int u_index = get_u_index(n1);
		int** R = malloc(sizeof(int*)*largo);
		int i = 0;
		if(debug){printf("largo: %d \t d_index %d\t u:index  %d\n", largo, d_index, u_index );}

		for(i = 0; i < largo; i++)
		{
			int j = rand() % n;
			R[i] = L[j];
		}
		
    int** r2 = mergesort(R,largo);
		R = r2;
		free(r2);
		if(debug)
    {
      print_l(R, largo);
      printf("\nLista ordenada ^^^^^\n");
    }
    int d = R[d_index];
		int u = R[u_index];
		int md = 0;
		int mu = 0;
		int largo_s = 0;

		for(i = 0; i < n; i++)
		{
      int aux = L[i];
			if((d <= aux) && (aux <= u)){
				largo_s++;
			}else if(aux < d){
				md++;
			}else if(aux > u){
        mu++;
			}else{
        if(debug){printf("WTF\n");}
      }
		}
    int cota = round(floor(pow(n,0.75)));
    if( (md >= n/2 + n%2) || (mu >= n/2 + n%2) || (largo_s >= 4*cota) )
		{
			if(md >= n/2 + n%2)
			{
				printf("Y1\n");
			}

			if(mu >= n/2 + n%2)
			{
				printf("Y2\n");
			}

			if(largo_s >= 4*cota)
			{
				printf("%d > %d S\n",largo_s , 4*cota);
			}

			retorno[0] = 0;
			retorno[1] = -1;
			return retorno;
		}else{
			int** S = malloc(sizeof(int*)*largo_s);
			int k = 0;
			for(i = 0; i < n; i++)
			{
        int aux2 = L[i];
				if((d <= aux2) && (aux2 <= u))
				{
					S[k] = aux2;
					k++;
				}
			}
			int** s2 = mergesort(S,largo_s);
      S = s2;
      free(s2);
      if(debug)
      {
        print_l(S, largo_s);
        printf("\nLista ordenada ^^^^^\n");
      }
      printf("Length of s %d\n", largo_s );
      printf("d and u: %d and %d \n", d, u );
			retorno[0] = 1;
			int index_final = n/2 + n%2 - md;
			retorno[1] = S[index_final];
			return retorno;
		}
	}
}


int get_d_index(double n)
{
	double d1 =  pow(n,0.75)/2.0 - pow(n,0.5);
	int d = round(floor(d1));
	return d;
}

int get_u_index(double n)
{
	double u_index1 = pow(n,0.75)/2.0 + pow(n,0.5);
	int u_index = round(ceil(u_index1));
	return u_index;
}

int get_largo_R(double n)
{
	int r =  round(ceil(pow(n,0.75)));
	return r;
}
