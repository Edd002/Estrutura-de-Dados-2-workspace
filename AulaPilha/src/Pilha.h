/*
 * Library.h
 *
 *  Created on: 23 de ago de 2018
 *      Author: n226804875
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct structItem {
	int key;
	char* caracter;
} Data;

typedef struct structNode {
	Data data;
	struct structNode* nextNode;
} Node;

typedef struct structPile {
	struct structNode* topNode;
	struct structNode* bottomNode;
	int size;
} Pile;

void create(Pile*);
int empty(Pile);
int push(Data, Pile*);
int pop(Pile*, Data*);
int look(Pile*, Data*);
int size(Pile);

#endif /* PILHA_H_ */
