/*
 ============================================================================
 Name        : ExercicioPilha.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
OBESERVAÇÃO:
	1- Primeira célular HEADER
	2- Ponteiro para apontar para o último elemento
	3- Armazenar o tamanho

	NOTAÇÃO INFIXA -> NOTAÇÃO POSFIXA
	5 x 2 + 3 -> 5 2 x 3 +
	5 + 2 x 3 -> 5 2 3 x +
	( 5 + 2 ) x 3 -> 5 2 + 3 x

	-- REGRA PARA OPERANDO --
	JOGAR PARA SAÍDA

	-- REGRA PARA OPERADOR --
	CRIAR A PILHA COM UM OPERADOR FALSO (#) COM MENOR PRIORIDADE QUE TODOS OS OUTROS PARA EVITAR A VERIFICAÇÃO DE PILHA VAZIA
	PRIORIDADE IGUAL/MENOR: DESEMPILHAR O OPERADOR DO TOPO E JOGAR PARA SAÍDA E EMPILHAR O ANALISADO
	PRIORIDADE MAIOR: EMPILHAR

	-- REGRA PARA ABRE PARENTESES --
	JOGAR PARA PILHA

	-- REGRA PARA FECHAR PARENTESES --
	DESIMPILHAR TUDO ATÉ ENCONTRAR ABRE PARENTESES E JOGAR PARA SAÍDA

	AO CHEGAR NO FINAL DA EXPRESSÃO DESEMPILHAR TUDO E JOGAR PARA SAÍDA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

void adicionarOperandoPilha(char, PILE*);
char consultarOperandoPilha(PILE*);
char removerOperandoPilha(PILE*);

void adicionarOperadorPilha(char, PILE*);
char consultarOperadorPilha(PILE*);
char removerOperadorPilha(PILE*);

void examinarExpressaoInfixa(char*, PILE*, PILE*);
void realizarOperacao(PILE*, char);

int main(int argc, char* argv[]) {
	setbuf(stdout, NULL);
	//printf("Arg[1]: %s\nArg[2]: %s\nArg[3]: %s", argv[1], argv[2], argv[3]);

	PILE pileOperadores;
	create(&pileOperadores);
	PILE pileOperandos;
	create(&pileOperandos);

	adicionarOperadorPilha('#', &pileOperadores);
	examinarExpressaoInfixa(argv[1], &pileOperadores, &pileOperandos);

	return EXIT_SUCCESS;
}


void adicionarOperandoPilha(char operando, PILE* pile) {
	operando = operando - '0';
	Data data;
	data.operando = operando;
	push(data, pile);
}

char consultarOperandoPilha(PILE* pile) {
	Data data;
	look(pile, &data);
	return data.operando;
}

char removerOperandoPilha(PILE* pile) {
	Data data;
	pop(pile, &data);
	return data.operando;
}

void adicionarOperadorPilha(char operador, PILE* pile) {
	Data data;
	data.operador = operador;
	push(data, pile);
}

char consultarOperadorPilha(PILE* pile) {
	Data data;
	look(pile, &data);
	return data.operador;
}

char removerOperadorPilha(PILE* pile) {
	Data data;
	pop(pile, &data);
	return data.operador;
}


void examinarExpressaoInfixa(char* expressao, PILE* pileOperadores, PILE* pileOperandos) {
	int i = 0;

	printf("\n\nExpressão: %s", expressao);

	for (i = 0; i < strlen(expressao); i++) {
		if (expressao[i] >= '0' && expressao[i] <= '9') {
			adicionarOperandoPilha(expressao[i], pileOperandos);

		} else if (expressao[i] == '(') {
			adicionarOperadorPilha(expressao[i], pileOperadores);

		} else if (expressao[i] == '+' || expressao[i] == '-') {

			char operadorTopoPilha = consultarOperadorPilha(pileOperadores);
			if (operadorTopoPilha == '*' || operadorTopoPilha == '/') {
				adicionarOperadorPilha(expressao[i], pileOperadores);
			} else {
				realizarOperacao(pileOperandos, removerOperandoPilha(pileOperadores));
				adicionarOperadorPilha(expressao[i], pileOperadores);
			}

		} else if (expressao[i] == '*' || expressao[i] == '/') {
			realizarOperacao(pileOperandos, removerOperandoPilha(pileOperadores));

		} else if (expressao[i] == '#') {
			adicionarOperandoPilha(expressao[i], pileOperadores);

		} else if (expressao[i] == ')') {
			Data dataOperador;
			do {
				pop(pileOperadores, &dataOperador);
				printf("%c", dataOperador.operador);
			} while (dataOperador.operador != '(');
		}
	}

	Data dataOperador;
	do {
		pop(pileOperadores, &dataOperador);
		printf("%c", dataOperador.operador);
	} while(dataOperador.operador != '#');
}

void realizarOperacao(PILE* pileOperandos, char operacao) {
	Data dataPrimeiroOperando;
	Data dataSegundoOperando;

	pop(pileOperandos, &dataPrimeiroOperando);
	pop(pileOperandos, &dataSegundoOperando);

	int primeiroOperando = dataPrimeiroOperando.operando;
	int segundoOperando = dataSegundoOperando.operando;

	Data dataResultado;
	if (operacao == '+') {
		dataResultado.operando = primeiroOperando + segundoOperando;
		push(dataResultado, pileOperandos);
	} else if (operacao == '-') {
		dataResultado.operando = primeiroOperando - segundoOperando;
		push(dataResultado, pileOperandos);
	} else if (operacao == '*') {
		dataResultado.operando = primeiroOperando * segundoOperando;
		push(dataResultado, pileOperandos);
	} else if (operacao == '/') {
		dataResultado.operando = primeiroOperando / segundoOperando;
		push(dataResultado, pileOperandos);
	}
}
