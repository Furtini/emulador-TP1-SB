// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "carregador.h"

// Inicia memoria.
int16_t *InicializaMemoria() {

	// Inicializando memoria.
	int16_t *mem;
	mem = (int16_t *) calloc(TAM_MEMORIA, sizeof(int16_t));
	if (mem == NULL) {
		printf("ERRO ao alocar memoria.\n");
		exit(1);
	}

	return (mem);
}


// Inicia vetor de registradores.
int16_t *InicializaRegistradores() {

	int16_t *regs;
	regs = (int16_t *) calloc (NUM_REG, sizeof(int16_t));
	if (regs == NULL) {
		printf("ERRO ao alocar memoria.\n");
		exit(1);
	}

	return (regs);
}

// Abre arquivo.
FILE *AbreArquivo(const char *nomeArquivo) {

	FILE *a;

	a = fopen(nomeArquivo, "rb");
	if (a == NULL){
		printf("ERRO ao abrir arquivo.\n");
		exit(1);	
	}

	return a;
}

// Leitura das instrucoes e salvando na memoria virtualcriada.
// Carregador.
void Carregador(FILE *arq, int16_t *memoria, int16_t *IP){

	int16_t instrucao;
	int16_t op1, op2;

	int8_t codOperando, opcode;

	// Leitura de 2 em 2 bytes.
	while (fread((char*)&instrucao, 2, 1, arq) == 1) {
		
		opcode = (instrucao >> 8) & 0xff;

		codOperando = (instrucao) & 0xff;

		switch (codOperando) {
			// Nenhum Operando.
			case 0:
				memoria[*IP] = instrucao;
				(*IP) = (*IP) + 1;
				break;
			// Um Operando.
			case 1:
			case 2:
			case 8:
				memoria[*IP] = instrucao;
				fread((char*)&op1, 2, 1, arq);
				memoria[*IP+1] = op1;
				(*IP) = (*IP) + 2;
				break;
			// Dois Operandos.
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				memoria[*IP] = instrucao;

				fread((char*)&op1, 2, 1, arq);
				memoria[*IP+1] = op1;
				fread((char*)&op2, 2, 1, arq);
				memoria[*IP+2] = op2;

				(*IP) = (*IP) + 3;
				break;
			default:
				printf("Opcode errado: %d.\n",codOperando);
				break;
		}
	}
}