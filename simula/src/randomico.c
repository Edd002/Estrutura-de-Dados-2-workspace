/*
 * randomico.c
 *
 *  Created on: 4 de nov de 2020
 *      Author:
 */

#include "randomico.h"

#define SUPERIOR 1310171
#define VELOCIDADE 9806

unsigned randomico(unsigned anterior) {
	return ((unsigned long)VELOCIDADE * (unsigned long)anterior) % SUPERIOR + 1;
}

int chegada(int media, int semente) {
	static unsigned ultimoRandomico = 0;
	if (ultimoRandomico < 1)
		ultimoRandomico = semente;
	ultimoRandomico = randomico (ultimoRandomico);
	return (int) ceil(-media*log((double) ultimoRandomico / SUPERIOR));
}

int atendimento(int media, int semente) {
	static unsigned ultimoRandomico = 0;
	if (ultimoRandomico < 1)
		ultimoRandomico = semente;
	ultimoRandomico = randomico(ultimoRandomico);
	return (int)ceil(-media*log((double)ultimoRandomico / SUPERIOR));
}
