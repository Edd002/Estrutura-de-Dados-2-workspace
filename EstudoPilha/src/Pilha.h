/*
 * Pilha.h
 *
 *  Created on: 24 de set de 2018
 *      Author: n226804875
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct structItem {
	int chave;
} ITEM;

typedef struct structElemento {
	ITEM item;
	struct structElemento* proximoElementoPilha;
} ELEMENTO;

typedef ELEMENTO* PILHA;

PILHA* criaPilha();
ITEM olharPrimeiro(PILHA*);
void empilha(PILHA*, ITEM);
ITEM desempilha(PILHA*);
int tamanhoPilha(PILHA*);

#endif /* PILHA_H_ */
