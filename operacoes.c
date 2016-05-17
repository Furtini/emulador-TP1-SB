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


	int16_t temp_reg;

	switch (codigo) {
		case 3: // REG e MEM
			temp_reg = mem[IP + 1];
			switch (temp_reg) {
				case 0: // AL

				case 1: // AH
				case 2: // AX
				case 3: // BH
				case 4: // BL
				case 5: // BX
				case 6: // Cl
				case 7: // CH
				case 8: // CX
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}		
			break;				
		case 4: // MEM e REG
		case 5: // REG e REG 
		case 6: // MEM e I
		case 7: // REG e I
		default:
			printf("ERRO de codigo.\n");
			exit(1);
			break;
	}



}

// 02 - ADD	(48 bits)
// op1 = op1 + op2
//Afeta - > ZF e SF
void ADD(int *mem, int *op1, int *op2);

// 03 - SUB (48 bits)
// op1 = op1 - op2
// Afeta -> ZF e SF
void SUB(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t temp_reg;

	switch (codigo) {
		case 3: // REG e MEM
			temp_reg = mem[IP + 1];
			switch (temp_reg) {
				case 0: // AL

				case 1: // AH
				case 2: // AX
				case 3: // BH
				case 4: // BL
				case 5: // BX
				case 6: // Cl
				case 7: // CH
				case 8: // CX
				default:
					printf("ERRO de codigo de registrador.\n");
					exit(1);
					break;
			}		
			break;				
		case 4: // MEM e REG
		case 5: // REG e REG 
		case 6: // MEM e I
		case 7: // REG e I
		default:
			printf("ERRO de codigo.\n");
			exit(1);
			break;
	}

}

// 04 - MUL (32 bits)
// caso byte: AX = AL * op1
// caso word: AX = AX * op1
void MUL(int *mem, int *op1, int *op2);

// 05 - DIV (32 bits)  
// caso byte: AL = AX/op1
//			  AH = resto da div
// caso word: AX = AX/op1	
//			  BX = resto da div
void DIV(int *mem, int *op1, int *op2);

// 06 - AND (48bits)
// op1 = op1 AND op2
// Afeta ZF e SF
void AND(int *mem, int *op1, int *op2);

// 07 - NOT (32 bits)
// op1 = ~op1
// Afeta -> ZF e SF
void NOT(int *mem, int *op1, int *op2);

// 08 - OR (48 bits)
// op1 = op1 OR op2
// Afeta -> ZF e SF
void OR(int *mem, int *op1, int *op2);

// 09 - CMP (48 bits)
// op1 - op2
// Afeta -> ZF e SF
void CMP(int *mem, int *op1, int *op2);

// 10 - JMP (32 bits)
// Desvia para label indicado.
void JMP (int *mem, int *op1, int *op2);

// 11 - JZ (32 bits)
// Se ZF == 1, desvia.
void JZ(int *mem, int *op1, int *op2);

// 12 - JS (32 bits)
// se SF == 1, desvia.
void JS(int *mem, int *op1, int *op2);

// 13 - CALL (32 bits)
// Chama procedimento
void CALL();

// 14 - RET (16 bits)
// Retorna de um procedimento.
void RET();

// 15 - PUSH (32 bits)
// SP = SP - 1
// Empilha valor na memoria.
void PUSH (int *mem, int *op1);
   
// 16 - POP (32 bits)
// SP = SP + 1
// Desempilha valor da memoria.
void POP (int *mem, int *op1);   
   
// 17 - DUMP
// Imprime valores de todos os registradores separados por " ".
void DUMP(int16_t *reg) {

	int i;
	
	printf("AX   BX   CX   BP   SP   IP   ZF   SF\n");
	for(i = 0; i < 8; i++) {
		printf("%04hX ",reg[i]);
	}
}

// 18 - READ 
void READ(int16_t *mem, int16_t *reg, int8_t codigo, int IP) {

	int16_t input;
	// Temps regs.
	int8_t  AL, BL, CL;
	int16_t AH, BH, CH;


	// temp_reg = Operando da instrucao.
	int16_t temp_reg = mem[IP + 1];
	
	// Setando Lower and higher regs.
	AL = reg[0] & 0xff;
	AH = reg[0] >> 8;
	BL = reg[1] & 0xff;
	BH = reg[1] >> 8;
	CL = reg[2] & 0xff;
	CH = reg[2] >> 8;
	

	printf("Entre com o valor: ");
	scanf("%" SCNd16, &input);
	
	// Setando ZF e SF
	(input == 0) ? (reg[6] = 1) : (reg[6] = 0);
	(input >= 0) ? (reg[7] = 0) : (reg[7] = 1);	
	
	// REG
	if (codigo == 1) {
		switch (temp_reg) {
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
void WRITE(int *mem, int *op1);

// 20 - HLT (16 bits)
// Interrompe execucao.
void HLT();