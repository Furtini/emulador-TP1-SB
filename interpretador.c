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

	int8_t opcode, codigo;

	int parada = 1;

	// Reseta IP
	regs[11] = 0;

	while (parada) {

		opcode = (memoria[regs[11]] >> 8) & 0xff;
		codigo = memoria[regs[11]] & 0xff;

		switch (opcode) {

			case 1:  // MOV
				MOV(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 2:	 // ADD
				ADD(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 3:	 // SUB
				SUB(memoria, regs, codigo, regs[11]);
				regs[11] += 3;	
				break;
			case 4:  // MUL
				MUL(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 5:  // DIV
				DIV(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 6:  // AND
				AND(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 7:	 // NOT
				NOT(memoria, regs, codigo, regs[11]);
				regs[11] += 1;				
				break;
			case 8:	 // OR
				OR(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 9:	 // CMP
				CMP(memoria, regs, codigo, regs[11]);
				regs[11] += 3;
				break;
			case 10: // JMP
				JMP(memoria, regs, regs[11]);
				break;
			case 11: // JZ
				JZ(memoria, regs, regs[11]);
				break;
			case 12: // JS
				JS(memoria, regs, regs[11]);
				break;
			case 13: // CALL
				CALL(memoria, regs, regs[11]);
				break;
			case 14: // RET
				RET(memoria, regs, regs[11]);
				break;
			case 15: // PUSH
				PUSH(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 16: // POP
				POP(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 17: // DUMP
				DUMP(regs);
				regs[11] += 1;
				break;
			case 18: // READ
				READ(memoria, regs, codigo, regs[11]);
				//DUMP(regs);
				regs[11] += 2;
				break;
			case 19: // WRITE
				WRITE(memoria, regs, codigo, regs[11]);
				regs[11] += 2;
				break;
			case 20: // HLT
				parada = HLT();
				regs[11] = regs[11];
				break;
			default: // Erro de instrucao.
				printf("\nERRO de leitura de instrucao: %d \n", opcode);
				exit(1);
				break;
		}
	}
}