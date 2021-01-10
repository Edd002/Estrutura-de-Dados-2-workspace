/*
 ============================================================================
 Name        : simula.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "simlib.h"

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	verificarArgumentos(argc, argv);

	return EXIT_SUCCESS;
}
