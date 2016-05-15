// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "controle.h"

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
void Carregador(FILE *arq, int16_t *memoria, int *PC){
	printf("Teste Leitura Entrada.\n\n");

	int parada;
	int operandos, opcode;

	unsigned char buffer1[2];
	unsigned char buffer2;


	fread((char *)&buffer1[0], 1, 1, arq);
	fread((char *)&buffer1[1], 1, 1, arq);

	printf("Primeiro byte lido: %d\n", buffer1[0]);
	printf("Segundo byte lido: %d\n", buffer1[1]);


	opcode = buffer1[1];

	printf("Opcode: %d \n", opcode);
	/*
	// Leitura de 2 em 2 bytes.
	while (1) {
		parada = fread(buffer, 1, 1, arq);
		if (parada != 1) {
			printf("\nFim do arquivo!\n");
			break;
		} else { 
			operandos = buffer[0];
			opcode = buffer[1];

			printf("Primeiro byte lido: %d\n", operandos);
			printf("Segundo byte lido: %d\n", opcode);

			printf("\n");
		}
		
	}
	*/
}

/*
			switch (operandos) {
				case 0: 
					printf("Imediato. \n"); 
					break;
				case 1: 
					printf("Registrador. \n"); 
					break;
				case 2: 
					printf("Memoria. \n"); 
					break;
				case 3: 
					printf("Registrador e Memoria. \n"); 
					break;
				case 4: 
					printf("Memoria e Registrador. \n"); 
					break;
				case 5: 
					printf("Registrador e Registrador. \n"); 
					break;
				case 6: 
					printf("Memoria e Imediato. \n"); 
					break;
				case 7: 
					printf("Registrador e Imediato. \n"); 
					break;
				case 8: 
					printf("Imediato. \n"); 
					break;
				default:
					printf("Valor invalido.\n");
			}*/
