/*
 * satlib.h
 *
 *  Created on: 3 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#ifndef SATLIB_H_
#define SATLIB_H_

typedef struct struct_elementpos {
	int i;
	int j;
} ELEMENT_POS;

typedef struct struct_node {
	ELEMENT_POS element;
	struct struct_node* nextNode;
} Node;

typedef struct struct_pile {
	struct struct_node* topNode;
	struct struct_node* bottomNode;
	int size;
} PILE;

void create(PILE*);
int empty(PILE);
int push(ELEMENT_POS, PILE*);
int pop(PILE*, ELEMENT_POS*);
int look(PILE*, ELEMENT_POS*);
int size(PILE);
void stack_elementpos(int, int, PILE*);
void unstack_elementpos(int*, int*, PILE*);

void print_err();
void print_arr(int**, int, int);
void print_result(char*, int, int);

void check_file(int, char**);
void read_file(char*);

int num_constr(int**, int, int);
void mark_constr(int**, int, int, int, int);

void walkto_topneighbor(int*, int*);
void walkto_topleftneighbor(int*, int*);
void walkto_toprightneighbor(int*, int*);
void walkto_bottomneighbor(int*, int*);
void walkto_bottomleftneighbor(int*, int*);
void walkto_bottomrightneighbor(int*, int*);
void walkto_leftneighbor(int*, int*);
void walkto_rightneighbor(int*, int*);
int get_topneighbor(int**, int, int, int, int);
int get_topleftneighbor(int**, int, int, int, int);
int get_toprightneighbor(int**, int, int, int, int);
int get_bottomneighbor(int**, int, int, int, int);
int get_bottomleftneighbor(int**, int, int, int, int);
int get_bottomrightneighbor(int**, int, int, int, int);
int get_leftneighbor(int**, int, int, int, int);
int get_rightneighbor(int**, int, int, int, int);
int checkall_neighbors(int**, int, int, int, int);

#endif /* SATLIB_H_ */
