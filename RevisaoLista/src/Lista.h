/*
 * Lista.h
 *
 *  Created on: 12 de fev de 2019
 *      Author: n226804875
 */

#ifndef LISTA_H_
#define LISTA_H_

#define false 0
#define true 1
typedef int bool;

typedef struct structData {
	int key;
	bool activated;
} DATA;

typedef struct structNode {
	struct structNode* previousNode;
	DATA data;
	struct structNode* nextNode;
} NODE;

typedef NODE* LIST;

LIST* createList();
void insertNodeBegin(LIST*);
void insertNodeEnd(LIST*);
void removeNode(LIST*);
void showList(LIST*);

#endif /* LISTA_H_ */
