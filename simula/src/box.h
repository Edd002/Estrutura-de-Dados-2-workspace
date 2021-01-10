/*
 * box.h
 *
 *  Created on: 5 de nov de 2020
 *      Author:
 */

#ifndef BOX_H_
#define BOX_H_

#include "fila.h"

// A cada box (ou atendente) está associada uma fila de espera
typedef struct structBox {
	int numeroBox;
	CLIENTE* clienteNoBox;
	FILA* filaEsperaClientes;
} BOX;

#endif /* BOX_H_ */
