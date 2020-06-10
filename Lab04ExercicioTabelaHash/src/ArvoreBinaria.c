/*
 * ArvoreBinaria.c
 *
 *  Created on: 22 de out de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ArvoreBinaria.h"

void criaArvore(ARVORE* arvore) {
	*arvore = NULL;
}

int pesquisaArvore(ARVORE* arvore, ITEM* item) {
	if (*arvore == NULL)
		return -1;

	if (strncmp(item->nome, (*arvore)->item.nome, TAM_CHAVE) < 0)
		return pesquisaArvore(&(*arvore)->esquerda, item);
	if (strncmp(item->nome, (*arvore)->item.nome, TAM_CHAVE) > 0)
		return pesquisaArvore(&(*arvore)->direita, item);

	*item = (*arvore)->item;

	return 0;
}

int insereArvore(ARVORE* arvore, ITEM item) {
	if (*arvore == NULL) {
		*arvore = (ARVORE) malloc(sizeof(NO));
		(*arvore)->item = item;
		(*arvore)->esquerda = NULL;
		(*arvore)->direita = NULL;
		return 0;
	}

	if (strncmp(item.nome, (*arvore)->item.nome, TAM_CHAVE) < 0)
		return insereArvore(&(*arvore)->esquerda, item);
	if (strncmp(item.nome, (*arvore)->item.nome, TAM_CHAVE) > 0)
		return insereArvore(&(*arvore)->direita, item);

	return -1;
}

int retiraArvore(ARVORE* arvore, ITEM item) {
	ARVORE aux;

	if (*arvore == NULL)
		return -1;

	if (strncmp(item.nome, (*arvore)->item.nome, TAM_CHAVE) < 0)
		return retiraArvore(&(*arvore)->esquerda, item);
	if (strncmp(item.nome, (*arvore)->item.nome, TAM_CHAVE) > 0)
		return retiraArvore(&(*arvore)->direita, item);

	if ((*arvore)->direita == NULL) {
		aux = *arvore;
		*arvore = (*arvore)->esquerda;
		free(aux);
		return 0;
	}

	if ((*arvore)->esquerda == NULL) {
		aux = *arvore;
		*arvore = (*arvore)->direita;
		free(aux);
		return 0;
	}

	antecessor(*arvore, &(*arvore)->esquerda);
	return 0;
}

void antecessor (ARVORE arvore, ARVORE* pArvore) {
	if ((*pArvore)->direita != NULL) {
		antecessor(arvore, &(*pArvore)->direita);
	} else {
		arvore->item = (*pArvore)->item;
		arvore = *pArvore;
		*pArvore = (*pArvore)->esquerda;
		free(arvore);
	}
}

void percorreIn(ARVORE arvore) {
	if (arvore != NULL) {
		percorreIn(arvore->esquerda);
		printf("%s", arvore->item.nome);
		percorreIn(arvore->direita);
	}
}

void percorrePre(ARVORE arvore) {
	if (arvore != NULL) {
		printf("%s\n", arvore->item.nome);
		percorrePre(arvore->esquerda);
		percorrePre(arvore->direita);
	}
}

void percorrePos(ARVORE arvore) {
	if (arvore != NULL) {
		percorrePos(arvore->esquerda);
		percorrePos(arvore->direita);
		printf("%s\n", arvore->item.nome);
	}
}
