// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "operacoes.h"

// -----------
// Instrucoes:

// 01 - MOV (48 bits)
// op1 <- op2
void MOV(int16_t *mem, int16_t *reg, int8_t codigo, int IP) {

	int16_t op1, op2, resp;
	// Temps regs.
	int8_t  AL, BL, CL;
	int16_t AH, BH, CH;

	op1 = mem[IP + 1];
	op2 = mem[IP + 2];
 
	// Setando Lower and higher regs.
	AL = reg[0] & 0xff;
	AH = reg[0] >> 8;
	BL = reg[1] & 0xff;
	BH = reg[1] >> 8;
	CL = reg[2] & 0xff;
	CH = reg[2] >> 8;

	switch (codigo) {
		case 3: // REG e MEM
			switch (op1) {
				case 0: // AL
					AL = AL - mem[op2];
					reg[0] = reg[0] - AL;
					resp = reg[0];
					break;
				case 1: // AH
					break;
				case 2: // AX
					break;
				case 3: // BH
					break;
				case 4: // BL
					break;
				case 5: // BX
					break;
				case 6: // CL
					break;
				case 7: // CH
					break;
				case 8: // CX
					break;
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}
			break;				
		case 4: // MEM e REG
			break;
		case 5: // REG e REG 
			break;
		case 6: // MEM e I
			break;
		case 7: // REG e I
			break;
		default:
			printf("ERRO de codigo.\n");
			exit(1);
			break;
	}
	// Setando ZF e SF
	(resp == 0) ? (reg[6] = 1) : (reg[6] = 0);
	(resp >= 0) ? (reg[7] = 0) : (reg[7] = 1);	



}

// 02 - ADD	(48 bits)
// op1 = op1 + op2
//Afeta - > ZF e SF
void ADD(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 03 - SUB (48 bits)
// op1 = op1 - op2
// Afeta -> ZF e SF
void SUB(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1, op2, resp;
	// Temps regs.
	int8_t  AL, BL, CL;
	int16_t AH, BH, CH;

	op1 = mem[IP + 1];
	op2 = mem[IP + 2];

	printf("%" PRId16 "\n",op1 );
	printf("%" PRId16 "\n",op2 );
 
	
	// Setando ZF e SF
	(resp == 0) ? (reg[6] = 1) : (reg[6] = 0);
	(resp >= 0) ? (reg[7] = 0) : (reg[7] = 1);			

}

// 04 - MUL (32 bits)
// caso byte: AX = AL * op1
// caso word: AX = AX * op1
void MUL(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 05 - DIV (32 bits)  
// caso byte: AL = AX/op1
//			  AH = resto da div
// caso word: AX = AX/op1	
//			  BX = resto da div
void DIV(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 06 - AND (48bits)
// op1 = op1 AND op2
// Afeta ZF e SF
void AND(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 07 - NOT (32 bits)
// op1 = ~op1
// Afeta -> ZF e SF
void NOT(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 08 - OR (48 bits)
// op1 = op1 OR op2
// Afeta -> ZF e SF
void OR(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 09 - CMP (48 bits)
// op1 - op2
// Afeta -> ZF e SF
void CMP(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 10 - JMP (32 bits)
// Desvia para label indicado.
void JMP (int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 11 - JZ (32 bits)
// Se ZF == 1, desvia.
void JZ(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 12 - JS (32 bits)
// se SF == 1, desvia.
void JS(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 13 - CALL
// Chama procedimento
void CALL(int16_t *mem, int16_t *reg, int IP) {

	int16_t op1 = mem[IP + 1];

	// Decrementa SP
	reg[10] = reg[10] - 1;
	// EMPILHA IP da prox instrucao.
	mem[reg[10]] = IP + 2;

	// IP passa a ser a posicao da memoria de op1.
	reg[11] = op1; 
}

// 14 - RET (16 bits)
// Retorna de um procedimento.
void RET(int16_t *mem, int16_t *reg, int IP) {

	// Recupera valor do IP empilhado.
	reg[11] = mem[reg[10]];

	reg[10] = reg[10] + 1;
}

// 15 - PUSH
// Empilha valor na memoria.
void PUSH (int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];

	// Decrementa SP
	reg[10] = reg[10] - 1;
	
	// REG
	if (codigo == 1) {
		mem[reg[10]] = reg[op1];
	}
	// MEM
	if (codigo == 2) {
		mem[reg[10]] = mem[op1];
	}
	// IMEDIATO
	if (codigo == 8) {
		mem[reg[10]] = op1;
	}
}
   
// 16 - POP
// Desempilha valor da memoria.
void POP (int16_t *mem, int16_t *reg, int codigo, int IP){

	int16_t op1 = mem[IP + 1];
	
	// REG
	if (codigo == 1) {
		switch (op1) {
			// AL
			case 0:
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff;

				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] << 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// AH
			case 1: 
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff;

				reg[2] = reg[2] << 8;				
				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// BH	
			case 3:
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff; 

				reg[5] = reg[5] << 8;
				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] + reg[op1];
				break;
			//BL
			case 4:
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff; 

				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] << 8;
				reg[5] = reg[5] + reg[op1];
				break;
			// CL
			case 6:
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff; 

				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] << 8;
				reg[8] = reg[8] + reg[op1];
				break;
			// CH	
			case 7: 
				// Pegando 8 bits menos significativos da memoria. 
				reg[op1] = mem[reg[10]]&0xff; 

				reg[8] = reg[8] << 8;
				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] + reg[op1];
				break;
		
			default:
				reg[op1] = mem[reg[10]];
				break;
		}		
	}
	// MEM
	if (codigo == 2) {
		mem[op1] = mem[reg[10]];
	}
	// Incrementa SP
	reg[10] = reg[10] + 1;
} 
   
// 17 - DUMP
// Imprime valores de todos os registradores separados por " ".
void DUMP(int16_t *reg) {

	printf("AX   BX   CX   SP   BP   IP   ZF   SF\n");
	printf("%04hX %04hX %04hX %04hX %04hX %04hX %04hX %04hX", reg[2],reg[5],reg[8],reg[10],reg[9],reg[11],reg[12],reg[13]);
	printf("\n");
}

// 18 - READ 
void READ(int16_t *mem, int16_t *reg, int8_t codigo, int IP) {

	int16_t input;
	
	int16_t op1 = mem[IP + 1];

	printf("Entre com o valor: ");
	scanf("%" SCNx16, &input);
	
	// Setando ZF e SF
	(input == 0) ? (reg[12] = 1) : (reg[12] = 0);
	(input >= 0) ? (reg[13] = 0) : (reg[13] = 1);	
	
	// REG
	if (codigo == 1) {
		printf("CODIGO: %d\n",codigo );
		printf("Endereco banco reg: %d\n", op1);
		switch (op1) {
			// AL
			case 0:
				reg[op1] = input;

				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] << 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// AH
			case 1: 
				reg[op1] = input;

				reg[2] = reg[2] << 8;				
				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// BH	
			case 3: 
				reg[op1] = input;

				reg[5] = reg[5] << 8;
				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] + reg[op1];
				break;
			//BL
			case 4:
				reg[op1] = input;

				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] << 8;
				reg[5] = reg[5] + reg[op1];
				break;
			// CL
			case 6:
				reg[op1] = input;

				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] << 8;
				reg[8] = reg[8] + reg[op1];
				break;
			// CH	
			case 7: 
				reg[op1] = input;

				reg[8] = reg[8] << 8;
				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] + reg[op1];
				break;
		
			default:

				reg[op1] = input;
				break;
		}		
	}
	// MEM
	if (codigo == 2) {
		mem[op1] = input;
	}
}

// 19 - WRITE (32 bits)
// Escreve na tela valor do operando.
void WRITE(int16_t *mem, int16_t *reg, int codigo, int IP) {
	
	int16_t op1 = mem[IP + 1];

	// REG
	if (codigo == 1) {
		printf("%04hX\n",reg[op1]);
	}
	// MEM
	if (codigo == 2) {
		printf("%04hX\n",mem[op1]);
	}
}

// 20 - HLT
// Interrompe execucao.
// Tratado no proprio case do interpretador.
int HLT() {return 0;}