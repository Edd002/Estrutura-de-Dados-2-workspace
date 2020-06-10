/*
 * Pilha.c
 *
 *  Created on: 24 de set de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

PILHA* criaPilha() {
	PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
	if (pilha != NULL)
		*pilha = NULL;
	return pilha;
}

ITEM olharPrimeiro(PILHA* pilha) {
	return (*pilha)->item;
}

void empilha(PILHA* pilha, ITEM item) {
	ELEMENTO* novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));

	novoElemento->item = item;
	novoElemento->proximoElementoPilha = (*pilha);
	*pilha = novoElemento;
}

ITEM desempilha(PILHA* pilha) {
	ELEMENTO* elemento = (*pilha);
	*pilha = (*pilha)->proximoElementoPilha;
	free(elemento);

	return elemento->item;
}

int tamanhoPilha(PILHA* pilha) {
	int contador = 0;
	ELEMENTO* elemento = *pilha ;

	while (elemento != NULL) {
		contador++;
		elemento = elemento->proximoElementoPilha;
	}

	return contador;
}
