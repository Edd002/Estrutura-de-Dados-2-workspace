/*
 * simlib.h
 *
 *  Created on: 4 de nov de 2020
 *      Author:
 */

#ifndef SIMLIB_H_
#define SIMLIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include "boollib.h"
#include "box.h"
#include "fila.h"
#include "lista.h"
#include "randomico.h"

int _numeroFilas;
int _tempoTotal;
int _tempoChegada;
int _tempoOperacao;
int _semente;

int _proxChegada;
int _finalAtendimento;
bool _exibicaoTempoOcorrida;

int _somatorioClientesAtendidos;
int _somatorioTempoPermanenciaFila;
int _somatorioTempoPermanenciaEstabelecimento;

void verificarArgumentos(int, char**);
bool ehInteiro(char*);
bool ehPositivo(int);

void simularEventos();
void verificarFinalAtendimentoClientes(BOX*, int, int, LISTA**);
BOX* criarBoxes();
BOX* buscarBoxDesocupadoOuMenorFila(BOX*);
void entrarBoxDesocupadoOuMenorFila(BOX*, CLIENTE*, int, LISTA**);
void desocuparBoxEAtenderProximoCliente(BOX*, int, LISTA**);

void exibirErro();
void exibirEntradas();
void exibirEventos();
void exibirTempoAtual(int);
void exibirChegadaCliente(int, int, int);
void exibirInicioAtendimento(int, int, int);
void exibirFinalAtendimento(int, int, int, int);
void exibirResultados(int, float, float);

#endif /* LCLIB_H_ */
