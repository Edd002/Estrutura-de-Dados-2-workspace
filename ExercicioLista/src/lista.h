/*
 * Lista.h
 *
 *  Created on: 11 de set de 2020
 *      Author:
 */

#ifndef LISTA_H_
#define LISTA_H_

typedef struct CELULA_TAG* PONT;

typedef struct {
	int linha, coluna;
	double valor;
} ITEM;

typedef struct CELULA_TAG {
	ITEM item;
	PONT direita;
	PONT abaixo;
} CELULA;

typedef struct {
	PONT inicio;
	PONT fimLinha;
	PONT fimColuna;
} LISTA;

#endif /* LISTA_H_ */
