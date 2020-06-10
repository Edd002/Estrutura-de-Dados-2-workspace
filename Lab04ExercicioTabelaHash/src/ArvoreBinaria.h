/*
 * ArvoreBinaria.h
 *
 *  Created on: 22 de out de 2018
 *      Author: n226804875
 */

#ifndef ARVOREBINARIA_H_
#define ARVOREBINARIA_H_

#include "TabelaHash.h"

typedef struct structNo {
	ITEM item;
	struct structNo* esquerda;
	struct structNo* direita;
} NO;

typedef NO* ARVORE;

void criaArvore(ARVORE*);
int pesquisaArvore(ARVORE*, ITEM*);
int insereArvore(ARVORE*, ITEM);
int retiraArvore(ARVORE*, ITEM);
void antecessor (ARVORE, ARVORE*);
void percorreIn(ARVORE);
void percorrePre(ARVORE);
void percorrePos(ARVORE);

#endif /* ARVOREBINARIA_H_ */
