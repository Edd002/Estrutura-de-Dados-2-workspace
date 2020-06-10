/*
 ============================================================================
 Name        : RevisaoLista.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(void) {
	setbuf(stdout, NULL);

	LIST* list = createList();

	showList(list);
	insertNodeEnd(list);
	insertNodeBegin(list);
	insertNodeBegin(list);
	showList(list);
	removeNode(list);
	showList(list);

	return EXIT_SUCCESS;
}
