/*
 ============================================================================
 Name        : graph.c
 Author      : Eduardo Augusto Lima Pereira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "graphlib.h"

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");
	init();
	return EXIT_SUCCESS;
}

// Exemplo -> Entrada: 0 1 2 3 4 5
// [0 1 2 3 4 5], com espa輟 representando arestas -> [0<A0>1<A1>2<A2>3<A3>4<A4>5]
/*
 * Matriz de adjac麩cia: indica se possui uma liga鈬o direta entre os v駻tices
 *   || 0 | 1 | 2 | 3 | 4 | 5
 * 覧覧覧覧覧覧覧覧覧覧覧覧覧�
 * 0 || 0 | 1 | 0 | 0 | 0 | 0
 * ---------------------------
 * 1 || 1 | 0 | 1 | 0 | 0 | 0
 * ---------------------------
 * 2 || 0 | 1 | 0 | 1 | 0 | 0
 * ---------------------------
 * 3 || 0 | 0 | 1 | 0 | 1 | 0
 * ---------------------------
 * 4 || 0 | 0 | 0 | 1 | 0 | 1
 * ---------------------------
 * 5 || 0 | 0 | 0 | 0 | 1 | 0
 * */
/*
 * Matriz de incid麩cia: indica quais arestas o v駻tice possui
 *   || A0 | A1 | A2 | A3 | A4
 * 覧覧覧覧覧覧覧覧覧覧覧覧覧覧
 * 0 || 01 | 00 | 00 | 00 | 00
 * ----------------------------
 * 1 || 01 | 01 | 00 | 00 | 00
 * ----------------------------
 * 2 || 00 | 01 | 01 | 00 | 00
 * ----------------------------
 * 3 || 00 | 00 | 01 | 01 | 00
 * ----------------------------
 * 4 || 00 | 00 | 00 | 01 | 01
 * ----------------------------
 * 5 || 00 | 00 | 00 | 00 | 01
 * */
