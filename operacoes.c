// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "operacoes.h"

// Identifica qual registrador usar.
static int16_t IdRegistrador(int16_t *reg, int8_t cod) {

	// Setando Lower and higher regs.
	// AL
	reg[0] = reg[2] << 8;
	reg[0] = reg[0] >> 8;
	// AH
	reg[1] = reg[2] >> 8;
	// BH
	reg[3] = reg[5] >> 8;
	// BL	
	reg[4] = reg[5] << 8;
	reg[4] = reg[4] >> 8;
	// CL
	reg[6] = reg[8] << 8;
	reg[6] = reg[6] >> 8;
	// CH
	reg[7] = reg[8] >> 8;

	switch (cod) {
		case 0: // AL
			printf("AL\n");
			return reg[0];
			break;
		case 1: // AH
			printf("AH\n");
			return reg[1];
			break;
		case 2: // AX
			printf("AX\n");
			return reg[2];
			break;
		case 3: // BH
			printf("BH\n");
			return reg[3];
			break;
		case 4: // BL
			printf("BL\n");
			return reg[4];
			break;
		case 5: // BX
			printf("BX\n");
			return reg[5];
			break;
		case 6: // CL
			printf("CL\n");
			return reg[6];
			break;
		case 7: // CH
			printf("CH\n");
			return reg[7];
			break;
		case 8: // CX
			printf("CX\n");
			return reg[8];
			break;
		default:
			printf("ERRO de codigo de registrador.\n");
			return 0;
			break;	
	}
}


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
					AH = AH - mem[op2];
					AH = AH << 8;
					reg[0] = reg[0] - AH;
					resp = reg[0];
					break;
				case 2: // AX
					reg[0] = reg[0] - mem[op2];
					resp = reg[0];
					break;
				case 3: // BH
					BH = BH - mem[op2];
					BH = BH << 8;
					reg[1] = reg[1] - BH;
					resp = reg[1];
					break;
				case 4: // BL
					BL = BL - mem[op2];
					reg[1] = reg[1] - BL;
					resp = reg[1];
					break;
				case 5: // BX
					reg[1] = reg[1] - mem[op2];
					resp = reg[1];
					break;
				case 6: // CL
					CL = CL - mem[op2];
					reg[2] = reg[2] - CL;
					resp = reg[2];
					break;
				case 7: // CH
					CH = CH - mem[op2];
					CH = CH << 8;
					reg[2] = reg[2] - CH;
					resp = reg[2];
					break;
				case 8: // CX
					reg[2] = reg[2] - mem[op2];
					resp = reg[2];
					break;
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}
			break;				
		case 4: // MEM e REG
			switch (op2) {
				case 0: // AL
					mem[op1] = mem[op1] - AL;
					resp = mem[op1];
					break;
				case 1: // AH
					mem[op1] = mem[op1] - AH;
					resp = mem[op1];
					break;
				case 2: // AX
					mem[op1] = mem[op1] - reg[0];
					resp = mem[op1];
					break;
				case 3: // BH
					mem[op1] = mem[op1] - BH;
					resp = mem[op1];
					break;
				case 4: // BL
					mem[op1] = mem[op1] - BL;
					resp = mem[op1];
					break;
				case 5: // BX
					mem[op1] = mem[op1] - reg[1];
					resp = mem[op1];
					break;
				case 6: // CL
					mem[op1] = mem[op1] - CL;
					resp = mem[op1];
					break;
				case 7: // CH
					mem[op1] = mem[op1] - CH;
					resp = mem[op1];
					break;
				case 8: // CX
					mem[op1] = mem[op1] - reg[2];
					resp = mem[op1];
					break;
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}
			break;
		case 5: // REG e REG 
			break;
		case 6: // MEM e I
			mem[op1] = mem[op1] + op2;
			resp = mem[op1];
			break;
		case 7: // REG e I
			switch (op1) {
				case 0: // AL
					AL = AL - op2;
					reg[0] = reg[0] - AL;
					resp = reg[0];
					break;
				case 1: // AH
					AH = AH - op2;
					AH = AH << 8;
					reg[0] = reg[0] - AH;
					resp = reg[0];
					break;
				case 2: // AX
					reg[0] = reg[0] - op2;
					resp = reg[0];
					break;
				case 3: // BH
					BH = BH - op2;
					BH = BH << 8;
					reg[1] = reg[1] - BH;
					resp = reg[1];
					break;
				case 4: // BL
					BL = BL - op2;
					reg[1] = reg[1] - BL;
					resp = reg[1];
					break;
				case 5: // BX
					reg[1] = reg[1] - op2;
					resp = reg[1];
					break;
				case 6: // CL
					CL = CL - op2;
					reg[2] = reg[2] - CL;
					resp = reg[2];
					break;
				case 7: // CH
					CH = CH - op2;
					CH = CH << 8;
					reg[2] = reg[2] - CH;
					resp = reg[2];
					break;
				case 8: // CX
					reg[2] = reg[2] - op2;
					resp = reg[2];
					break;
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}
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

// 13 - CALL (32 bits)
// Chama procedimento
void CALL(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 14 - RET (16 bits)
// Retorna de um procedimento.
void RET(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 15 - PUSH (32 bits)
// SP = SP - 1
// Empilha valor na memoria.
void PUSH (int16_t *mem, int16_t *reg, int codigo, int IP) {

}
   
// 16 - POP (32 bits)
// SP = SP + 1
// Desempilha valor da memoria.
void POP (int16_t *mem, int16_t *reg, int codigo, int IP){

} 
   
// 17 - DUMP
// Imprime valores de todos os registradores separados por " ".
void DUMP(int16_t *reg) {

	int i;
	
	printf("AX   BX   CX   BP   SP   IP   ZF   SF\n");
	for(i = 0; i < 8; i++) {
		printf("%04hX ",reg[i]);
	}
	printf("\n");
}

// 18 - READ 
void READ(int16_t *mem, int16_t *reg, int8_t codigo, int IP) {

	int16_t input;
	// Temps regs.
	int8_t  AL, BL, CL;
	int16_t AH, BH, CH;

	int16_t op1 = mem[IP + 1];
	
	// Setando Lower and higher regs.
	AL = reg[0] & 0xff;
	AH = reg[0] >> 8;
	BL = reg[1] & 0xff;
	BH = reg[1] >> 8;
	CL = reg[2] & 0xff;
	CH = reg[2] >> 8;
	
	printf("Entre com o valor: ");
	scanf("%" SCNx16, &input);
	
	printf("input: %d\n",input );
	// Setando ZF e SF
	(input == 0) ? (reg[6] = 1) : (reg[6] = 0);
	(input >= 0) ? (reg[7] = 0) : (reg[7] = 1);	
	
	// REG
	if (codigo == 1) {
		switch (op1) {
			case 0: // AL

				AL = AL + input;
				reg[0] = reg[0] + AL;
				break;
			case 1: // AH

				AH = AH + input;
				AH = AH << 8;
				reg[0] = reg[0] + AH;
				break;
			case 2: // AX
				
				reg[0] = input;
				break;
			case 3: // BH

				BH = BH + input;
				BH = BH << 8;
				reg[1] = reg[1] + BH;
				break;
			case 4: // BL

				BL = BL + input;
				reg[1] = reg[1] + BL;
				break;
			case 5: // BX

				reg[1] = input;
				break;
			case 6: // CL

				CL = CL + input;
				reg[2] = reg[2] + CL;
				break;
			case 7: // CH

				CH = CH + input;
				CH = CH << 8;
				reg[2] = reg[2] + CH;
				break;
			case 8: // CX

				reg[2] = input;
				break;
			default:
				printf("ERRO de codigo de registrador.\n");
				exit(1);
				break;
		}		
	}
}

// 19 - WRITE (32 bits)
// Escreve na tela valor do operando.
void WRITE(int16_t *mem, int16_t *reg, int codigo, int IP) {

}

// 20 - HLT (16 bits)
// Interrompe execucao.
void HLT() {

}