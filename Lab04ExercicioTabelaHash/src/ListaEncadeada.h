/*
 * ListaEncadeada.h
 *
 *  Created on: 22 de out de 2018
 *      Author: n226804875
 */

#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include "TabelaHash.h"

typedef struct structCelula {
	ITEM item;
	struct structCelula* proximaCelula;
} CELULA;

typedef struct structLista {
	CELULA* primeiraCelula;
	CELULA* ultimaCelula;
} LISTA;

void criaLista(LISTA*);
int verificaVaziaLista(LISTA);
int insereLista(LISTA*, ITEM);
int retiraLista(LISTA*, CHAVE, ITEM*);
void imprime(LISTA);

#endif /* LISTAENCADEADA_H_ */
