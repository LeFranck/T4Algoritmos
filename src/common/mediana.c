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
	int** retorno = malloc(sizeof(int*)*2);
	int n = round(n1);
	if(n1 < 145.0)
	{
		int** l1 = mergesort(L,n);
		retorno[0] = 1;
		int uuu = round(ceil(n1/2));
		printf("%d\n", uuu);
		retorno[1] = l1[uuu-1];
		//retorno[1] = l1[(n/2)+n%2];
		return retorno;
	}else{
		int largo = get_largo_R(n1);
		int d_index = get_d_index(n1);
		int u_index = get_u_index(n1);
		int** R = malloc(sizeof(int*)*largo);
		int i = 0;
		printf("largo: %d \t d_index %d\t u:index  %d\n", largo, d_index, u_index );
		for(i = 0; i < largo; i++)
		{
			int j = rand() % n;
			R[i] = L[j];
			printf("|%d|",j);
		}
		int** r2 = mergesort(R,largo);
		R = r2;
		free(r2);
		int d = R[d_index];
		int u = R[u_index];
		int md = 0;
		int mu = 0;
		int largo_s = 0;

		for(i = 0; i < n; i++)
		{
			if(d <= L[i] && L[i] <= u)
			{
				largo_s++;
			}else if(L[i] < d){
				md++;
			}else{
				mu++;
			}
		}

		if( (md >= n/2 + n%2) || (mu >= n/2 + n%2) || (largo_s >= 4*largo) )
		{
			if(md >= n/2 + n%2)
			{
				printf("Y1\n");
			}

			if(mu >= n/2 + n%2)
			{
				printf("Y2\n");
			}

			if(largo_s >= 4*largo)
			{
				printf("%d > %d S\n",largo_s, 4*largo);
			}

			retorno[0] = 0;
			retorno[1] = -1;
			return retorno;
		}else{
			int** S = malloc(sizeof(int*)*largo_s);
			int k = 0;
			for(i = 0; i < n; i++)
			{
				if(d <= L[i] && L[i] <= u)
				{
					S[k] = L[i];
					k++;
				}
			}
			int** s2 = mergesort(S,largo_s);
			retorno[0] = 1;
			int index_final = n/2 + n%2 - md;
			retorno[1] = S[index_final];
			return retorno;
		}
	}
}


int get_d_index(double n)
{
	double r1 =  pow(n,0.6394)/2.0 - pow(n,0.5);
	int r = round(r1);
	return r;
}

int get_u_index(double n)
{
	double u_index1 = pow(n,0.6394)/2.0 + pow(n,0.5);
	int r = round(ceil(u_index1));
	return r;
}

int get_largo_R(double n)
{
	int r =  round(ceil(pow(n,0.6394)));
	return r;
}
