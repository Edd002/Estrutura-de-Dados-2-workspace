/*
 * LibGrafo.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#ifndef LIBGRAFO_H_
#define LIBGRAFO_H_

typedef struct structGrafo {
	int ehPonderado;
	int numVertices;
	int grauMax;
	int** arestas;
	float** pesos;
	int* grau;
} GRAFO;

GRAFO* criarGrafo(int, int, int);
void liberarGrafo(GRAFO*);
int inserirAresta(GRAFO*, int, int, int, float);
int removerAresta(GRAFO*, int, int, int);

void buscaProfundidade(GRAFO*, int, int*, int);
void buscaProfundidadeGrafo(GRAFO*, int, int*);
void buscaLarguraGrafo(GRAFO*, int, int*);

#endif /* LIBGRAFO_H_ */
