/*
 ============================================================================
 Name        : Aula02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// -- ALOCAÇÃO DE MEMÓRIA QUANDO O PROGRAMA É RODADO --
/*
 * CODE		Onde está o código fonte do programa
 * STATIC	Local onde estão as variáveis globais, estáticas ou constantes
 * STACK	Área de memória para as pilhas e suas variáveis locais
 * HEAP		Espaços de memória para alocações dinâmicas
 */

int main(void) {
	setbuf(stdout, NULL);
	return EXIT_SUCCESS;
}
