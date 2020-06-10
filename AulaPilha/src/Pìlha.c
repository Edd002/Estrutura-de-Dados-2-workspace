/*
 * Library.c
 *
 *  Created on: 23 de ago de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

void create(Pile* pile) {
	pile->topNode = (Node*) malloc(sizeof(Node));
	pile->bottomNode = pile->topNode;
	pile->topNode->nextNode = NULL;
	pile->size = 0;
}

int empty(Pile pile) {
	return (pile.topNode == pile.bottomNode);
}

int push(Data data, Pile* pile) {
	Node* aux;

	aux = (Node*) malloc(sizeof(Node));
	pile->topNode->data = data;
	aux->nextNode = pile->topNode;
	pile->topNode = aux;
	pile->size++;

	return 0;
}

int pop(Pile* pile, Data* data) {
	Node* node;

	if (empty(*pile))
		return -1;

	node = pile->topNode;
	pile->topNode = node->nextNode;
	*data = node->nextNode->data;
	free(node);
	pile->size--;

	return 0;
}

int look(Pile* pile, Data* data) {
	if (empty(*pile))
		return -1;

	*data = pile->topNode->nextNode->data;

	return 0;
}

int size(Pile pile) {
	return pile.size;
}
