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

	int parada = 1;
	int i;

	// Reseta IP
	regs[11] = 0;

	while (parada) {

		opcode = (memoria[regs[11]] >> 8) & 0xff;
		codigo = memoria[regs[11]] & 0xff;

		switch (opcode) {
			case 1:  // MOV
				printf("-MOV-\n");
				MOV(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 2:	 // ADD
				printf("-ADD-\n");
				ADD(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 3:	 // SUB
				printf("-SUB-\n");
				SUB(memoria, regs, codigo, regs[11]);
				regs[11] += 3;	
				break;
			case 4:  // MUL
				printf("-MUL-\n");
				MUL(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 5:  // DIV
				printf("-DIV-\n");
				DIV(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 6:  // AND
				printf("-ADN-\n");
				AND(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 7:	 // NOT
				printf("-NOT-\n");
				NOT(memoria, regs, codigo, regs[11]);
				regs[11] += 1;				
				break;
			case 8:	 // OR
				printf("-OR-\n");
				OR(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 9:	 // CMP
				printf("-CMP-\n");
				CMP(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 10: // JMP
				printf("-JMP-\n");
				JMP(memoria, regs, regs[11]);
				break;
			case 11: // JZ
				printf("-JZ-\n");
				JZ(memoria, regs, regs[11]);
				break;
			case 12: // JS
				printf("-JS-\n");
				JS(memoria, regs, regs[11]);
				break;
			case 13: // CALL
				printf("-CALL-\n");
				CALL(memoria, regs, regs[11]);
				break;
			case 14: // RET
				printf("-RET-\n");
				RET(memoria, regs, regs[11]);
				break;
			case 15: // PUSH
				printf("-PUSH-\n");
				PUSH(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 16: // POP
				printf("-POP-\n");
				POP(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 17: // DUMP
				printf("-DUMP-\n");
				DUMP(regs);
				regs[11] += 1;
				break;
			case 18: // READ
				printf("-READ-\n");
				READ(memoria, regs, codigo, regs[11]);
				DUMP(regs);
				regs[11] += 2;
				break;
			case 19: // WRITE
				printf("-WRITE-\n");
				WRITE(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 20: // HLT
				printf("-HALT-\n");
				parada = HLT();
				regs[11] = regs[11];
				break;
			default: // Erro de instrucao.
				printf("\nERRO de leitura de instrucao\n");
				exit(1);
				break;
		}
	}
}