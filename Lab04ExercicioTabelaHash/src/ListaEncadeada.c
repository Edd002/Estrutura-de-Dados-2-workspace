/*
 * ListaEncadeada.c
 *
 *  Created on: 22 de out de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ListaEncadeada.h"

void criaLista(LISTA* lista) {
	lista->primeiraCelula = (CELULA*) malloc(sizeof(CELULA));
	lista->ultimaCelula = lista->primeiraCelula;
	lista->primeiraCelula->proximaCelula = NULL;
}

int verificaVaziaLista(LISTA lista) {
	return (lista.primeiraCelula == lista.ultimaCelula);
}

int insereLista(LISTA* lista, ITEM item) {
	lista->ultimaCelula->proximaCelula = (CELULA*) malloc(sizeof(CELULA));
	lista->ultimaCelula = lista->ultimaCelula->proximaCelula;
	lista->ultimaCelula->item = item;
	lista->ultimaCelula->proximaCelula = NULL;
	return 0;
}

int retiraLista(LISTA* lista, CHAVE chave, ITEM* item) {
	CELULA* celulaAux1;
	CELULA* celulaAux2;

	celulaAux1 = lista->primeiraCelula;
	while (celulaAux1->proximaCelula != NULL) {
		if (strncmp(celulaAux1->proximaCelula->item.nome, chave, TAM_CHAVE) == 0) {
			celulaAux2 = celulaAux1->proximaCelula;
			*item = celulaAux2->item;
			celulaAux1->proximaCelula = celulaAux2->proximaCelula;

			if (celulaAux1->proximaCelula == NULL)
				lista->ultimaCelula = celulaAux1;

			free(celulaAux2);
			return 0;
		}
		celulaAux1 = celulaAux1->proximaCelula;
	}

	return -1;
}

void imprime(LISTA lista) {
	CELULA* aux;

	aux = lista.primeiraCelula->proximaCelula;
	while (aux != NULL) {
		printf("%s\n", aux->item.nome);
		aux = aux->proximaCelula;
	}
}
