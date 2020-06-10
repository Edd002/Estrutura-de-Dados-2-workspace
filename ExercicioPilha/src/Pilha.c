/*
 * Pilha.c
 *
 *  Created on: 30 de ago de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pilha.h"

void create(PILE* pile) {
	pile->topNode = (Node*) malloc(sizeof(Node));
	pile->bottomNode = pile->topNode;
	pile->topNode->nextNode = NULL;
	pile->size = 0;
}

int empty(PILE pile) {
	return (pile.topNode == pile.bottomNode);
}

int push(Data data, PILE* pile) {
	Node* aux;

	aux = (Node*) malloc(sizeof(Node));
	pile->topNode->element = data;
	aux->nextNode = pile->topNode;
	pile->topNode = aux;
	pile->size++;

	return 0;
}

int pop(PILE* pile, Data* data) {
	Node* node;

	if (empty(*pile))
		return -1;

	node = pile->topNode;
	pile->topNode = node->nextNode;
	*data = node->nextNode->element;
	free(node);
	pile->size--;

	return 0;
}

int look(PILE* pile, Data* data) {
	if (empty(*pile))
		return -1;

	*data = pile->topNode->nextNode->element;

	return 0;
}

int size(PILE pile) {
	return pile.size;
}
