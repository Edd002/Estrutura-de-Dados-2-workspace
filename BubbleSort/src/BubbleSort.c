/*
 ============================================================================
 Name        : BubbleSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

void bubbleSort(int*, int);
void showArray(int*, int);

int main(void) {
	setbuf(stdout, NULL);

	int array[] = {9, 8, 7, 6, 5, 1, 2, 3, 4, 0};
	int tam = sizeof(array) / sizeof(int);
	bubbleSort(array, tam);
	showArray(array, tam);

	return EXIT_SUCCESS;
}

void bubbleSort(int* array, int tam) {
	int i, j, temp;
	for (i = 0; i < tam - 1; i++){
		for (j = (i+1); j < tam; j++){
			if (array[j] < array[i]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void showArray(int* array, int tam) {
	printf("ARRAY ORDENADO\n");
	int i;
	for (i = 0; i < tam; i++)
		printf("%i ", array[i]);
}
