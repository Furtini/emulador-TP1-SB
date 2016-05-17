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
	int16_t *regs;

	int16_t AX = 5000;
	int16_t input = 10;
	int16_t AL;
	int16_t AH = (AX >> 8);

	AL = AX << 8;
	AL = AL >> 8;
	// =========================================================================

	printf("AX: %" PRId16 "\n",AX);
	printf("AL: %" PRId16 "\n",AL );
	printf("AH: %" PRId16 "\n",AH );
	printf("Input: %" PRId16 "\n",input );
	printf("-------------\n");
	AH = AH + input;
	printf("AH: %" PRId16 "\n",AH );
	AL = AL + input;
	AH = AH << 8;
	AX = AX + AL;
	printf("AL: %" PRId16 "\n",AL );
	printf("AH: %" PRId16 "\n",AH );
	printf("AX :%" PRId16 "\n",AX);
//	int x = 1;
//	char *y = (char*)&x;
//	printf("%c\n",*y+48);
	
	// Inicializa memoria
	memoria = InicializaMemoria();
	// Inicializa registradores.
	regs = InicializaRegistradores();

	// Abertura de arquivo contendo instrucoes.
	arq = AbreArquivo(argv[1]);

	// Leitura das instrucoes.
	Carregador(arq, memoria, &regs[11]);
	
	Interpretador(memoria, regs);

	fclose(arq);
	free(memoria);
	return 0;
}