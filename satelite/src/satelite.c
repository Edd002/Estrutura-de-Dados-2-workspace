/*
 ============================================================================
 Name        : satelite.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// C:\Users\eddua\Documents\Eduardo\Universidade\FUMEC\4� Per�odo\Estruturas de Dados 2\Exerc�cios\workspace\satelite\Debug

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "satlib.h"

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	check_file(argc, argv);

	return EXIT_SUCCESS;
}
