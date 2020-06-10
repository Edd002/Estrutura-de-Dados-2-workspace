/*
 * Line.c
 *
 *  Created on: 29 de ago de 2018
 *      Author: n226804875
 */

#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

FILA* cria() {
	FILA* fila = (FILA*) malloc(sizeof(FILA));

	if (fila  != NULL) {
		fila->final = NULL;
		fila->elementoInicio = NULL;
	}

	return fila;
}

int vazia(FILA* fila) {
	if (fila == NULL)
		return 1;

	if (fila->elementoInicio == NULL)
		return 1;

	return 0;
}

int enfileira(FILA* fila, ITEM item) {
	if (fila == NULL)
		return 0;

	ELEMENTO_FILA* elementoFila = (ELEMENTO_FILA*) malloc(sizeof(ELEMENTO_FILA));
	if (elementoFila == NULL)
		return 0;

	elementoFila->item = item;
	elementoFila->proximoElementoFila = NULL;

	if (fila->final == NULL)
		fila->elementoInicio = elementoFila;
	else
		fila->final->proximoElementoFila = elementoFila;
	fila->final = elementoFila;

	return 1;
}

int desenfileira(FILA* fila, ITEM* item) {
	if (fila == NULL)
		return 0;

	if (fila->elementoInicio == NULL)
		return 0;

	ELEMENTO_FILA* elementoFila = fila->elementoInicio;
	*item = elementoFila->item;
	fila->elementoInicio = fila->elementoInicio->proximoElementoFila;

	if (fila->elementoInicio == NULL)
		fila->final = NULL;

	free(elementoFila);
	return 1;
}
