// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Juniot - 2014004174

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

#include "controle.h"
#include "operacoes.h"

int main(int argc, char const *argv[]) {
	
	FILE *arq = NULL;

	//MEMORIA.
	int16_t *memoria;
	
	// REGISTRADORES.
	// --- A ---
	int8_t  AL = 0;
	int8_t  AH = 0;
	int16_t AX = 0;
	// --- B ---
	int8_t  BL = 0;
	int8_t  BH = 0;
	int16_t BX = 0;
	// --- C ---
	int8_t 	CL = 0;
	int8_t  CH = 0;
	int16_t CX = 0;
	// Aponta para base da memoria (ultima posicao).
	int BP = 0;  // Base pointer.
	// A cada chamada para empilhar, valor empilhado na posicao (SP - 1)
	int SP = 0; // Stack pointer.
	// Incrementado a cada iteracao.
	int IP = 0; // Instruction pointer.
	// Indica se resultado da operacao eh zero(1) ou diferente de zero (0).
	unsigned short int ZF = 0; // Zero flag.
	// Indica se resultado da op eh positivo (0) ou negativo (1).
	unsigned short int SF = 0; // Sign flag.

	// =========================================================================

//	int x = 1;
//	char *y = (char*)&x;
//	printf("%c\n",*y+48);
	
	// Inicializa memoria e registradores.
	memoria = InicializaMemoria();

	// Abertura de arquivo contendo instrucoes.
	arq = AbreArquivo(argv[1]);

	// Leitura das instrucoes.
	Carregador(arq, memoria, &IP);
	
	fclose(arq);
	free(memoria);
	return 0;
}
