/*
 ============================================================================
 Name        : ExercicioFila.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(void) {
	setbuf(stdout, NULL);

	FILA* fila = cria();
	ITEM item;
	item.chave = 123;

	printf("Vazia? %i", vazia(fila));

	printf("\nEnfileirando...");
	enfileira(fila, item);

	printf("\nVazia? %i", vazia(fila));

	ITEM itemBuscado;
	printf("\nDesenfileirando...");
	desenfileira(fila, &itemBuscado);

	printf("\nVazia? %i", vazia(fila));

	printf("\n\nChave do item desenfileirado: %i", itemBuscado.chave);

	return EXIT_SUCCESS;
}
