// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

// Memoria = 1000 posicoes.
// Cada posicao = 1 palavra 16 bits.

// Instrucao com 0, 1 ou 2 operandos
//  primeiro byte -> operacao
//  segundo byte -> tipo dos operandos

//Proximos 2 bytes varia de opeandos e tipo de operacao.
// Imediatos sao valores em Hexa (ex: 0xABCD).

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "carregador.h"
#include "interpretador.h"

int main(int argc, char const *argv[]) {
	
	FILE *arq = NULL;

	//MEMORIA.
	int16_t *memoria;
	
	// REGISTRADORES.
	// 2 - AX
	// 5 - BX
	// 8 - CX
	// 9 - SP
	// 10 - BP
	// 11 - IP
	// 12 - ZF
	// 13 - SF
	int16_t *registradores;

	// =========================================================================

	// Inicializa memoria
	memoria = InicializaMemoria();
	// Inicializa registradores.
	registradores = InicializaRegistradores();

	// BP recebe Endereco mem[1000] 
	registradores[9] = 1001;
	// SP inicia = BP
	registradores[10] = 1001;

	// Abertura de arquivo contendo instrucoes.
	arq = AbreArquivo(argv[1]);

	// Leitura das instrucoes.
	Carregador(arq, memoria, &registradores[11]);
	
	Interpretador(memoria, registradores);

	fclose(arq);
	free(memoria);
	return 0;
}