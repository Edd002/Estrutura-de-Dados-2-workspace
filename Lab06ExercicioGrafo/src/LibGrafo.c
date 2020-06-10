/*
 * LibGrafo.c
 *
 *  Created on: 22 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include "LibGrafo.h"

GRAFO* criarGrafo(int numVertices, int grauMax, int ehPonderado) {
	GRAFO* grafo = (GRAFO*) malloc(sizeof(GRAFO));

	if (grafo != NULL) {
		int i;
		grafo->numVertices = numVertices;
		grafo->grauMax = grauMax;
		grafo->ehPonderado = (ehPonderado != 0) ? 1 : 0;
		grafo->grau = (int*) calloc(numVertices, sizeof(int));
		grafo->arestas = (int**) malloc(numVertices * sizeof(int*));

		for (i = 0; i < numVertices; i++) {
			grafo->arestas[i] = (int*) malloc(grauMax * sizeof(int));
			if (grafo->ehPonderado) {
				grafo->pesos = (float**) malloc(numVertices * sizeof(float*));

				for (i = 0; i < numVertices; i++)
					grafo->pesos[i] = (float*) malloc(grauMax * sizeof(float));
			}
		}
	}

	return grafo;
}

void liberarGrafo(GRAFO* grafo) {
	if (grafo != NULL) {
		int i;

		for (i = 0; i < grafo->numVertices; i++)
			free(grafo->arestas[i]);
		free(grafo->arestas);

		if (grafo->ehPonderado) {
			for (i = 0; i < grafo->numVertices; i++)
				free(grafo->pesos[i]);
			free(grafo->pesos);
		}

		free(grafo->grau);
		free(grafo);
	}
}

int inserirAresta(GRAFO* grafo, int origem, int destino, int ehDigrafo, float peso) {
	if (grafo == NULL)
		return 0;
	if (origem < 0 || origem >= grafo->numVertices)
		return 0;
	if (destino < 0 || destino >= grafo->numVertices)
		return 0;

	grafo->arestas[origem][grafo->grau[origem]] = destino;
	if (grafo->ehPonderado)
		grafo->pesos[origem][grafo->grau[origem]] = peso;
	grafo->grau[origem]++;

	if (ehDigrafo == 0)
		inserirAresta(grafo, destino, origem, 1, peso);
	return 1;
}

int removerAresta(GRAFO* grafo, int origem, int destino, int ehDigrafo) {
	if (grafo == NULL)
		return 0;
	if (origem < 0 || origem >= grafo->numVertices)
		return 0;
	if (destino < 0 || destino >= grafo->numVertices)
		return 0;

	int i = 0;
	while (i < grafo->grau[origem] && grafo->arestas[origem][i] != destino)
		i++;

	if (i == grafo->grau[origem])
		return 0;

	grafo->grau[origem]--;
	grafo->arestas[origem][i] = grafo->arestas[origem][grafo->grau[origem]];

	if (grafo->ehPonderado)
		grafo->pesos[origem][i] = grafo->pesos[origem][grafo->grau[origem]];

	if (ehDigrafo == 0)
		removerAresta(grafo, destino, origem, 1);

	return 1;
}

void buscaProfundidade(GRAFO* grafo, int inicio, int* visitado, int cont) {
	int i;
	visitado[inicio] = cont;
	for (i = 0; i < grafo->grau[inicio]; i++) {
		if (!visitado[grafo->arestas[inicio][i]])
			buscaProfundidade(grafo, grafo->arestas[inicio][i], visitado, cont + 1);
	}
}

void buscaProfundidadeGrafo(GRAFO* grafo, int inicio, int* visitado) {
	int i, cont = 1;
	for (i = 0; i < grafo->numVertices; i++)
		visitado[i] = 0;
	buscaProfundidade(grafo, inicio, visitado, cont);
}

void buscaLarguraGrafo(GRAFO* grafo, int inicio, int* visitado) {
	int i, vertice, numVertices, cont = 1, *fila, inicioFila = 0, finalFila = 0;

	for (i = 0; i < grafo->numVertices; i++)
		visitado[i] = 0;

	numVertices = grafo->numVertices;
	fila = (int*) malloc(numVertices * sizeof(int));
	finalFila++;
	fila[finalFila] = inicio;
	visitado[inicio] = cont;

	while (inicioFila != finalFila) {
		inicioFila = (inicioFila + 1) % numVertices;
		vertice = fila[inicioFila];
		cont++;
		for (i = 0; i < grafo->grau[vertice]; i++) {
			if (!visitado[grafo->arestas[vertice][i]]) {
				finalFila = (finalFila + 1) % numVertices;
				fila[finalFila] = grafo->arestas[vertice][i];
				visitado[grafo->arestas[vertice][i]] = cont;
			}
		}
	}

	free(fila);
}
