/*
 * cliente.h
 *
 *  Created on: 7 de nov de 2020
 *      Author:
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct structCliente {
	int numeroCliente;
	int numeroBox; // N�mero do box que o cliente ser� atendido
	int instanteEntradaFila; // (Instante de Chegada)
	int instanteSaidaFila; // (In�cio de Atendimento)
	int instanteSaidaEstabelecimento; // (Final de Atendimento)
} CLIENTE;

#endif /* CLIENTE_H_ */
