// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson ...

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "interpretador.h"
#include "operacoes.h"

void Interpretador(int16_t *memoria, 
				   int8_t *AL, int8_t *AH, int16_t *AX,
				   int8_t *BL, int8_t *BH, int16_t *BX,
				   int8_t *CL, int8_t *CH, int16_t *CX,
				   int *BP, int *SP, int *IP,
				   unsigned short *ZF, unsigned short *SF) {

	printf("Teste Interpretador.\n");
	int i;

	for (i = 0; i < 10; i++){
		printf("Posicao %d: %x \n",i, memoria[i]);
	}
}