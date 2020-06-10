/*
 ============================================================================
 Name        : ExercicioPilhaVersao2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

void testarPilha();
void analisarExpressao(char*);
char realizarOperacao(char, char, char);

int main(int argc, char* argv[]) {
	setbuf(stdout, NULL);

	analisarExpressao(argv[1]);
	printf("\n\n\nFim do programa.");

	return EXIT_SUCCESS;
}

void testarPilha() {
	PILHA_OPERANDOS* pilhaOperandos = criarPilhaOperandos();
	PILHA_OPERADORES* pilhaOperadores = criarPilhaOperadores();

	printf("Tamanho da pilha de operandos: %i", tamanhoPilhaOperandos(pilhaOperandos));
	printf("\nTamanho da pilha de operadores: %i", tamanhoPilhaOperadores(pilhaOperadores));

	printf("\n\nPilha de operandos vazia?: %i", pilhaOperandosVazia(pilhaOperandos));
	printf("\nPilha de operadores vazia? %i", pilhaOperadoresVazia(pilhaOperadores));

	OPERANDO operando;
	operando.caracterOperando = '5';
	printf("\n\nEmpilhando operando...");
	empilharPilhaOperandos(pilhaOperandos, operando);
	printf("\nPilha de operandos vazia?: %i", pilhaOperandosVazia(pilhaOperandos));
	printf("\nTamanho da pilha de operandos: %i", tamanhoPilhaOperandos(pilhaOperandos));

	OPERANDO operando2;
	operando2.caracterOperando = '6';
	printf("\n\nEmpilhando operando...");
	empilharPilhaOperandos(pilhaOperandos, operando2);
	printf("\nPilha de operandos vazia?: %i", pilhaOperandosVazia(pilhaOperandos));
	printf("\nTamanho da pilha de operandos: %i", tamanhoPilhaOperandos(pilhaOperandos));

	OPERADOR operador;
	operador.caracterOperador = '+';
	printf("\n\nEmpilhando operador...");
	empilharPilhaOperadores(pilhaOperadores, operador);
	printf("\nPilha de operadores vazia? %i", pilhaOperadoresVazia(pilhaOperadores));
	printf("\nTamanho da pilha de operadores: %i", tamanhoPilhaOperadores(pilhaOperadores));

	OPERADOR operador2;
	operador2.caracterOperador = '-';
	printf("\n\nEmpilhando operador...");
	empilharPilhaOperadores(pilhaOperadores, operador2);
	printf("\nPilha de operadores vazia? %i", pilhaOperadoresVazia(pilhaOperadores));
	printf("\nTamanho da pilha de operadores: %i", tamanhoPilhaOperadores(pilhaOperadores));

	OPERANDO operandoVerificado = verTopoPilhaOperandos(pilhaOperandos);
	printf("\n\nVerificando topo da pilha de operandos...");
	printf("\nCaracter do operando verificado: %c", operandoVerificado.caracterOperando);

	OPERADOR operadorVerificado = verTopoPilhaOperadores(pilhaOperadores);
	printf("\n\nVerificando topo da pilha de operadores...");
	printf("\nCaracter do operador verificado: %c", operadorVerificado.caracterOperador);

	printf("\n\nDesempilhando operando...");
	OPERANDO operandoDesempilhado = desempilharPilhaOperandos(pilhaOperandos);
	printf("\nCaracter do operando desempilhado: %c", operandoDesempilhado.caracterOperando);
	printf("\nPilha de operandos vazia?: %i", pilhaOperandosVazia(pilhaOperandos));
	printf("\nTamanho da pilha de operandos: %i", tamanhoPilhaOperandos(pilhaOperandos));

	printf("\n\nDesempilhando operador...");
	OPERADOR operadorDesempilhado = desempilharPilhaOperador(pilhaOperadores);
	printf("\nCaracter do operador desempilhado: %c", operadorDesempilhado.caracterOperador);
	printf("\nPilha de operadores vazia?: %i", pilhaOperadoresVazia(pilhaOperadores));
	printf("\nTamanho da pilha de operadores: %i", tamanhoPilhaOperadores(pilhaOperadores));

	OPERANDO operandoVerificado2 = verTopoPilhaOperandos(pilhaOperandos);
	printf("\n\nVerificando topo da pilha de operandos...");
	printf("\nCaracter do operando verificado: %c", operandoVerificado2.caracterOperando);

	OPERADOR operadorVerificado2 = verTopoPilhaOperadores(pilhaOperadores);
	printf("\n\nVerificando topo da pilha de operadores...");
	printf("\nCaracter do operador verificado: %c", operadorVerificado2.caracterOperador);
}

void analisarExpressao(char* expressao) {
	printf("Expressão: %s\n", expressao);
	printf("Tamanho da expressão: %i\n", (int) strlen(expressao));

	PILHA_OPERANDOS* pilhaOperandos = criarPilhaOperandos();
	PILHA_OPERADORES* pilhaOperadores = criarPilhaOperadores();

	OPERADOR operador = { '#' };
	empilharPilhaOperadores(pilhaOperadores, operador);

	int i;
	for (i = 0; i < strlen(expressao); i++) {
		if (expressao[i] >= '0' && expressao[i] <= '9') {
			OPERANDO operandoNovo = { expressao[i] };
			empilharPilhaOperandos(pilhaOperandos, operandoNovo);

		} else if (expressao[i] == '(') {
			OPERADOR operadorNovo = { expressao[i] };
			empilharPilhaOperadores(pilhaOperadores, operadorNovo);

		} else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/') {
			OPERADOR operadorCorrente = { expressao[i] };
			OPERADOR operadorTopoPilha = verTopoPilhaOperadores(pilhaOperadores);

			if (operadorCorrente.caracterOperador == '+' || operadorCorrente.caracterOperador == '-') {
				if (operadorTopoPilha.caracterOperador == '(' || operadorTopoPilha.caracterOperador == '#') {
					empilharPilhaOperadores(pilhaOperadores, operadorCorrente);
				} else {
					OPERADOR operadorDesempilhado = desempilharPilhaOperador(pilhaOperadores);
					OPERANDO operandoDesempilhado1 = desempilharPilhaOperandos(pilhaOperandos);
					OPERANDO operandoDesempilhado2 = desempilharPilhaOperandos(pilhaOperandos);
					OPERANDO operandoResultado = { realizarOperacao(operadorDesempilhado.caracterOperador, operandoDesempilhado1.caracterOperando, operandoDesempilhado2.caracterOperando) };

					empilharPilhaOperadores(pilhaOperadores, operadorCorrente);
					empilharPilhaOperandos(pilhaOperandos, operandoResultado);
				}
			} else if (operadorCorrente.caracterOperador == '*' || operadorCorrente.caracterOperador == '/') {
				if (operadorTopoPilha.caracterOperador == '+' || operadorTopoPilha.caracterOperador == '-' || operadorTopoPilha.caracterOperador == '(' || operadorTopoPilha.caracterOperador == '#') {
					empilharPilhaOperadores(pilhaOperadores, operadorCorrente);
				} else {
					OPERADOR operadorDesempilhado = desempilharPilhaOperador(pilhaOperadores);
					OPERANDO operandoDesempilhado1 = desempilharPilhaOperandos(pilhaOperandos);
					OPERANDO operandoDesempilhado2 = desempilharPilhaOperandos(pilhaOperandos);
					OPERANDO operandoResultado = { realizarOperacao(operadorDesempilhado.caracterOperador, operandoDesempilhado1.caracterOperando, operandoDesempilhado2.caracterOperando) };

					empilharPilhaOperadores(pilhaOperadores, operadorCorrente);
					empilharPilhaOperandos(pilhaOperandos, operandoResultado);
				}
			}

		} else if (expressao[i] == ')') {
			OPERADOR operadorDesempilhado = desempilharPilhaOperador(pilhaOperadores);

			while (operadorDesempilhado.caracterOperador != '(') {
				OPERANDO operandoDesempilhado1 = desempilharPilhaOperandos(pilhaOperandos);
				OPERANDO operandoDesempilhado2 = desempilharPilhaOperandos(pilhaOperandos);
				OPERANDO operandoResultado = { realizarOperacao(operadorDesempilhado.caracterOperador, operandoDesempilhado1.caracterOperando, operandoDesempilhado2.caracterOperando) };
				empilharPilhaOperandos(pilhaOperandos, operandoResultado);
			}

		} else if (expressao[i] == '\0') {
			OPERADOR operadorDesempilhado;

			while (operadorDesempilhado.caracterOperador != '#') {
				operadorDesempilhado = desempilharPilhaOperador(pilhaOperadores);

				OPERANDO operandoDesempilhado1 = desempilharPilhaOperandos(pilhaOperandos);
				OPERANDO operandoDesempilhado2 = desempilharPilhaOperandos(pilhaOperandos);
				OPERANDO operandoResultado = { realizarOperacao(operadorDesempilhado.caracterOperador, operandoDesempilhado1.caracterOperando, operandoDesempilhado2.caracterOperando) };

				empilharPilhaOperandos(pilhaOperandos, operandoResultado);
			} while (operadorDesempilhado.caracterOperador != '#');
		}
	}

	OPERANDO operandoResultado = (*pilhaOperandos)->operando;
	printf("\nResultado: %c", operandoResultado.caracterOperando);
}

char realizarOperacao(char operador, char operando1, char operando2) {
	int operando1Int = operando1 - '0';
	int operando2Int = operando2 - '0';
	int resultado = 0;

	if (operador == '+')
		resultado = operando1Int + operando2Int;
	else if (operador == '-')
		resultado = operando1Int - operando2Int;
	else if (operador == '*')
		resultado = operando1Int * operando2Int;
	else if (operador == '/')
		resultado = operando1Int / operando2Int;

	return resultado + '0';
}
