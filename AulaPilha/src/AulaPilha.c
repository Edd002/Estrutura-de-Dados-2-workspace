/*
 ============================================================================
 Name        : AulaPilha.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int main(void) {
	setbuf(stdout, NULL);

	Pile pile;
	create(&pile);

	Data data;
	data.key = 5;
	data.caracter = "25";
	push(data, &pile);

	Data lookedData;
	look(&pile, &lookedData);

	printf("DADOS DO TOPO DA PILHA\nKey: %i\nTermo da expressão: %s\n", lookedData.key, lookedData.caracter);
	printf("Tamanho da pilha: %i", pile.size);

	return EXIT_SUCCESS;
}
