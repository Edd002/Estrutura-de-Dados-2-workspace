/*
 * TabelaHash.c
 *
 *  Created on: 12 de nov de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "TabelaHash.h"
#include "ArvoreRedBlack.h"

void criaHash(HASH hash) {
	int i;

	for (i = 0; i < TAM_TABELA; i++)
		strcpy(hash[i].nome, VAZIO);
}

int h(CHAVE chave) {
	if (chave == NULL)
		return 0;

	int pos = 0;
	while (*chave != '\0') {
		char caracter = *chave++;
		int inteiro = caracter - '0';
		pos = (pos * 10) + inteiro;
	}

	return pos;
}

void carregaDadosHashArvoreRedBlack(HASH hash) {
	FILE *file;
	file = fopen("file.txt", "rb");

	if (file == NULL) {
		printf("Erro na abertura do arquivo.\n");
		system("pause");
		exit(1);
	}

	ITEM* item = (ITEM*) malloc(sizeof(ITEM));
	int i = 0;
	char temp[21];
	char c;

	printf("\n\n-- INSERÇÃO NA TABELA HASH --\n\n");
	do {
		c = fgetc(file);

		if (c == ' ') {
			if (temp[0] == '\n')
				memmove(temp, temp + 1, strlen(temp));

			strcpy(item->nome, temp);
		}

		if (c == '\n' || feof(file)) {
			item->preco = atof(temp);
		}

		if (c == ' ' || c == '\n') {
			memset(temp, 0, strlen(temp));
			i = 0;
		}

		if (c == '\n' || feof(file)) {
			printf("[%s] [%lf] < Inseriu? %i\n", item->nome, item->preco, insereHashArvoreRedBlack(hash, *item));
			free(item);
			item = (ITEM*) malloc(sizeof(ITEM));
		}

		temp[i] = c;
		i++;
	} while (!feof(file));

	printf("\nFim do arquivo. Tabela hash carregada.\n\n");
	fclose(file);
}

int buscaHashArvoreRedBlack(HASH hash, CHAVE chave, ITEM* item) {
	int i, inicial;

	inicial = h(chave);
	i = 0;
	while ((strncmp(hash[(inicial + i) % TAM_TABELA].nome, VAZIO, TAM_CHAVE))
			&& (strncmp(hash[(inicial + i) % TAM_TABELA].nome, chave, TAM_CHAVE))
			&& (i < TAM_TABELA)) i++;

	if (!strncmp(hash[(inicial + i) % TAM_TABELA].nome, chave, TAM_CHAVE)) {
		*item = hash[(inicial + i) % TAM_TABELA];
		return ((inicial + i) % TAM_TABELA);
	} else {
		return -1;
	}
}

int insereHashArvoreRedBlack(HASH hash, ITEM item) {
	int i, inicial;

	inicial = h(item.nome);
	i = 0;
	while ((strncmp(hash[(inicial + i) % TAM_TABELA].nome, VAZIO, TAM_CHAVE))
			&& (strncmp(hash[(inicial + i) % TAM_TABELA].nome, RETIRADO, TAM_CHAVE))
			&& (i < TAM_TABELA)) i++;

	if (i < TAM_TABELA) {
		hash[(inicial + i) % TAM_TABELA] = item;
		return ((inicial + i) % TAM_TABELA);
	} else {
		return -1;
	}
}

int removeHashArvoreRedBlack(HASH hash, CHAVE chave, ITEM* item) {
	int i;

	i = buscaHashArvoreRedBlack(hash, chave, item);
	if (i != -1) {
		memcpy(hash[i].nome, RETIRADO, sizeof(CHAVE));
		return 0;
	} else {
		return -1;
	}
}

int alteraHashArvoreRedBlack(HASH hash, CHAVE chave, ITEM* item) {
	int i;
	ITEM itemAntigo;

	i = buscaHashArvoreRedBlack(hash, chave, &itemAntigo);
	if (i != -1) {
		strncpy(item->nome, itemAntigo.nome, TAM_CHAVE);
		hash[i].preco = item->preco;
		return 0;
	} else {
		return -1;
	}
}
