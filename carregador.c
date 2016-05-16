// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson ...

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
void Carregador(FILE *arq, int16_t *memoria, int *IP){
	printf("Teste Leitura Entrada.\n");

	int16_t instrucao;
	int16_t op1, op2;

	int8_t codOperando, opcode;

	// Leitura de 2 em 2 bytes.
	while (fread((char*)&instrucao, 2, 1, arq) == 1) {
		
		printf("Instrucao: %x \n",instrucao);
		
		//opcode = (instrucao >> 8) & 0xff;
		//printf("Opcode: %d\n",opcode);

		codOperando = (instrucao) & 0xff;
		printf("Codigo: %d \n",codOperando);

		switch (codOperando) {
			// Nenhum Operando.
			case 0:
				printf("Nenhum Operando.\n");
				memoria[*IP] = instrucao;
				(*IP) = (*IP) + 1;
				printf("IP: %d\n",*IP);
				break;
			// Um Operando.
			case 1:
			case 2:
			case 8:
				printf("1 Operando.\n");
				memoria[*IP] = instrucao;
				fread((char*)&op1, 2, 1, arq);
				memoria[*IP+1] = op1;
				(*IP) = (*IP) + 2;
				printf("IP: %d\n",*IP);
				break;
			// Dois Operandos.
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				printf("2 Operandos.\n");
				memoria[*IP] = instrucao;

				fread((char*)&op1, 2, 1, arq);
				memoria[*IP+1] = op1;
				fread((char*)&op2, 2, 1, arq);
				memoria[*IP+2] = op2;

				(*IP) = (*IP) + 3;
				printf("IP: %d\n",*IP);
				break;
			default:
				printf("Opcode errado.\n");
				printf("IP: %d\n",*IP);
		}
		printf("\n");
	}
	
	printf("IP final: %d \n", *IP);
	printf("Final do arquivo.\n");
	
}