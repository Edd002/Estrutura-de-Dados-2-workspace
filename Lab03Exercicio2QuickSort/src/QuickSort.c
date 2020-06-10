/*
 * QuickSort.c
 *
 *  Created on: 13 de set de 2018
 *      Author: n226804875
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "QuickSort.h"

void selecao(ITEM *a, int tam) {
	INDICE i,j,min;
	ITEM x;

	for(i=0; i < tam-1; i++){
		min = i;
		for(j=i; j < tam; j++)
			if(a[j].chave < a[min].chave) min = j;
		x = a[min]; a[min] = a[i]; a[i] = x;
	}
}

ITEM calcularPivo(INDICE i, INDICE j, ITEM *a) {
	return a[(i + j) / 2];
}


void particao(INDICE esq, INDICE dir, INDICE *i, INDICE *j, ITEM *a) {
	ITEM x,w;

	*i = esq; *j = dir;
	x = calcularPivo(*i, *j, a); /*pivo*/
	do{
		while(x.chave > a[*i].chave) (*i)++;
		while(x.chave < a[*j].chave) (*j)--;
		if(*i <= *j) {
			w = a[*i]; a[*i] = a[*j]; a[*j] = w;
			(*i)++; (*j)--;
		}
	} while(*i <= *j);
}

void ordena(INDICE esq, INDICE dir, ITEM *a) {
	INDICE i,j;

	particao(esq,dir,&i,&j,a);
	if(esq < j) ordena(esq,j,a);
	if(i < dir) ordena(i,dir,a);
}

void quicksort(ITEM *a, int tam) {
	if (tam < 20)
		selecao(a, tam);
	else
		ordena(0,tam-1,a);
}

double rand0a1() {
	double res = (double)rand() / INT_MAX;
	if(res > 1.0) res = 1.0;
	return res;
}

void permuta(VETOR a, int tam) {
	ITEM b;
	int i,j;

	for(i=tam-1; i>=0; i--){
		j = (i * rand0a1()) + 1;
		b = a[i];
		a[i] = a[j];
		a[j] = b;
	}
}

void imprime(VETOR a, int tam) {
	int i;

	for(i=0; i<tam; i++) printf("%ld ", a[i].chave);
	printf("\n");
}
