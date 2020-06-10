/*
 ============================================================================
 Name        : Lab05ExercicioArvoreRedBlack.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "TabelaHash.h"
#include "ArvoreRedBlack.h"

void tabelaHashArvoreRedBlack();

int main(void) {
	setbuf(stdout, NULL);
	tabelaHashArvoreRedBlack();
	printf("\n\n\nFIM DO PROGRAMA.");
	return EXIT_SUCCESS;
}

void tabelaHashArvoreRedBlack() {
	printf("TABELA HASH POR ÁRVORE RED BLACK");

	HASH hash;
	criaHash(hash);
	carregaDadosHashArvoreRedBlack(hash);

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

			int remove = removeHashArvoreRedBlack(hash, nome, &item);
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

			int busca = buscaHashArvoreRedBlack(hash, nome, &item);
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

			int altera = alteraHashArvoreRedBlack(hash, nome, &item);
			if (altera == -1)
				printf("\nItem não encontrado.\n");
			else
				printf("\nItem alterado: \nNome: %s\nPreço: %lf\n", item.nome, item.preco);
		} else if (opcao == 'D') {
			break;
		}
	} while (1);
}
