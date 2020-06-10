/*
 * Library.c
 *
 *  Created on: 4 de dez de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

ARVORE cria() {
	return NULL;
}

ARVORE insere(ARVORE raiz, ARVORE no) {
	if (raiz == NULL)
		return no;

	if(no->chave < raiz->chave)
		raiz->esquerda = insere(raiz->esquerda, no);
	else
		raiz->direita = insere(raiz->direita, no);

	return raiz;
}

ARVORE criaNovoNo(CHAVE chave) {
	ARVORE novoNo = (ARVORE) malloc(sizeof(NO));
	novoNo->esquerda = NULL;
	novoNo->direita = NULL;
	novoNo->chave = chave;
	return novoNo;
}
