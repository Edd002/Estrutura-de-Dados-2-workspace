/*
 * lista.h
 *
 *  Created on: 7 de nov de 2020
 *      Author:
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct structLista LISTA;

struct structLista {
	CLIENTE cliente;
	LISTA* anterior;
	LISTA* proximo;
};

LISTA* criarListaNulo();
LISTA* inserirInicioLista(LISTA*, CLIENTE);
LISTA* inserirFimLista(LISTA*, CLIENTE);
LISTA* excluirElementoLista(LISTA*, int);
LISTA* buscarElementoLista(LISTA*, int);
void imprimir(LISTA*);

#endif /* LISTA_H_ */
