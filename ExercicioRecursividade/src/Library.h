/*
 * Library.h
 *
 *  Created on: 9 de ago de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

int aquecimentoQuestao1Tail(int, int);
int aquecimentoQuestao1Peel(int);

void aquecimentoQuestao2Tail(int, int, int, int);
void aquecimentoQuestao2Peel(int, int);

int aquecimentoQuestao3RecursivaTail(int, int, int);
void aquecimentoQuestao3RecursivaPeel(int);
void aquecimentoQuestao3IterativaTail(int);
void aquecimentoQuestao3IterativaPeel(int);

char* entregaQuestao1Questao2Tail(char*, char*, int, int);
void entregaQuestao1Peel(char*);
void entregaQuestao2Peel(char*);

void entregaQuestao3(unsigned int);

char* entregaQuestao3Tail(unsigned int, char*);
void entregaQuestao3Peel(unsigned int);

int entregaQuestao4ATail(int*, int, int, int);
void entregaQuestao4APeel(int*, int);

int entregaQuestao4BTail(int*, int*, int, int, int, int, int, int);
void entregaQuestao4BPeel(int*, int*, int, int);

int entregaQuestao5Iterativa(int*, int, int);
void entregaQuestao5IterativaPeel(int*, int, int);

int entregaQuestao5Tail(int*, int, int, int);
void entregaQuestao5RecursivaPeel(int*, int, int);

#endif /* LIBRARY_H_ */
