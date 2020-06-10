/*
 ============================================================================
 Name        : Lab04ExercicioTabelaHash.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TabelaHash.h"

void menu();
void tabelaHashEnderecoAberto();
void tabelaHashListaEncadeada();
void tabelaHashArvoreBinaria();

int main(void) {
	setbuf(stdout, NULL);
	menu();
	puts("\n\n\nFIM DO PROGRAMA.");
	return EXIT_SUCCESS;
}

void menu() {
	char opcao = '\0';

	do {
		printf("DICIONÁRIO - TABELA HASH\n");
		printf("Informe 1 para tabela hash por endereçamento aberto\n"
				"Informe 2 para tabela hash por lista encadeada\n"
				"Informe 3 para tabela hash por árvore binária\n");
		fflush(stdin);
		scanf("%c", &opcao);

		if (opcao != '1' && opcao != '2' && opcao != '3')
			printf("Opção escolhida inválida.\n\n");
	} while (opcao != '1' && opcao != '2' && opcao != '3');

	if (opcao == '1')
		tabelaHashEnderecoAberto();
	else if (opcao == '2')
		tabelaHashListaEncadeada();
	else if (opcao == '3')
		tabelaHashArvoreBinaria();
}

void tabelaHashEnderecoAberto() {
	printf("\n\nTABELA HASH POR ENDEREÇAMENTO ABERTO\n\n");

	HASH hash;
	criaHash(hash);
	carregaDadosHashEnderecoAberto(hash);

	char opcao = '\0';
	do {
		printf("\nInforme A para remover um item do dicionário\n"
				"Informe B para buscar o preço de um item pelo nome\n"
				"Informe C para alterar o preço de um item\n"
				"Informe D para sair\n");
		fflush(stdin);
		scanf("%c", &opcao);
		opcao = toupper(opcao);

		if (opcao != 'A' && opcao != 'B' && opcao != 'C' && opcao != 'D')
			printf("Opção escolhida inválida.\n\n");

		if (opcao == 'A') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser removido: ");
			fflush(stdin);
			gets(nome);

			int remove = removeHashEnderecoAberto(hash, nome, &item);
			if (remove == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem excluído: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'B') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser buscado: ");
			fflush(stdin);
			gets(nome);

			int busca = buscaHashEnderecoAberto(hash, nome, &item);
			if (busca == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem pesquisado: \nPosição: %i\nNome: %s\nPreço: %lf\n", busca, item.nome, item.preco);
		} else if (opcao == 'C') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser alterado: ");
			fflush(stdin);
			gets(nome);

			printf("\nInforme um novo preço para o item %s: ", nome);
			fflush(stdin);
			scanf("%lf", &item.preco);

			int altera = alteraHashEnderecoAberto(hash, nome, &item);
			if (altera == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem alterado: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'D') {
			break;
		}
	} while (1);
}

void tabelaHashListaEncadeada() {
	printf("\n\nTABELA HASH POR LISTA ENCADEADA");

	HASH hash;
	criaHash(hash);
	carregaDadosHashListaEncadeada(hash);

	char opcao = '\0';
	do {
		printf("\nInforme A para remover um item do dicionário\n"
				"Informe B para buscar o preço de um item pelo nome\n"
				"Informe C para alterar o preço de um item\n"
				"Informe D para sair\n");
		fflush(stdin);
		scanf("%c", &opcao);
		opcao = toupper(opcao);

		if (opcao != 'A' && opcao != 'B' && opcao != 'C' && opcao != 'D')
			printf("Opção escolhida inválida.\n\n");

		if (opcao == 'A') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser removido: ");
			fflush(stdin);
			gets(nome);

			int remove = removeHashListaEncadeada(hash, nome, &item);
			if (remove == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem excluído: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'B') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser buscado: ");
			fflush(stdin);
			gets(nome);

			int busca = buscaHashListaEncadeada(hash, nome, &item);
			if (busca == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem pesquisado: \nPosição: %i\nNome: %s\nPreço: %lf\n", busca, item.nome, item.preco);
		} else if (opcao == 'C') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser alterado: ");
			fflush(stdin);
			gets(nome);

			printf("\nInforme um novo preço para o item %s: ", nome);
			fflush(stdin);
			scanf("%lf", &item.preco);

			int altera = alteraHashListaEncadeada(hash, nome, &item);
			if (altera == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem alterado: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'D') {
			break;
		}
	} while (1);
}

void tabelaHashArvoreBinaria() {
	printf("\n\nTABELA HASH POR ÁRVORE BINÁRIA");

	printf("\n\nTABELA HASH POR LISTA ENCADEADA");

	HASH hash;
	criaHash(hash);
	carregaDadosHashArvoreBinaria(hash);

	char opcao = '\0';
	do {
		printf("\nInforme A para remover um item do dicionário\n"
				"Informe B para buscar o preço de um item pelo nome\n"
				"Informe C para alterar o preço de um item\n"
				"Informe D para sair\n");
		fflush(stdin);
		scanf("%c", &opcao);
		opcao = toupper(opcao);

		if (opcao != 'A' && opcao != 'B' && opcao != 'C' && opcao != 'D')
			printf("Opção escolhida inválida.\n\n");

		if (opcao == 'A') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser removido: ");
			fflush(stdin);
			gets(nome);

			int remove = removeHashArvoreBinaria(hash, nome, &item);
			if (remove == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem excluído: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'B') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser buscado: ");
			fflush(stdin);
			gets(nome);

			int busca = buscaHashArvoreBinaria(hash, nome, &item);
			if (busca == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem pesquisado: \nPosição: %i\nNome: %s\nPreço: %lf\n", busca, item.nome, item.preco);
		} else if (opcao == 'C') {
			char nome[TAM_CHAVE];
			ITEM item;

			printf("Informe o nome do item a ser alterado: ");
			fflush(stdin);
			gets(nome);

			printf("\nInforme um novo preço para o item %s: ", nome);
			fflush(stdin);
			scanf("%lf", &item.preco);

			int altera = alteraHashArvoreBinaria(hash, nome, &item);
			if (altera == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem alterado: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'D') {
			break;
		}
	} while (1);
}
