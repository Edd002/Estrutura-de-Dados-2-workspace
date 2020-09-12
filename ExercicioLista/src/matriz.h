/*
 * matriz.h
 *
 *  Created on: 12 de set de 2020
 *      Author:
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "lista.h"

typedef struct {
    int nLinhas, nColunas;
    LISTA* lista;
} MATRIZ;

typedef MATRIZ MATRIZ_ESPARSA;

MATRIZ_ESPARSA* leMatriz(char*);
MATRIZ_ESPARSA* criaMatriz(int, int);
int iniciaCabecas(MATRIZ_ESPARSA*);
int insereCabecaLinha(MATRIZ_ESPARSA*);
int insereCabecaColuna(MATRIZ_ESPARSA*);

int insereMatriz(MATRIZ_ESPARSA*, int, int, float);
int imprimeMatriz(MATRIZ_ESPARSA*);
MATRIZ_ESPARSA* somaMatriz(MATRIZ_ESPARSA*, MATRIZ_ESPARSA*);
MATRIZ_ESPARSA* multiplicaMatriz(MATRIZ_ESPARSA*, MATRIZ_ESPARSA*);
int apagaMatriz(MATRIZ_ESPARSA*);

float obterElementoPeloIndice(MATRIZ_ESPARSA*, int, int);

#endif /* MATRIZ_H_ */
