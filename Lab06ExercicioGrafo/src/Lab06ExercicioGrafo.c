/*
 ============================================================================
 Name        : Lab06ExercicioGrafo.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LibGrafo.h"

int main(void) {
	setbuf(stdout, NULL);

	/*
	int ehDigrafo = 1;
	GRAFO* grafo = criarGrafo(5, 5, 0);

	inserirAresta(grafo, 0, 1, 0, 0);
	removerAresta(grafo, 0, 1, 0);

	inserirAresta(grafo, 0, 1, ehDigrafo, 0);
	inserirAresta(grafo, 1, 3, ehDigrafo, 0);
	inserirAresta(grafo, 1, 2, ehDigrafo, 0);
	inserirAresta(grafo, 2, 4, ehDigrafo, 0);
	inserirAresta(grafo, 3, 0, ehDigrafo, 0);
	inserirAresta(grafo, 3, 4, ehDigrafo, 0);
	inserirAresta(grafo, 4, 1, ehDigrafo, 0);
	int visitado[5];

	//buscaProfundidadeGrafo(grafo, 0, visitado);
	buscaLarguraGrafo(grafo, 0, visitado);
	liberarGrafo(grafo);
	 */

	int i, j, k, n, matrizAdj[10][10], aux[10], flag[10], count = 0;

	printf("Informe o número de vétices:\n");
	scanf("%d", &n);

	printf("Informando a matriz de adjacência:\n");
	for(i = 0; i < n; i++) {
		printf("Informe a linha %d\n",i+1);
		for(j = 0; j < n; j++)
			scanf("%d", &matrizAdj[i][j]);
	}

	for(i = 0; i < n; i++) {
		aux[i] = 0;
		flag[i] = 0;
	}

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			aux[i] = aux[i] + matrizAdj[j][i];

	printf("\nA ordem topológica é: ");
	while(count < n) {
		for(k = 0; k < n; k++) {
			if((aux[k] == 0) && (flag[k] == 0)){
				printf("%d ", (k + 1));
				flag[k] = 1;
			}

			for(i = 0; i < n; i++) {
				if(matrizAdj[i][k] == 1)
					aux[k]--;
			}
		}
		count++;
	}

	printf("\n\nFIM DO PROGRAMA.");

	return EXIT_SUCCESS;
}
