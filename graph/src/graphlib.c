/*
 * graphlib.c
 *
 *  Created on: 19 de nov de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "graphlib.h"

// -- AUXILIARY/GENERIC FUNCTIONS --
void print_err(char* error) {
	printf("\n%s\n", error);
	exit(1);
}

void scan_str(char** string) {
	int i;
	for(i = 0; 1; i++) {
		if(i)
			*string = (char*) realloc((*string), i + 1);
		else
			*string = (char*) malloc(i + 1);

		(*string)[i] = getchar();
		if((*string)[i] == '\n') {
			(*string)[i] = '\0';
			break;
		}
	}
}

void replacefirstoccurrence_str(char* str, char* org, char* rep) {
	char* to_rep = strstr(str, org);
	char* rest = (char*) malloc(strlen(to_rep));
	strcpy(rest, ((to_rep) + strlen(org)));

	strcpy(to_rep, rep);
	strcat(to_rep, rest);

	free(rest);
}

char* remove_spaces(char* string) {
	int copy_from = 0, copy_to = 0;
	while (string[copy_to] != 0) {
		if (string[copy_from] == ' ') {
			string[copy_to] = string[copy_from];
			copy_from++;
			copy_to++;

			while ((string[copy_from] == ' ') && (string[copy_from] !='\0')) {
				copy_from++;
			}
		}

		string[copy_to] = string[copy_from];

		if (string[copy_to] != '\0') {
			copy_from++;
			copy_to++;
		}
	}

	if (string[0] == ' ') {
		string[0] = '\0';
		string++;
	}

	if (string[strlen(string) - 1] == ' ') {
		string[strlen(string) - 1] = '\0';
	}

	return string;
}

char* replaceall_words(char* string, char* old_word, char* new_word) {
	char *result;
	int i, count = 0;
	int new_wordlen = strlen(new_word);
	int old_wordlen = strlen(old_word);

	for (i = 0; string[i] != '\0'; i++) {
		if (strstr(&string[i], old_word) == &string[i]) {
			count++;
			i += old_wordlen - 1;
		}
	}

	result = (char*) malloc(i + count * (new_wordlen - old_wordlen) + 1);

	i = 0;
	while (*string) {
		if (strstr(string, old_word) == string) {
			strcpy(&result[i], new_word);
			i += new_wordlen;
			string += old_wordlen;
		} else {
			result[i++] = *string++;
		}
	}

	result[i] = '\0';
	return result;
}

char* read_str(char* message) {
	char* string = NULL;

	printf(message);
	fflush(stdin);
	scan_str(&string);

	return string;
}

char read_char(char* message) {
	char character = '\0';

	printf(message);
	fflush(stdin);
	scanf("%c", &character);

	return character;
}

int read_int(char* message) {
	int integer = 0;

	printf(message);
	fflush(stdin);
	scanf("%i", &integer);

	return integer;
}

int count_words(char* string) {
	int str_tam, i, in_word = 0, num_words = 0;

	str_tam = strlen(string);
	for (i = 0; i <= str_tam; i++) {
		if (isalnum(string[i]))
			in_word = 1;
		else if (in_word) {
			in_word = 0;
			num_words++;
		}
	}

	return num_words;
}


// -- MAIN FUNCTIONS --
void init() {
	printf("--------------------------------------------------------------\n");
	printf("TRABALHO SOBRE GRAFOS - AUTOINSTRUCIONAL DE MATEMÁTICA DISCRETA - QUESTÃO NÚMERO 2");
	printf("\n--------------------------------------------------------------");

	//Exemplo: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
	char* string = read_str(
			"\nInforme uma sequêcia de números inteiros separados por espaço."
			"\nOs números representam os vértices e os espaços as arestas:\n"
	);

	if (string == NULL || (int)(strlen(string)) == 0) {
		print_err("Erro na execução: entrada nula ou vazia.");
	} else {
		show_strgraph(string);

		char opcao = read_char(
				"\nInforme:\n"
				"1 para visualizar a matriz de incidência\n"
				"2 para visualizar a matriz de adjacência\n"
				"3 para computar o grau de um vértice\n"
				"4 para visualizar a representação em conjuntos do grafo\n"
		);

		int i;
		int num_vert = count_words(string);
		int M = num_vert + 1;
		int N = num_vert + 1;
		int** arr = (int**) calloc(M, sizeof(int*));
		for (i = 0; i < M; i++)
			arr[i] = (int*) calloc(N, sizeof(int));

		if (opcao == '1') {
			convertto_incmatr(string, arr, num_vert);
			print_incmatr(arr, M, N);
		} else if (opcao == '2') {
			convertto_adjmatr(string, arr, num_vert);
			print_adjmatr(arr, M, N);
		} else if (opcao == '3') {
			convertto_incmatr(string, arr, num_vert);
			print_incmatr(arr, M, N);
			compute_degree(arr, num_vert);
		} else if (opcao == '4') {
			convertto_adjmatr(string, arr, num_vert);
			print_adjmatr(arr, M, N);
			print_graphsetrepresentation(arr, num_vert);
		} else {
			print_err("Erro na execução: opção escolhida inválida.");
		}
	}

	free(string);
}

void show_strgraph(char* string) {
	char* string_graph = (char*) malloc(((int) strlen(string)) * sizeof(char) * 4);
	strcpy(string_graph, string);

	strcpy(string_graph, remove_spaces(string_graph));
	strcpy(string_graph, replaceall_words(string_graph, " ", "<AX>"));

	int i = 0;
	int edge_count = 0;
	int len = (int) strlen(string_graph);
	while (string_graph[i] != '\0') {
		if (string_graph[i] == 'A') {
			char edge_string[len];
			char aux[len];

			itoa(edge_count, edge_string, 10);
			strcpy(aux, "<A");
			strcat(aux, edge_string);
			strcat(aux, ">");

			replacefirstoccurrence_str(string_graph, "<AX>", aux);
			edge_count++;
		}
		i++;
	}

	printf("\nRepresentação do grafo (<AX> representam arestas): \n%s\n", string_graph);
	free(string_graph);
}

void convertto_incmatr(char* string, int** arr, int num_vert) {
	printf("\n-- Matriz de Incidência --");

	int i, j;
	for (i = 0; i < num_vert; i++) {
		int n, cont;

		cont = sscanf(string, "%i %n", &arr[0][i + 1], &n);
		cont = sscanf(string, "%i %n", &arr[i + 1][0], &n);

		if (cont != 1)
			break;

		string += n;
	}
	for (i = 0; i <= num_vert; i++) {
		for (j = 0; j <= num_vert; j++) {
			if (i != 0 && j != 0)
				if (i == j || j == i - 1)
					arr[i][j] = 1;
		}
	}
}

void print_incmatr(int** matr, int M, int N) {
	int i, j;

	printf("\n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (i == 0 && j > 0 && j < (N - 1)) {
				printf("A%i\t", (j - 1));
			} else {
				if (j < (N - 1))
					printf("%i\t", matr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void convertto_adjmatr(char* string, int** arr, int num_vert) {
	printf("\n-- Matriz de Adjacência --");

	int i, j;
	for (i = 0; i < num_vert; i++) {
		int n, cont;

		cont = sscanf(string, "%i %n", &arr[0][i + 1], &n);
		cont = sscanf(string, "%i %n", &arr[i + 1][0], &n);

		if (cont != 1)
			break;

		string += n;
	}
	for (i = 0; i <= num_vert; i++) {
		for (j = 0; j <= num_vert; j++) {
			if(i != 0 && j != 0)
				if (i == j + 1 || j == i + 1)
					arr[i][j] = 1;
		}
	}
}

void print_adjmatr(int** arr, int M, int N) {
	int i, j;

	printf("\n");
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%i\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void compute_degree(int** arr, int num_vert) {
	printf("-- Computar Grau --");

	int vert_searched = read_int("\nInforme um vértice para computar seu grau: ");

	int i, grau = 0;
	if ((arr[1][0] == vert_searched || arr[num_vert][0] == vert_searched)) {
		grau = 1;
	} else {
		for (i = 0; i <= num_vert; i++) {
			if (arr[i][0] == vert_searched) {
				grau = 2;
				break;
			}
		}
	}

	if (grau == 0) {
		printf("\nVértice não encontrado no grafo.\n");
	} else {
		if (num_vert == 1)
			printf("\nO grau do vértice %i é: 0\n", vert_searched);
		else
			printf("\nO grau do vértice %i é: %i\n", vert_searched, grau);
	}
}

void print_graphsetrepresentation(int** arr, int num_vert) {
	printf("-- Representação em Conjunto de Grafos --");

	int i;
	int lenstr_graphset = num_vert * 9 * sizeof(char) + 15;
	char* string_graphset = (char*) malloc(lenstr_graphset);

	strcpy(string_graphset, "G(V,A) = {V = {");
	for (i = 1; i <= num_vert; i++) {
		char str_vert[lenstr_graphset];
		itoa(arr[i][0], str_vert, 10);

		strcat(string_graphset, str_vert);
		if (i != num_vert)
			strcat(string_graphset, ",");
	}
	strcat(string_graphset, "}, A = {{");

	for (i = 1; i < num_vert; i++) {
		char str_vert1[lenstr_graphset];
		itoa(arr[i][0], str_vert1, 10);
		strcat(string_graphset, str_vert1);
		strcat(string_graphset, ",");

		char str_vert2[lenstr_graphset];
		itoa(arr[i + 1][0], str_vert2, 10);
		strcat(string_graphset, str_vert2);
		if(i != (num_vert - 1))
			strcat(string_graphset, "},{");
	}
	strcat(string_graphset, "}}}");

	// Exemplo de Saída: G(V,A) = {V = {1,2,3,4,5,6,7,8,9}, A = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9}}}
	printf("\nConjunto: %s\n", string_graphset);
}
