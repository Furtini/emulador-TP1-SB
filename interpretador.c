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

	while (count < regs[11]) {

		opcode = (memoria[count] >> 8) & 0xff;
		codigo = memoria[count] & 0xff;

		switch (opcode) {
			case 1:  // MOV
				printf("-MOV-\n");
				MOV(memoria, regs, codigo, count);
				count += 3;
				break;
			case 2:	 // ADD
				printf("-ADD-\n");
				ADD(memoria, regs, codigo, count);
				count += 3;
				break;
			case 3:	 // SUB
				printf("-SUB-\n");
				SUB(memoria, regs, codigo, count);
				DUMP(regs);
				count += 3;	
				break;
			case 4:  // MUL
				printf("-MUL-\n");
				MUL(memoria, regs, codigo, count);
				count += 2;
				break;
			case 5:  // DIV
				printf("-DIV-\n");
				DIV(memoria, regs, codigo, count);
				count += 2;
				break;
			case 6:  // AND
				printf("-ADN-\n");
				AND(memoria, regs, codigo, count);
				count += 3;
				break;
			case 7:	 // NOT
				printf("-NOT-\n");
				NOT(memoria, regs, codigo, count);
				count += 1;				
				break;
			case 8:	 // OR
				printf("-OR-\n");
				OR(memoria, regs, codigo, count);
				count += 3;
				break;
			case 9:	 // CMP
				printf("-CMP-\n");
				CMP(memoria, regs, codigo, count);
				count += 3;
				break;
			case 10: // JMP
				printf("-JMP-\n");
				JMP(memoria, regs, codigo, count);
				count += 2;
				break;
			case 11: // JZ
				printf("-JZ-\n");
				JZ(memoria, regs, codigo, count);
				count += 2;
				break;
			case 12: // JS
				printf("-JS-\n");
				JS(memoria, regs, codigo, count);
				count += 2;
				break;
			case 13: // CALL
				printf("-CALL-\n");
				CALL(memoria, regs, codigo, count);
				count += 2;
				break;
			case 14: // RET
				printf("-RET-\n");
				RET(memoria, regs, codigo, count);
				count += 1;
				break;
			case 15: // PUSH
				printf("-PUSH-\n");
				PUSH(memoria, regs, codigo, count);
				count += 2;
				break;
			case 16: // POP
				printf("-POP-\n");
				POP(memoria, regs, codigo, count);
				count += 2;
				break;
			case 17: // DUMP
				printf("-DUMP-\n");
				DUMP(regs);
				count += 1;
				break;
			case 18: // READ
				printf("-READ-\n");
				READ(memoria, regs, codigo, count);
				count += 2;
				break;
			case 19: // WRITE
				printf("-WRITE-\n");
				WRITE(memoria, regs, codigo, count);
				count += 2;
				break;
			case 20: // HLT
				printf("-HALT-\n");
				HLT();
				count += 1;
				break;
			default: // Erro de instrucao.
				printf("\nERRO de leitura de instrucao\n");
				count = regs[5];
				break;
		}
	}
}