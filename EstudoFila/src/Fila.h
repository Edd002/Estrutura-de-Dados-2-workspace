/*
 * Fila.h
 *
 *  Created on: 25 de set de 2018
 *      Author: n226804875
 */

#ifndef FILA_H_
#define FILA_H_

typedef struct structItem {
	int chave;
} ITEM;

typedef struct structElemento {
	ITEM item;
	struct structElemento* proximoElementoFila;
} ELEMENTO;

typedef struct structFila {
	ELEMENTO* elementoInicio;
	ELEMENTO* elementoFim;
} FILA;

FILA* criaFila();
void enfileira(FILA*, ITEM);
void desenfileira(FILA*, ITEM*);
int tamanhoFila(FILA*);

#endif /* FILA_H_ */
