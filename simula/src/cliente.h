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
	int numeroBox; // Número do box que o cliente será atendido
	int instanteEntradaFila; // (Instante de Chegada)
	int instanteSaidaFila; // (Início de Atendimento)
	int instanteSaidaEstabelecimento; // (Final de Atendimento)
} CLIENTE;

#endif /* CLIENTE_H_ */
