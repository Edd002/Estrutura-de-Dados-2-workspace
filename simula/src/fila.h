/*
 * fila.h
 *
 *  Created on: 5 de nov de 2020
 *      Author:
 */

#ifndef FILA_H_
#define FILA_H_

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct structElemento {
	CLIENTE cliente;
	struct structElemento* proximoElementoFila;
} ELEMENTO;

typedef struct structFila {
	ELEMENTO* elementoInicio;
	ELEMENTO* elementoFim;
	int tamanho;
} FILA;

FILA* criaFila();
void enfileira(FILA*, CLIENTE);
void desenfileira(FILA*, CLIENTE*);

#endif /* FILA_H_ */
