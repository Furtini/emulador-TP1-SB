// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "interpretador.h"
#include "operacoes.h"

void Interpretador(int16_t *memoria, int16_t *regs) {
	printf("\nTeste Interpretador.\n");

	int8_t opcode, codigo;
	int16_t op1, op2;

	int count = 0;
	int i;

	while (count < regs[5]) {

		opcode = (memoria[count] >> 8) & 0xff;
		codigo = memoria[count] & 0xff;

		switch (opcode) {
			case 1:  // MOV
				printf("MOV\n");
				MOV(memoria, regs, codigo, count);
				count += 3;
				break;
			case 2:	 // ADD
				
				break;
			case 3:	 // SUB
				
				break;
			case 4:  // MUL
				
				break;
			case 5:  // DIV
				
				break;
			case 6:  // AND
				
				break;
			case 7:	 // NOT
				
				break;
			case 8:	 // OR
				
				break;
			case 9:	 // CMP
				
				break;
			case 10: // JMP
				
				break;
			case 11: // JZ
				
				break;
			case 12: // JS
				
				break;
			case 13: // CALL
				
				break;
			case 14: // RET
				
				break;
			case 15: // PUSH
				
				break;
			case 16: // POP
				
				break;
			case 17: // DUMP
				printf("-DUMP-\n");
				DUMP(regs);
				count += 1;
				break;
			case 18: // READ
				printf("-READ-\n");
				READ(memoria, regs, codigo, count);
				printf("ZF: %d\n",regs[6]);
				printf("SF: %d\n",regs[7]);
				DUMP(regs);
				count += 2;
				break;
			case 19: // WRITE
				
				break;
			case 20: // HLT
				
				break;
			default: // Erro de instrucao.
				//printf("ERRO de leitura de instrucao\n");
				//exit(1);
				break;
		}





	//	printf("Posicao %d: %x \n",count, memoria[count]);
	//	printf("Opcode: %d\n",opcode );
	//	printf("Codigo: %d\n", codigo);
	//	printf("\n");
		count++;
	}
	printf("\n");

}