#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

int** mergesort(int** L, int n)
{
	if(n>1)
	{
		int n1 = n/2 + n%2;
		int n2 = n/2 ;
		int** l1 = malloc(sizeof(int*)*n1);
		int** l2 = malloc(sizeof(int*)*n2);
		int i = 0;
		for(i = 0; i < n1; i++)
		{
			l1[i] = L[i];
		}

		for(i = 0; i < n2; i++)
		{
			l2[i] = L[i+n1];
		}
		l1 = mergesort(l1,n1);
		l2 = mergesort(l2,n2);
		int** l3 = merge(l1,l2,n1,n2);
		free(l1);
		free(l2);
		return l3;
	}else{
		return L;
	}
}

int** merge(int** l1, int** l2, int n1, int n2)
{

	int** l3 = malloc(sizeof(int*)*(n1+n2));
	int k = 0;
	int j = 0;
	int i = 0;

	while(k < n1 + n2)
	{
		if(i == n1)
		{
			l3[k] = l2[j];
			j++;
		}else if(j == n2)
		{
			l3[k] = l1[i];
			i++;
		}else{
			if(l1[i] < l2[j])
			{
				l3[k] = l1[i];
				i++;
			}else{
				l3[k] = l2[j];
				j++;
			}
		}
		k++;
	}
	return l3;
}

void print_l(int** l, int n)
{
	int k = 0;
	printf("[");
	for(k = 0; k < n-1; k++)
	{
		printf("%d,",l[k]);
	}
	printf("%d]",l[n-1]);
}
