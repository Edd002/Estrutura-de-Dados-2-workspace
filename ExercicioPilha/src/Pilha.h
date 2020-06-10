/*
 * Pilha.h
 *
 *  Created on: 30 de ago de 2018
 *      Author: n226804875
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct structItem {
	char operador;
	int operando;
} Data;

typedef struct structNode {
	Data element;
	struct structNode* nextNode;
} Node;

typedef struct structPile {
	struct structNode* topNode;
	struct structNode* bottomNode;
	int size;
} PILE;

void create(PILE*);
int empty(PILE);
int push(Data, PILE*);
int pop(PILE*, Data*);
int look(PILE*, Data*);
int size(PILE);

#endif /* PILHA_H_ */
