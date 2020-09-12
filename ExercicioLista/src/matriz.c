/*
 * matriz.c
 *
 *  Created on: 12 de set de 2020
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "matriz.h"

MATRIZ_ESPARSA* leMatriz(char* nomeArquivo) {
	MATRIZ_ESPARSA* matriz;

	char linha[255];

	int nLinhas = 0, nColunas = 0;
	int linhas = 0, colunas = 0;
	float valor = 0.0;

	FILE* arquivo;

	arquivo = fopen(nomeArquivo, "r");
	if (!arquivo) {
		arquivo = fopen("arquivo.txt", "w");
		fprintf(arquivo, "Erro ao abrir arquivo\n");
		fclose(arquivo);
		return NULL;
	}

	fgets(linha, 255, arquivo);
	sscanf(linha, "%d %d", &nLinhas, &nColunas);

	if (nLinhas <= 0 || nColunas <= 0)
		return 0;

	matriz = criaMatriz(nLinhas, nColunas);

	while(fgets(linha, 255, arquivo)){
		sscanf(linha, "%d %d %f", &linhas, &colunas, &valor);
		if (valor)
			insereMatriz(matriz, linhas, colunas, valor);
	}

	fclose(arquivo);
	return matriz;
}

MATRIZ_ESPARSA* criaMatriz(int linhas, int colunas) {
	MATRIZ_ESPARSA* mat;
	mat = (MATRIZ_ESPARSA*) malloc(sizeof(MATRIZ_ESPARSA));
	mat->lista = (LISTA*) malloc(sizeof(LISTA));

	if (!mat || linhas <= 0 || colunas <= 0)
		return 0;

	mat->lista->inicio = NULL;
	mat->lista->fimLinha = NULL;
	mat->lista->fimColuna = NULL;
	mat->nLinhas = linhas;
	mat->nColunas = colunas;

	iniciaCabecas(mat);

	return mat;
}

int iniciaCabecas(MATRIZ_ESPARSA* mat){
	int i = 0;

	CELULA *cabeca;
	cabeca = (CELULA*) malloc(sizeof(CELULA));

	if (!cabeca)
		return 0;

	cabeca->item.coluna = -1;
	cabeca->item.linha = -1;

	mat->lista->inicio = cabeca;
	mat->lista->fimLinha = cabeca;
	mat->lista->fimColuna = cabeca;

	for (i = 1; i <= mat->nColunas; i++)
		insereCabecaColuna(mat);

	for (i = 1; i <= mat->nLinhas; i++)
		insereCabecaLinha(mat);

	return 1;
}

int insereCabecaColuna(MATRIZ_ESPARSA* mat) {
	CELULA *cabeca;
	cabeca = (CELULA*) malloc(sizeof(CELULA));

	if (!cabeca)
		return 0;

	cabeca->item.coluna = -1;
	cabeca->item.linha = 0;

	mat->lista->fimColuna->direita = cabeca;
	mat->lista->fimColuna = cabeca;

	cabeca->direita = mat->lista->inicio;
	cabeca->abaixo = cabeca;

	return 1;
}

int insereCabecaLinha(MATRIZ_ESPARSA* mat) {
	CELULA *cabeca;
	cabeca = (CELULA*)malloc(sizeof(CELULA));

	if (!cabeca)
		return 0;

	cabeca->item.coluna = 0;
	cabeca->item.linha = -1;

	mat->lista->fimLinha->abaixo = cabeca;
	mat->lista->fimLinha = cabeca;

	cabeca->abaixo = mat->lista->inicio;
	cabeca->direita = cabeca;

	return 1;
}

int insereMatriz(MATRIZ_ESPARSA *mat, int linha, int coluna, float valor){
	int i;

	if (!mat || mat->nLinhas <= 0 || mat->nColunas <= 0 || !valor)
		return 0;

	if (linha>mat->nLinhas || coluna>mat->nColunas || !valor || linha < 1 || coluna < 1)
		return 0;


	CELULA *pCelula;
	CELULA *pCelulaColuna;
	CELULA *pCelulaLinha;

	pCelula = (CELULA*) malloc(sizeof(CELULA));

	if (!pCelula)
		return 0;

	pCelula->item.linha = linha;
	pCelula->item.coluna = coluna;
	pCelula->item.valor = valor;

	pCelulaLinha = mat->lista->inicio->abaixo;
	pCelulaColuna = mat->lista->inicio->direita;


	for (i = 0; i < linha-1; i++)
		pCelulaLinha = pCelulaLinha->abaixo;

	i = 0;
	while (i < coluna && pCelulaLinha->direita->item.linha != -1) {
		if (pCelulaLinha->direita->item.coluna > pCelula->item.coluna) {
			pCelula->direita = pCelulaLinha->direita;
			pCelulaLinha->direita = pCelula;
		} else {
			pCelulaLinha = pCelulaLinha->direita;
		}
		i++;
	}
	if (pCelulaLinha->direita->item.linha == -1) {
		pCelula->direita = pCelulaLinha->direita;
		pCelulaLinha->direita = pCelula;
	}

	for (i = 0; i < coluna-1; i++)
		pCelulaColuna = pCelulaColuna->direita;

	i = 0;
	while (i<linha && pCelulaColuna->abaixo->item.coluna != -1) {
		if (pCelulaColuna->abaixo->item.linha > pCelula->item.linha) {
			pCelula->abaixo = pCelulaColuna->abaixo;
			pCelulaColuna->abaixo = pCelula;
		}  else {
			pCelulaColuna = pCelulaColuna->abaixo;
		}
		i++;
	}
	if (pCelulaColuna->abaixo->item.coluna == -1) {
		pCelula->abaixo = pCelulaColuna->abaixo;
		pCelulaColuna->abaixo = pCelula;
	}
	return 1;
}

int imprimeMatriz(MATRIZ_ESPARSA* mat) {
	int i, j;
	CELULA* pCelula;

	if (!mat || !mat->nLinhas || !mat->nColunas)
		return 0;

	pCelula = mat->lista->inicio->abaixo;

	printf("\n");

	for (i = 1; i <= mat->nLinhas; i++) {
		for (j = 1; j <= mat->nColunas; j++) {
			if (pCelula->direita->item.linha == i && pCelula->direita->item.coluna == j) {
				pCelula = pCelula->direita;
				printf("  \t%0.2f   ", pCelula->item.valor);
			} else {
				printf("  \t%0.2f   ", 0.0F);
			}
		}
		printf("\n");
		pCelula = pCelula->direita->abaixo;
	}

	return 1;
}

int apagaMatriz(MATRIZ_ESPARSA* mat){
	int i = 1;
	int j = 1;
	CELULA *pCelula, *aux;

	if (!mat || !mat->nLinhas || !mat->nColunas)
		return 0;

	pCelula = mat->lista->inicio->abaixo;
	pCelula = pCelula->direita;

	for (i = 1; i <= mat->nLinhas; i++) {
		for (j = 1; j <= mat->nColunas; j++) {
			if (pCelula->item.linha == i && pCelula->item.coluna == j) {
				aux = pCelula;
				pCelula = pCelula->direita;
				free(aux);
			}
		}
		pCelula = pCelula->abaixo->direita;
	}

	pCelula = mat->lista->inicio->direita;
	for (i = 0; i < mat->nColunas; i++){
		aux = pCelula;
		pCelula = pCelula->direita;
		free(aux);
	}

	pCelula = mat->lista->inicio->abaixo;
	for (i = 0; i < mat->nLinhas; i++){
		aux = pCelula;
		pCelula = pCelula->abaixo;
		free(aux);
	}

	pCelula = mat->lista->inicio;
	free(pCelula);

	mat->lista->fimColuna = mat->lista->fimLinha = mat->lista->inicio = NULL;
	mat->nLinhas = mat->nColunas = 0;
	mat = NULL;

	return 1;
}

MATRIZ_ESPARSA* somaMatriz(MATRIZ_ESPARSA* matA, MATRIZ_ESPARSA* matB) {
	int i, j;
	float soma;
	MATRIZ_ESPARSA *matC;
	CELULA *pCelulaA, *pCelulaB;

	if (matA->nLinhas != matB->nLinhas || matA->nColunas != matB->nColunas){
		printf("\nMatrizes de Ordem diferente.\nSo eh possivel somar matrizes de mesma ordem\n");
		return NULL;
	}

	if (!matA || !matB || !matA->nLinhas || !matA->nColunas)
		return NULL;

	matC = criaMatriz(matA->nLinhas, matB->nColunas);

	pCelulaA = matA->lista->inicio->abaixo;
	pCelulaB = matB->lista->inicio->abaixo;

	for (i = 1; i <= matA->nLinhas; i++) {
		for (j = 1; j <= matA->nColunas; j++) {
			if (j == pCelulaA->direita->item.coluna && j == pCelulaB->direita->item.coluna) {
				soma = pCelulaA->direita->item.valor + pCelulaB->direita->item.valor;
				if (soma)
					insereMatriz(matC, i, j, soma);

				pCelulaA = pCelulaA->direita;
				pCelulaB = pCelulaB->direita;
			} else if (j == pCelulaA->direita->item.coluna) {
				insereMatriz(matC, i, j, pCelulaA->direita->item.valor);
				pCelulaA = pCelulaA->direita;
			} else if (j == pCelulaB->direita->item.coluna) {
				insereMatriz(matC, i, j, pCelulaB->direita->item.valor);
				pCelulaB = pCelulaB->direita;
			}
		}
		pCelulaA = pCelulaA->direita->abaixo;
		pCelulaB = pCelulaB->direita->abaixo;
	}

	return matC;
}

MATRIZ_ESPARSA* multiplicaMatriz(MATRIZ_ESPARSA *matA, MATRIZ_ESPARSA *matB){
	int i = 0, j = 0, k = 0;
	float total;
	MATRIZ_ESPARSA *matC;

	if (matA->nColunas != matB->nLinhas) {
		printf("\nNao foi possivel multiplicar as matrizes\nnumero de colunas de A eh diferente do numero de linhas de B\n");
		return NULL;
	}

	if (!matA || !matB || !matA->nLinhas || !matA->nColunas || !matB->nColunas)
		return NULL;

	matC = criaMatriz(matA->nLinhas, matB->nColunas);

	for (i = 1; i <= matA->nLinhas; i++) {
		for (j = 1; j <= matB->nColunas; j++) {
			total = 0;
			for (k = 1; k <= matA->nColunas; k++)
				total += obterElementoPeloIndice(matA, i, k) * obterElementoPeloIndice(matB, k, j);

			if (total)
				insereMatriz(matC, i, j, total);
		}
	}
	return matC;
}

float obterElementoPeloIndice(MATRIZ_ESPARSA* mat, int linha, int coluna){
	CELULA* pCelula;
	int i = 0;

	pCelula = mat->lista->inicio->direita;

	for (i = 0; i < coluna-1; i++)
		pCelula = pCelula->direita;

	do {
		pCelula = pCelula->abaixo;
		if (pCelula->item.linha == linha)
			return pCelula->item.valor;
	} while(pCelula->item.coluna != -1);

	return 0;
}
