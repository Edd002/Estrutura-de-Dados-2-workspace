/*
 * Pilha.h
 *
 *  Created on: 5 de set de 2018
 *      Author: n226804875
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct structOperandos {
	char caracterOperando;
} OPERANDO;

typedef struct structOperadores {
	char caracterOperador;
} OPERADOR;

typedef struct structElementoPilhaOperando {
	OPERANDO operando;
	struct structElementoPilhaOperando* proximoElementoPilhaOperando;
} ELEMENTO_PILHA_OPERANDO;

typedef struct structElementoPilhaOperador {
	OPERADOR operador;
	struct structElementoPilhaOperador* proximoElementoPilhaOperador;
} ELEMENTO_PILHA_OPERADOR;

typedef ELEMENTO_PILHA_OPERANDO* PILHA_OPERANDOS;
typedef ELEMENTO_PILHA_OPERADOR* PILHA_OPERADORES;


PILHA_OPERANDOS* criarPilhaOperandos();
PILHA_OPERADORES* criarPilhaOperadores();
int tamanhoPilhaOperandos(PILHA_OPERANDOS*);
int tamanhoPilhaOperadores(PILHA_OPERADORES*);
int pilhaOperandosVazia(PILHA_OPERANDOS*);
int pilhaOperadoresVazia(PILHA_OPERADORES*);
int empilharPilhaOperandos(PILHA_OPERANDOS*, OPERANDO);
int empilharPilhaOperadores(PILHA_OPERADORES*, OPERADOR);
OPERANDO desempilharPilhaOperandos(PILHA_OPERANDOS*);
OPERADOR desempilharPilhaOperador(PILHA_OPERADORES*);
OPERANDO verTopoPilhaOperandos(PILHA_OPERANDOS*);
OPERADOR verTopoPilhaOperadores(PILHA_OPERADORES*);

#endif /* PILHA_H_ */
