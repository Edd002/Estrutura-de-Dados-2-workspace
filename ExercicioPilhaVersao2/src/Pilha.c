/*
 * Pilha.c
 *
 *  Created on: 5 de set de 2018
 *      Author: n226804875
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

PILHA_OPERANDOS* criarPilhaOperandos() {
	PILHA_OPERANDOS* pilhaOperandos = (PILHA_OPERANDOS*) malloc(sizeof(PILHA_OPERANDOS));
	if (pilhaOperandos != NULL)
		*pilhaOperandos = NULL;
	return pilhaOperandos;
}

PILHA_OPERADORES* criarPilhaOperadores() {
	PILHA_OPERADORES* pilhaOperadores = (PILHA_OPERADORES*) malloc(sizeof(PILHA_OPERADORES));
	if (pilhaOperadores != NULL)
		*pilhaOperadores = NULL;
	return pilhaOperadores;
}

int tamanhoPilhaOperandos(PILHA_OPERANDOS* pilhaOperandos) {
	if (pilhaOperandos == NULL)
		return 0;

	int contador = 0;
	ELEMENTO_PILHA_OPERANDO* elementoPilhaOperandos = *pilhaOperandos;

	while (elementoPilhaOperandos != NULL) {
		contador++;
		elementoPilhaOperandos = elementoPilhaOperandos->proximoElementoPilhaOperando;
	}

	return contador;
}

int tamanhoPilhaOperadores(PILHA_OPERADORES* pilhaOperadores) {
	if (pilhaOperadores == NULL)
		return 0;

	int contador = 0;
	ELEMENTO_PILHA_OPERADOR* elementoPilhaOperadores = *pilhaOperadores;

	while (elementoPilhaOperadores != NULL) {
		contador++;
		elementoPilhaOperadores = elementoPilhaOperadores->proximoElementoPilhaOperador;
	}

	return contador;
}

int pilhaOperandosVazia(PILHA_OPERANDOS* pilhaOperandos) {
	if (pilhaOperandos == NULL)
		return 1;
	if (*pilhaOperandos == NULL)
		return 1;
	return 0;
}

int pilhaOperadoresVazia(PILHA_OPERADORES* pilhaOperadores) {
	if (pilhaOperadores == NULL)
		return 1;
	if (*pilhaOperadores == NULL)
		return 1;
	return 0;
}

int empilharPilhaOperandos(PILHA_OPERANDOS* pilhaOperandos, OPERANDO operando) {
	if (pilhaOperandos == NULL)
		return 0;

	ELEMENTO_PILHA_OPERANDO* elementoPilhaOperandos = (ELEMENTO_PILHA_OPERANDO*) malloc(sizeof(ELEMENTO_PILHA_OPERANDO));

	if (elementoPilhaOperandos == NULL)
		return 0;

	elementoPilhaOperandos->operando = operando;
	elementoPilhaOperandos->proximoElementoPilhaOperando = (*pilhaOperandos);

	*pilhaOperandos = elementoPilhaOperandos;

	return 1;
}

int empilharPilhaOperadores(PILHA_OPERADORES* pilhaOperadores, OPERADOR operador) {
	if (pilhaOperadores == NULL)
		return 0;

	ELEMENTO_PILHA_OPERADOR* elementoPilhaOperadores = (ELEMENTO_PILHA_OPERADOR*) malloc(sizeof(ELEMENTO_PILHA_OPERADOR));

	if (elementoPilhaOperadores == NULL)
		return 0;

	elementoPilhaOperadores->operador = operador;
	elementoPilhaOperadores->proximoElementoPilhaOperador = (*pilhaOperadores);

	*pilhaOperadores = elementoPilhaOperadores;

	return 1;
}

OPERANDO desempilharPilhaOperandos(PILHA_OPERANDOS* pilhaOperandos) {
	OPERANDO operando = { '\0' };

	if (pilhaOperandos == NULL)
		return operando;

	if ((*pilhaOperandos) == NULL)
		return operando;

	ELEMENTO_PILHA_OPERANDO* elementoPilhaOperando = *pilhaOperandos;
	*pilhaOperandos = elementoPilhaOperando->proximoElementoPilhaOperando;
	operando = elementoPilhaOperando->operando;

	free(elementoPilhaOperando);
	return operando;
}

OPERADOR desempilharPilhaOperador(PILHA_OPERADORES* pilhaOperadores) {
	OPERADOR operador = { '\0' };

	if (pilhaOperadores == NULL)
		return operador;

	if ((*pilhaOperadores) == NULL)
		return operador;

	ELEMENTO_PILHA_OPERADOR* elementoPilhaOperador = *pilhaOperadores;
	*pilhaOperadores = elementoPilhaOperador->proximoElementoPilhaOperador;
	operador = elementoPilhaOperador->operador;

	free(elementoPilhaOperador);
	return operador;
}

OPERANDO verTopoPilhaOperandos(PILHA_OPERANDOS* pilhaOperandos) {
	OPERANDO operando = { '\0' };

	if (pilhaOperandos == NULL)
		return operando;

	if ((*pilhaOperandos) == NULL)
		return operando;

	return (*pilhaOperandos)->operando;
}

OPERADOR verTopoPilhaOperadores(PILHA_OPERADORES* pilhaOperadores) {
	OPERADOR operador = { '\0' };

	if (pilhaOperadores == NULL)
		return operador;

	if ((*pilhaOperadores) == NULL)
		return operador;

	return (*pilhaOperadores)->operador;
}
