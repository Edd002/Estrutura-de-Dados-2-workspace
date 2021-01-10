/*
 * lista.c
 *
 *  Created on: 7 de nov de 2020
 *      Author:
 */

#include "lista.h"

LISTA* criarListaNulo() {
	return NULL;
}

LISTA* inserirInicioLista(LISTA* lista, CLIENTE cliente) {
	LISTA* novo = (LISTA*) malloc (sizeof(LISTA));
	novo->cliente = cliente;
	novo->proximo = lista;

	return novo;
}

LISTA* inserirFimLista(LISTA* lista, CLIENTE cliente) {
	LISTA* novo = (LISTA*) malloc (sizeof(LISTA));
	novo->cliente = cliente;
	novo->proximo = NULL;

	if (lista == NULL) {
		return novo;
	} else {
		LISTA* tmp = lista;
		while (tmp->proximo != NULL)
			tmp = tmp->proximo;
		tmp->proximo = novo;
		return lista;
	}
}

LISTA* excluirElementoLista(LISTA* lista, int numeroCliente) {
	LISTA* tmp = lista;
	LISTA* anterior = NULL;

	while (tmp != NULL) {
		if (tmp->cliente.numeroCliente == numeroCliente){
			if (anterior == NULL)
				lista = lista->proximo;
			else
				anterior->proximo = tmp->proximo;

			free(tmp);
			break;
		} else {
			anterior = tmp;
			tmp = tmp->proximo;
		}
	}
	if (tmp == NULL)
		printf("\nRegistro de número %i não localizado.", numeroCliente);

	return lista;
}

LISTA* buscarElementoLista(LISTA* lista, int numeroCliente) {
	LISTA* atual = lista;

	while (atual != NULL) {
		if (atual->cliente.numeroCliente == numeroCliente)
			return atual;
		atual = atual->proximo;
	}

	return NULL;
}

void imprimir(LISTA* lista) {
	if (lista != NULL) {
		printf("\n%p - %i - %p", lista, lista->cliente.numeroBox, lista->proximo);
		imprimir(lista->proximo);
	}
}
