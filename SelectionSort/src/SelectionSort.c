/*
 ============================================================================
 Name        : SelectionSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int*, int);
void showArray(int*, int);

int main(void) {
	setbuf(stdout, NULL);

	int array[] = {9, 8, 7, 6, 5, 1, 2, 3, 4, 0};
	int tam = sizeof(array) / sizeof(int);
	selectionSort(array, tam);
	showArray(array, tam);

	return EXIT_SUCCESS;
}

void selectionSort(int* array, int tam) {
	int i, j, min, aux;
	for (i = 0; i < (tam - 1); i++) {
		min = i;
		for (j = (i+1); j < tam; j++) {
			if(array[j] < array[min])
				min = j;
		}
		if (array[i] != array[min]) {
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
		}
	}
}

void showArray(int* array, int tam) {
	printf("ARRAY ORDENADO\n");
	int i;
	for (i = 0; i < tam; i++)
		printf("%i ", array[i]);
}
