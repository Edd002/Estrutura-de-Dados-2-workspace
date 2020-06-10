/*
 * TabelaHash.c
 *
 *  Created on: 11 de out de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "ListaEncadeada.h"
#include "ArvoreBinaria.h"

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


// -- Endereço Aberto --

void carregaDadosHashEnderecoAberto(HASH hash) {
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

	printf("-- INSERÇÃO NA TABELA HASH --\n\n");
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
			printf("[%s] [%lf] < Inseriu? %i\n", item->nome, item->preco, insereHashEnderecoAberto(hash, *item));
			free(item);
			item = (ITEM*) malloc(sizeof(ITEM));
		}

		temp[i] = c;
		i++;
	} while (!feof(file));

	printf("\nFim do arquivo. Tabela hash carregada.\n\n");
	fclose(file);
}

int buscaHashEnderecoAberto(HASH hash, CHAVE chave, ITEM* item) {
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

int insereHashEnderecoAberto(HASH hash, ITEM item) {
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

int removeHashEnderecoAberto(HASH hash, CHAVE chave, ITEM* item) {
	int i;

	i = buscaHashEnderecoAberto(hash, chave, item);
	if (i != -1) {
		memcpy(hash[i].nome, RETIRADO, sizeof(CHAVE));
		return 0;
	} else {
		return -1;
	}
}

int alteraHashEnderecoAberto(HASH hash, CHAVE chave, ITEM* item) {
	int i;
	ITEM itemAntigo;

	i = buscaHashEnderecoAberto(hash, chave, &itemAntigo);
	if (i != -1) {
		strncpy(item->nome, itemAntigo.nome, TAM_CHAVE);
		hash[i].preco = item->preco;
		return 0;
	} else {
		return -1;
	}
}

// ------------------------------------------------------------------------------------


// -- Lista Encadeada --

void carregaDadosHashListaEncadeada(HASH hash) {
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

	printf("-- INSERÇÃO NA TABELA HASH --\n\n");
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
			printf("[%s] [%lf] < Inseriu? %i\n", item->nome, item->preco, insereHashListaEncadeada(hash, *item));
			free(item);
			item = (ITEM*) malloc(sizeof(ITEM));
		}

		temp[i] = c;
		i++;
	} while (!feof(file));

	printf("\nFim do arquivo. Tabela hash carregada.\n\n");
	fclose(file);
}

int buscaHashListaEncadeada(HASH hash, CHAVE chave, ITEM* item) {
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

int insereHashListaEncadeada(HASH hash, ITEM item) {
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

int removeHashListaEncadeada(HASH hash, CHAVE chave, ITEM* item) {
	int i;

	i = buscaHashEnderecoAberto(hash, chave, item);
	if (i != -1) {
		memcpy(hash[i].nome, RETIRADO, sizeof(CHAVE));
		return 0;
	} else {
		return -1;
	}
}

int alteraHashListaEncadeada(HASH hash, CHAVE chave, ITEM* item) {
	int i;
	ITEM itemAntigo;

	i = buscaHashEnderecoAberto(hash, chave, &itemAntigo);
	if (i != -1) {
		strncpy(item->nome, itemAntigo.nome, TAM_CHAVE);
		hash[i].preco = item->preco;
		return 0;
	} else {
		return -1;
	}
}

// ------------------------------------------------------------------------------------


// -- Árvore Binária --

void carregaDadosHashArvoreBinaria(HASH hash) {
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

	printf("-- INSERÇÃO NA TABELA HASH --\n\n");
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
			printf("[%s] [%lf] < Inseriu? %i\n", item->nome, item->preco, insereHashArvoreBinaria(hash, *item));
			free(item);
			item = (ITEM*) malloc(sizeof(ITEM));
		}

		temp[i] = c;
		i++;
	} while (!feof(file));

	printf("\nFim do arquivo. Tabela hash carregada.\n\n");
	fclose(file);
}

int buscaHashArvoreBinaria(HASH hash, CHAVE chave, ITEM* item) {
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

int insereHashArvoreBinaria(HASH hash, ITEM item) {
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

int removeHashArvoreBinaria(HASH hash, CHAVE chave, ITEM* item) {
	int i;

	i = buscaHashEnderecoAberto(hash, chave, item);
	if (i != -1) {
		memcpy(hash[i].nome, RETIRADO, sizeof(CHAVE));
		return 0;
	} else {
		return -1;
	}
}

int alteraHashArvoreBinaria(HASH hash, CHAVE chave, ITEM* item) {
	int i;
	ITEM itemAntigo;

	i = buscaHashEnderecoAberto(hash, chave, &itemAntigo);
	if (i != -1) {
		strncpy(item->nome, itemAntigo.nome, TAM_CHAVE);
		hash[i].preco = item->preco;
		return 0;
	} else {
		return -1;
	}
}

// ------------------------------------------------------------------------------------
