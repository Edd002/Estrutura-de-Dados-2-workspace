/*
 * simlib.c
 *
 *  Created on: 4 de nov de 2020
 *      Author:
 */

#include "simlib.h"

void verificarArgumentos(int argc, char** argv) {
	if (argc == 6) {
		int entradas[argc - 1];
		int i = 0;
		for (i = 1; i < argc; i++) {
			if (!ehInteiro(argv[i]))
				exibirErro();

			entradas[i] = atoi(argv[i]);
			if (!ehPositivo(entradas[i]))
				exibirErro();
		}
		exibirEntradas(argv);

		_numeroFilas = entradas[1];
		_tempoTotal = entradas[2];
		_tempoChegada = entradas[3];
		_tempoOperacao = entradas[4];
		_semente = entradas[5];

		simularEventos();
	} else {
		exibirErro();
	}
}

bool ehInteiro(char* texto) {
	int i;
	for (i = 0; i < strlen(texto); i++)
		if (texto[i] < 48 || texto[i] > 57)
			return false;
	return true;
}

bool ehPositivo(int inteiro) {
	return inteiro > 0 ? true : false;
}


// -- Funções de Operações --
void simularEventos() {
	BOX* boxes = criarBoxes();
	LISTA* listaClientesEmAtendimento = criarListaNulo();
	int tempoAtual = 0;
	int numeroCliente = 1;
	int contadorClientes = 0;
	_proxChegada = chegada(_tempoChegada, _semente);
	_finalAtendimento = 0;
	_somatorioTempoPermanenciaFila = 0;
	_somatorioTempoPermanenciaEstabelecimento = 0;
	_somatorioClientesAtendidos = 0;

	exibirEventos();
	while (tempoAtual <= _tempoTotal) {
		_exibicaoTempoOcorrida = false;

		if (tempoAtual == _proxChegada) {
			_proxChegada += chegada(_tempoChegada, _semente);

			CLIENTE* cliente = (CLIENTE*) malloc(sizeof(CLIENTE));
			cliente->numeroCliente = numeroCliente;
			entrarBoxDesocupadoOuMenorFila(boxes, cliente, tempoAtual, &listaClientesEmAtendimento);

			numeroCliente++;
			contadorClientes++;
		}

		// A cada iteração verificar se algum atendimento terminou
		verificarFinalAtendimentoClientes(boxes, tempoAtual, numeroCliente, &listaClientesEmAtendimento);
		// Andar uma unidade de tempo
		tempoAtual++;
	}

	exibirResultados(_somatorioClientesAtendidos, ((float) _somatorioTempoPermanenciaFila / contadorClientes), ((float) _somatorioTempoPermanenciaEstabelecimento / _somatorioClientesAtendidos));
}

void verificarFinalAtendimentoClientes(BOX* boxes, int tempoAtual, int numeroUltimoCliente, LISTA** listaClientesEmAtendimento) {
	LISTA* elementoBuscado;
	int i;
	for (i = 0; i < numeroUltimoCliente; i++) {
		elementoBuscado = buscarElementoLista((*listaClientesEmAtendimento), i);
		if (elementoBuscado != NULL)
			if (elementoBuscado->cliente.instanteSaidaEstabelecimento == tempoAtual)
				desocuparBoxEAtenderProximoCliente(boxes, tempoAtual, listaClientesEmAtendimento);
	}
}

// Número de boxes = Número de filas
BOX* criarBoxes() {
	BOX* boxes = (BOX*) malloc(sizeof(BOX) * _numeroFilas);

	int i;
	for (i = 0; i < _numeroFilas; i++) {
		boxes[i].numeroBox = (i + 1);
		boxes[i].clienteNoBox = NULL;
		boxes[i].filaEsperaClientes = criaFila();
	}

	return boxes;
}

// Quando um cliente chega, ele deve procurar um box vazio, caso não exista o que tiver a menor fila
BOX* buscarBoxDesocupadoOuMenorFila(BOX* boxes) {
	int tamanhoMenorFila = INT_MAX;
	BOX* boxMenorFila = NULL;

	int i;
	for (i = 0; i < _numeroFilas; i++) {
		// Se o box for vazio retorná-lo para começar o atendimento
		if (boxes[i].clienteNoBox == NULL)
			return (&boxes[i]);

		// Em segundo verificar de todos os boxes qual tem a menor fila
		if (boxes[i].filaEsperaClientes->tamanho < tamanhoMenorFila) {
			boxMenorFila = (&boxes[i]);
			tamanhoMenorFila = boxes[i].filaEsperaClientes->tamanho;
		}
	}

	return boxMenorFila;
}

// Entrar em um box desocupado ou na menor fila de um box
void entrarBoxDesocupadoOuMenorFila(BOX* boxes, CLIENTE* cliente, int tempoAtual, LISTA** listaClientesEmAtendimento) {
	if (_exibicaoTempoOcorrida == false) {
		exibirTempoAtual(tempoAtual);
		_exibicaoTempoOcorrida = true;
	}

	BOX* boxDesocupadoOuMenorFila = buscarBoxDesocupadoOuMenorFila(boxes);
	cliente->numeroBox = boxDesocupadoOuMenorFila->numeroBox;
	cliente->instanteEntradaFila = tempoAtual;

	if (boxDesocupadoOuMenorFila->clienteNoBox == NULL) {
		cliente->instanteSaidaFila = tempoAtual;
		boxDesocupadoOuMenorFila->clienteNoBox = cliente;

		enfileira(boxDesocupadoOuMenorFila->filaEsperaClientes, (*cliente));
		exibirChegadaCliente(cliente->numeroCliente, cliente->numeroBox, (boxDesocupadoOuMenorFila->filaEsperaClientes->tamanho));
		desenfileira(boxDesocupadoOuMenorFila->filaEsperaClientes, cliente);

		_finalAtendimento = tempoAtual + atendimento(_tempoOperacao, _semente);
		cliente->instanteSaidaEstabelecimento = _finalAtendimento;

		// Somente inserir na lista os clientes que estão ocupando o box
		(*listaClientesEmAtendimento) = inserirInicioLista((*listaClientesEmAtendimento), (*cliente));
		exibirInicioAtendimento(cliente->numeroCliente, cliente->numeroBox, (cliente->instanteEntradaFila - cliente->instanteSaidaFila));
	} else {
		enfileira(boxDesocupadoOuMenorFila->filaEsperaClientes, (*cliente));
		exibirChegadaCliente(cliente->numeroCliente, cliente->numeroBox, boxDesocupadoOuMenorFila->filaEsperaClientes->tamanho);
	}
}

// Desocupar o box e atender o próximo cliente se houver (fila não vazia)
void desocuparBoxEAtenderProximoCliente(BOX* boxes, int tempoAtual, LISTA** listaClientesEmAtendimento) {
	if (_exibicaoTempoOcorrida == false) {
		exibirTempoAtual(tempoAtual);
		_exibicaoTempoOcorrida = true;
	}

	int i;
	for (i = 0; i < _numeroFilas; i++) {
		// Se possuir cliente no box, finalizar seu atendimento e desenfileirar um novo cliente para ser atendido
		if (boxes[i].clienteNoBox != NULL) {
			if (boxes[i].clienteNoBox->instanteSaidaEstabelecimento == tempoAtual) {
				// Quando desocupar o box exibir que o atendimento terminou
				boxes[i].clienteNoBox->instanteSaidaEstabelecimento = tempoAtual;
				int tempoPermanenciaEstabelecimento = (boxes[i].clienteNoBox->instanteSaidaEstabelecimento - boxes[i].clienteNoBox->instanteEntradaFila);
				exibirFinalAtendimento(boxes[i].clienteNoBox->numeroCliente, boxes[i].clienteNoBox->numeroBox, (boxes[i].clienteNoBox->instanteSaidaFila - boxes[i].clienteNoBox->instanteEntradaFila), tempoPermanenciaEstabelecimento);
				_somatorioTempoPermanenciaEstabelecimento += tempoPermanenciaEstabelecimento;
				_somatorioClientesAtendidos++;

				// Desocupar o box
				(*listaClientesEmAtendimento) = excluirElementoLista((*listaClientesEmAtendimento), boxes[i].clienteNoBox->numeroCliente);
				free(boxes[i].clienteNoBox);
				boxes[i].clienteNoBox = NULL;

				// Atender um novo cliente no box se houver
				if (boxes[i].filaEsperaClientes->tamanho > 0) {
					CLIENTE* cliente = (CLIENTE*) malloc(sizeof(CLIENTE));

					desenfileira(boxes[i].filaEsperaClientes, cliente);
					boxes[i].clienteNoBox = cliente;
					boxes[i].clienteNoBox->instanteSaidaFila = tempoAtual;

					_finalAtendimento = tempoAtual + atendimento(_tempoOperacao, _semente);
					boxes[i].clienteNoBox->instanteSaidaEstabelecimento = _finalAtendimento;

					// Somente inserir na lista os clientes que estão ocupando o box
					(*listaClientesEmAtendimento) = inserirInicioLista((*listaClientesEmAtendimento), (*cliente));
					int tempoPermanenciaFila = (boxes[i].clienteNoBox->instanteSaidaFila - boxes[i].clienteNoBox->instanteEntradaFila);
					_somatorioTempoPermanenciaFila += tempoPermanenciaFila;
					exibirInicioAtendimento(boxes[i].clienteNoBox->numeroCliente, boxes[i].clienteNoBox->numeroBox, tempoPermanenciaFila);
				}
			}
		}
	}
}


// -- Funções de Exibição --
void exibirErro() {
	printf("Utilizacao: simula <filas> <tempototal> <tempochegada> <tempooperacao> <semente>\n\n"
			"<filas>: numero de filas\n"
			"<tempototal>: tempo total da simulacao (minutos)\n"
			"<tempochegada>: tempo medio entre chegadas de clientes (minutos)\n"
			"<tempooperacao>: tempo medio de uma operacao de atendimento (minutos)\n"
			"<semente>: numero inteiro para geracao de numeros pseudo-aleatorios\n");
	exit(1);
}

void exibirEntradas(char** argv) {
	printf("\nRodando simulacao de %s minuto(s) com %s fila(s)\n"
			"Tempos medios: chegada = %s; operacao = %s\n",
			argv[2],
			argv[1],
			argv[3],
			argv[4]);
}

void exibirEventos() {
	printf("\nEVENTOS");
	printf("\n----------");
}

void exibirTempoAtual(int tempoAtual) {
	printf("\n\n%06i", tempoAtual);
}

void exibirChegadaCliente(int numeroCliente, int numeroBox, int tamanhoFila) {
	printf("\n Chegada do cliente %i no box %i (tamanho fila: %i)", numeroCliente, numeroBox, tamanhoFila);
}

void exibirInicioAtendimento(int numeroCliente, int numeroBox, int tempoTotalFila) {
	printf("\n Inicio de atendimento do cliente %i box %i (tempo na fila: %i)", numeroCliente, numeroBox, tempoTotalFila);
}

void exibirFinalAtendimento(int numeroCliente, int numeroBox, int tempoTotalFila, int tempoTotalAtendimento) {
	printf("\n Final de atendimento do cliente %i no box %i (fila: %i; total: %i)", numeroCliente, numeroBox, tempoTotalFila, tempoTotalAtendimento);
}

void exibirResultados(int totalClientesAtendidos, float tempoMedioEspera, float tempoMedioPermanencia) {
	printf("\n\n\nRESULTADOS");
	printf("\n----------");
	printf("\n\nTotal de clientes atendidos: %i", totalClientesAtendidos);

	printf("\nTempo medio de espera em fila: %.1f min.", ((int) (tempoMedioEspera * 10) / 10.0));
	printf("\nTempo medio de permanencia: %.1f min.", ((int) (tempoMedioPermanencia * 10) / 10.0));
}
