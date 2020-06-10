/*
 * TabelaHash.h
 *
 *  Created on: 12 de nov de 2018
 *      Author: n226804875
 */

#ifndef TABELAHASH_H_
#define TABELAHASH_H_

#define TAM_TABELA 997
#define TAM_CHAVE 20
#define VAZIO "---------------------"
#define RETIRADO "*********************"

typedef char CHAVE[TAM_CHAVE + 1];

typedef struct structItem {
	CHAVE nome;
	double preco;
} ITEM;

typedef ITEM HASH[TAM_TABELA];


void criaHash(HASH);
int h(CHAVE);

void carregaDadosHashArvoreRedBlack(HASH);
int buscaHashArvoreRedBlack(HASH, CHAVE, ITEM*);
int insereHashArvoreRedBlack(HASH, ITEM);
int removeHashArvoreRedBlack(HASH, CHAVE, ITEM*);
int alteraHashArvoreRedBlack(HASH, CHAVE, ITEM*);

#endif /* TABELAHASH_H_ */
