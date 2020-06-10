/*
 * Library.h
 *
 *  Created on: 4 de dez de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#define true 1
#define false 0
typedef int bool;

typedef int CHAVE;
typedef struct structArvore {
	CHAVE chave;
	struct structArvore* esquerda;
	struct structArvore* direita;
} NO;
typedef NO* ARVORE;

/* Matriz de Adjacências
typedef int PESO;
typedef struct structGrafo {
	int vertices;
	int arestas;
	PESO** matrizAdjacencias;
} GRAFO;
*/

/* Lista de Adjacências */
typedef int PESO;
typedef struct structListaAdjacencia {
	int vertice;
	PESO peso;
	struct structListaAdjacencia* proximoVertice;
} LISTA_ADJACENCIA;
typedef struct structVertice {
	LISTA_ADJACENCIA* listaAdjacencia;
} VERTICE;
typedef struct structGrafo {
	int qntVertices;
	int qntArestas;
	VERTICE* vertice;
} GRAFO;

ARVORE cria();
ARVORE insere(ARVORE, ARVORE);
ARVORE criaNovoNo(CHAVE);

#endif /* LIBRARY_H_ */
