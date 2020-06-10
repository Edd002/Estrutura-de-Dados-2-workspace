/*
 * Lista.c
 *
 *  Created on: 12 de fev de 2019
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

LIST* createList() {
	LIST* list = (LIST*) malloc(sizeof(LIST));
	if (list != NULL)
		*list = NULL; // Se a lista não for nula o primeiro nó dela deverá ser atribuido como nulo.
	return list;
}

void insertNodeBegin(LIST* list) {
	DATA data;
	data.key = rand();
	data.activated = true;

	NODE* newNode = (NODE*) malloc(sizeof(NODE));

	newNode->data = data;
	newNode->nextNode = (*list);
	newNode->previousNode = NULL;

	if (*list != NULL)
		(*list)->previousNode = newNode;
	*list = newNode;
}

void insertNodeEnd(LIST* list) {
	DATA data;
	data.key = rand();
	data.activated = true;

	NODE* newNode = (NODE*) malloc(sizeof(NODE));
	newNode->data = data;
	newNode->nextNode = NULL;

	if (*list == NULL) {
		newNode->previousNode = NULL;
		*list = newNode;
	} else {
		NODE* auxNode = *list;
		while(auxNode->nextNode != NULL)
			auxNode = auxNode->nextNode;
		auxNode->nextNode = newNode;
		newNode->previousNode = auxNode;
	}
}

void removeNode(LIST* list) {
	if (list == NULL || (*list) == NULL) {
		printf("\nEmpty list.");
	} else {
		int searchedKey = 0;
		printf("\nKey for data removal: ");
		fflush(stdin);
		scanf("%i", &searchedKey);

		NODE* searchedNode = *list;
		while(searchedNode != NULL && searchedNode->data.key != searchedKey)
			searchedNode = searchedNode->nextNode;

		if (searchedNode == NULL) {
			printf("\nKey not found.");
		} else {
			if (searchedNode->previousNode == NULL)
				*list = searchedNode->nextNode;
			else
				searchedNode->previousNode->nextNode = searchedNode->nextNode;

			if (searchedNode->nextNode != NULL)
				searchedNode->nextNode->previousNode = searchedNode->previousNode;

			free(searchedNode);

			printf("\nData with the code %i has been deleted.", searchedKey);
		}
	}
}

void showList(LIST* list) {
	NODE* searchedNode = *list;
	bool hasSearch = false;

	while (searchedNode != NULL) {
		printf("\nKey: %i - Activated: %i", searchedNode->data.key, searchedNode->data.activated);
		hasSearch = true;
		searchedNode = searchedNode->nextNode;
	}

	if (hasSearch == false)
		printf("\nEmpty list.");
}
