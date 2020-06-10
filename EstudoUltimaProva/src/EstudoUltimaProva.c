/*
 ============================================================================
 Name        : EstudoUltimaProva.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(void) {
	printf("Estudo para Prova\n");

	ARVORE arvore = cria();

	ARVORE no = criaNovoNo(23);
	arvore = insere(arvore, no);

	return EXIT_SUCCESS;
}
