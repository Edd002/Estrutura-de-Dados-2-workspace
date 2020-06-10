/*
 * Line.h
 *
 *  Created on: 29 de ago de 2018
 *      Author: n226804875
 */

#ifndef FILA_H_
#define FILA_H_

typedef struct structItem {
	int chave;
} ITEM;

typedef struct structElementoFila {
	ITEM item;
	struct structElementoFila* proximoElementoFila;
} ELEMENTO_FILA;

typedef struct structFila {
	ELEMENTO_FILA* elementoInicio;
	ELEMENTO_FILA* final;
} FILA;

FILA* fila;

FILA* cria();
int vazia(FILA*);
int enfileira(FILA*, ITEM);
int desenfileira(FILA*, ITEM*);

#endif /* FILA_H_ */
