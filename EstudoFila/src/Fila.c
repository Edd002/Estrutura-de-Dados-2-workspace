/*
 * Fila.c
 *
 *  Created on: 25 de set de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

FILA* criaFila() {
	FILA* fila = (FILA*) malloc(sizeof(FILA));

	if (fila != NULL) {
		fila->elementoInicio = NULL;
		fila->elementoFim = NULL;
	}

	return fila;
}

void enfileira(FILA* fila, ITEM item) {
	if (fila == NULL)
		return;

	ELEMENTO* elemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	elemento->item = item;
	elemento->proximoElementoFila = NULL;

	if (fila->elementoFim == NULL)
		fila->elementoInicio = elemento;
	else
		fila->elementoFim->proximoElementoFila = fila->elementoFim;
	fila->elementoFim = elemento;
}

void desenfileira(FILA* fila, ITEM* item) {
	if (fila == NULL)
		return;

	ELEMENTO* elemento = fila->elementoInicio;
	*item = elemento->item;
	fila->elementoInicio = fila->elementoInicio->proximoElementoFila;

	if (fila->elementoInicio == NULL)
		fila->elementoFim = NULL;

	free(elemento);
}

int tamanhoFila(FILA* fila) {
	ELEMENTO* elemento = fila->elementoInicio;
	int contador = 0;

	while (elemento != NULL) {
		elemento = elemento->proximoElementoFila;
		contador++;
	}

	return contador;
}
