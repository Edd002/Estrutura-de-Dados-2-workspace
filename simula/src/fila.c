/*
 * fila.c
 *
 *  Created on: 5 de nov de 2020
 *      Author:
 */

#include "fila.h"

FILA* criaFila() {
	FILA* fila = (FILA*) malloc(sizeof(FILA));

	if (fila != NULL) {
		fila->elementoInicio = NULL;
		fila->elementoFim = NULL;
	}
	fila->tamanho = 0;

	return fila;
}

void enfileira(FILA* fila, CLIENTE cliente) {
	if (fila == NULL)
		return;

	ELEMENTO* elemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	elemento->cliente = cliente;
	elemento->proximoElementoFila = NULL;

	if (fila->elementoFim == NULL)
		fila->elementoInicio = elemento;
	else
		fila->elementoFim->proximoElementoFila = fila->elementoFim;
	fila->elementoFim = elemento;
	fila->tamanho++;
}

void desenfileira(FILA* fila, CLIENTE* cliente) {
	if (fila == NULL)
		return;

	ELEMENTO* elemento = fila->elementoInicio;
	*cliente = elemento->cliente;
	fila->elementoInicio = fila->elementoInicio->proximoElementoFila;

	if (fila->elementoInicio == NULL)
		fila->elementoFim = NULL;
	fila->tamanho--;

	free(elemento);
}
