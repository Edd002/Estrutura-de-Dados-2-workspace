/*
 * satlib.c
 *
 *  Created on: 3 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "satlib.h"

// -- Pile functions --
void create(PILE* pile) {
	pile->topNode = (Node*) malloc(sizeof(Node));
	pile->bottomNode = pile->topNode;
	pile->topNode->nextNode = NULL;
	pile->size = 0;
}

int empty(PILE pile) {
	return (pile.topNode == pile.bottomNode);
}

int push(ELEMENT_POS element, PILE* pile) {
	Node* aux;

	aux = (Node*) malloc(sizeof(Node));
	pile->topNode->element = element;
	aux->nextNode = pile->topNode;
	pile->topNode = aux;
	pile->size++;

	return 0;
}

int pop(PILE* pile, ELEMENT_POS* element) {
	Node* node;

	if (empty(*pile))
		return -1;

	node = pile->topNode;
	pile->topNode = node->nextNode;
	*element = node->nextNode->element;
	free(node);
	pile->size--;

	return 0;
}

int look(PILE* pile, ELEMENT_POS* element) {
	if (empty(*pile))
		return -1;

	*element = pile->topNode->nextNode->element;

	return 0;
}

int size(PILE pile) {
	return pile.size;
}

void stack_elementpos(int i, int j, PILE* pile) {
	ELEMENT_POS element;
	element.i = i;
	element.j = j;
	push(element, pile);
}

void unstack_elementpos(int* i, int* j, PILE* pile) {
	ELEMENT_POS element;
	pop(pile, &element);
	(*i) = element.i;
	(*j) = element.j;
}

// -- Print functions --
void print_err() {
	printf("Utilização: satélite <imagem>\n"
			"<imagem>: nome do arquivo contendo a imagem");
	exit(1);
}

void print_arr(int** arr, int M, int N) {
	int i, j;

	printf("\n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%i ", arr[i][j]);

			if (j == (N - 1))
				printf("\n");
		}
	}
	printf("\n");
}

void print_result(char* name_file, int num_cel, int num_constr) {
	printf("Examinando imagem %s\n"
			"Número de células da imagem: %i\n"
			"Número de construções: %i", name_file, num_cel, num_constr);
}


// -- File functions --
void check_file(int argc, char** argv) {
	if(argc == 2)
		read_file(argv[1]);
	else
		print_err();
}

void read_file(char* name_file) {
	FILE *file;
	int cel;
	int M, N;
	int i = 0, j = 0;

	file = fopen(name_file, "rb");
	if (file == NULL)
		print_err();

	fscanf(file, "%i %i", &M, &N);

	int** arr = (int**) calloc(M, sizeof(int*));
	for (i = 0; i < M; i++)
		arr[i] = (int*) calloc(N, sizeof(int));

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			fscanf(file, "%i", &cel);

			if (cel != 0 && cel != 1)
				print_err();

			arr[i][j] = cel;
		}
	}

	fclose(file);

	print_result(name_file, M * N, num_constr(arr, M, N));
	//print_arr(arr, M, N);
}


// -- Array functions --
int num_constr(int** arr, int M, int N) {
	int i, j;
	int cont_constr = 0;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			// SE O ELEMENTO FOR IGUAL A 1 SOMAR UMA CONSTRUÇÃO E MARCÁ-LA POR COMPLETO
			if (arr[i][j] == 1) {
				cont_constr++;
				mark_constr(arr, i, j, M, N);
			}
		}
	}

	return cont_constr;
}

// Esta função percorrerá a construção marcando os elementos, ou seja, enquanto toda construção não estiver marcada esta função não termina
void mark_constr(int** arr, int i, int j, int M, int N) {
	PILE pile;
	create(&pile);
	int initial_i = i;
	int initial_j = j;

	while (1) { // CAMINHAR NO VETOR MARCANDO OS ELEMENTOS VISITADOS
		arr[i][j] = 2;

		if (checkall_neighbors(arr, i, j, M, N) == 1) { // SE HOUVER VIZINHOS: EMPILHAR O ELEMENTO E CONTINUAR PERCORRENDO A CONSTRUÇÃO
			stack_elementpos(i, j, &pile);

			if (get_topneighbor(arr, i, j, M, N) == 1)
				walkto_topneighbor(&i, &j);

			if (get_topleftneighbor(arr, i, j, M, N) == 1)
				walkto_topleftneighbor(&i, &j);

			if (get_toprightneighbor(arr, i, j, M, N) == 1)
				walkto_toprightneighbor(&i, &j);

			if (get_bottomneighbor(arr, i, j, M, N) == 1)
				walkto_bottomneighbor(&i, &j);

			if (get_bottomleftneighbor(arr, i, j, M, N) == 1)
				walkto_bottomleftneighbor(&i, &j);

			if (get_bottomrightneighbor(arr, i, j, M, N) == 1)
				walkto_bottomrightneighbor(&i, &j);

			if (get_leftneighbor(arr, i, j, M, N) == 1)
				walkto_leftneighbor(&i, &j);

			if (get_rightneighbor(arr, i, j, M, N) == 1)
				walkto_rightneighbor(&i, &j);

			continue;
		} else { // SE NÃO HOUVER VIZINHOS: DESEMPILHAR OS ELEMENTOS VERIFICANDO POSSÍVEIS OUTROS CAMINHOS

			// QUANDO A PILHA ESTIVER VAZIA É QUE VOLTOU PARA POSIÇÃO INICIAL
			if (empty(pile))
				break;

			unstack_elementpos(&i, &j, &pile);
			if (checkall_neighbors(arr, i, j, M, N) == 1)
				continue;
		}
	}

	//printf("Posição inicial da construção: <i: %i> <j: %i>\n", i, j);
	i = initial_i;
	j = initial_j;
}


// -- Neighbors Functions --
void walkto_topneighbor(int* i, int* j) {
	(*i)--;
}

void walkto_topleftneighbor(int* i, int* j) {
	(*i)--;
	(*j)--;
}

void walkto_toprightneighbor(int* i, int* j) {
	(*i)--;
	(*j)++;
}

void walkto_bottomneighbor(int* i, int* j) {
	(*i)++;
}

void walkto_bottomleftneighbor(int* i, int* j) {
	(*i)++;
	(*j)--;
}

void walkto_bottomrightneighbor(int* i, int* j) {
	(*i)++;
	(*j)++;
}

void walkto_leftneighbor(int* i, int* j) {
	(*j)--;
}

void walkto_rightneighbor(int* i, int* j) {
	(*j)++;
}

int get_topneighbor(int** arr, int i, int j, int M, int N) {
	// Primeira linha retornar 0
	return (i == 0) ? 0 : arr[i - 1][j];
}

int get_topleftneighbor(int** arr, int i, int j, int M, int N) {
	// Primeira linha ou primeira coluna retornar 0
	return (i == 0 || j == 0) ? 0 : arr[i - 1][j - 1];
}

int get_toprightneighbor(int** arr, int i, int j, int M, int N) {
	// Primeira linha ou última coluna retornar 0
	return (i == 0 || j == (N - 1)) ? 0 : arr[i - 1][j + 1];
}

int get_bottomneighbor(int** arr, int i, int j, int M, int N) {
	// Última linha retornar 0
	return  (i == (M - 1)) ? 0 : arr[i + 1][j];
}

int get_bottomleftneighbor(int** arr, int i, int j, int M, int N) {
	// Última linha ou primeira coluna retornar 0
	return  (i == (M - 1) || j == 0) ? 0 : arr[i + 1][j - 1];
}

int get_bottomrightneighbor(int** arr, int i, int j, int M, int N) {
	// Última linha ou última coluna retornar 0
	return (i == (M - 1) || j == (N - 1)) ? 0 : arr[i + 1][j + 1];
}

int get_leftneighbor(int** arr, int i, int j, int M, int N) {
	// Primeira coluna retornar 0
	return (j == 0) ? 0 : arr[i][j - 1];
}

int get_rightneighbor(int** arr, int i, int j, int M, int N) {
	// Última coluna retornar 0
	return (j == (N - 1)) ? 0 : arr[i][j + 1];
}

int checkall_neighbors(int** arr, int i, int j, int M, int N) {
	if (get_topneighbor(arr, i, j, M, N) == 1)
		return 1;

	if (get_topleftneighbor(arr, i, j, M, N) == 1)
		return 1;

	if (get_toprightneighbor(arr, i, j, M, N) == 1)
		return 1;

	if (get_bottomneighbor(arr, i, j, M, N) == 1)
		return 1;

	if (get_bottomleftneighbor(arr, i, j, M, N) == 1)
		return 1;

	while (get_bottomrightneighbor(arr, i, j, M, N) == 1)
		return 1;

	while (get_leftneighbor(arr, i, j, M, N) == 1)
		return 1;

	while (get_rightneighbor(arr, i, j, M, N) == 1)
		return 1;

	return 0;
}
