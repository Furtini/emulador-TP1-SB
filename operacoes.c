// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "operacoes.h"

// Atualiza os registradores no final de cada execucacao da instrucao.
static void AtualizaRegs(int16_t *reg, int16_t operando) {

	switch(operando) {
		// AL 
		case 0:
			reg[operando] = reg[operando] << 8;
			reg[operando] = reg[operando] >> 8;

			reg[2] = reg[2] >> 8;
			reg[2] = reg[2] << 8;

			reg[2] = reg[2] + reg[operando];
			break;
		// AH
		case 1:
			reg[operando] = reg[operando] >> 8;
			reg[operando] = reg[operando] << 8;

			reg[2] = reg[2] << 8;
			reg[2] = reg[2] >> 8;

			reg[2] = reg[2] + reg[operando];
			break;
		// AX
		case 2:
			reg[0] = reg[operando] << 8;
			reg[0] = reg[0] >> 8;

			reg[1] = reg[operando] >> 8; 
			break;
		// BH
		case 3:
			reg[operando] = reg[operando] >> 8;
			reg[operando] = reg[operando] << 8;

			reg[5] = reg[5] << 8;
			reg[5] = reg[5] >> 8;

			reg[5] = reg[5] + reg[operando];
			break;
		// BL
		case 4:
			reg[operando] = reg[operando] << 8;
			reg[operando] = reg[operando] >> 8;

			reg[5] = reg[5] >> 8;
			reg[5] = reg[5] << 8;

			reg[5] = reg[5] + reg[operando];
			break;
		// BX
		case 5:
			reg[4] = reg[operando] << 8;
			reg[4] = reg[4] >> 8;

			reg[3] = reg[operando] >> 8; 
			break;
		// CL
		case 6:
			reg[operando] = reg[operando] << 8;
			reg[operando] = reg[operando] >> 8;

			reg[8] = reg[8] >> 8;
			reg[8] = reg[8] << 8;

			reg[8] = reg[8] + reg[operando];
			break;
		// CH
		case 7:
			reg[operando] = reg[operando] >> 8;
			reg[operando] = reg[operando] << 8;

			reg[8] = reg[8] << 8;
			reg[8] = reg[8] >> 8;

			reg[8] = reg[8] + reg[operando];
			break;
		// CX
		case 8:
			reg[6] = reg[operando] << 8;
			reg[6] = reg[0] >> 8;

			reg[7] = reg[operando] >> 8; 
			break;
		default: 
			printf("ERRO: Codigo de operando!\n");
			exit(1);
			break;
	}
}

// -----------
// Instrucoes:

// 01 - MOV
// op1 <- op2
void MOV(int16_t *mem, int16_t *reg, int8_t codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];
	
	switch (codigo) {
		// REG - MEM
		case 3:
			reg[op1] = mem[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			
			AtualizaRegs(reg, op1);
			break;
		// MEM - REG
		case 4:
			mem[op1] = reg[op2];

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			
			break;
		// REG - REG
		case 5:
			reg[op1] = reg[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			
			AtualizaRegs(reg, op1);
			break;
		// MEM - I
		case 6:
			mem[op1] = op2;

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			break;
		// REG - I
		case 7:
			reg[op1] = op2;

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}

}

// 02 - ADD
// op1 = op1 + op2
//Afeta - > ZF e SF
void ADD(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];

	switch (codigo) {
		// REG - MEM
		case 3:
			reg[op1] = reg[op1] + mem[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;	
		// MEM - REG
		case 4:
			mem[op1] = mem[op1] + reg[op1];

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - REG
		case 5:
			reg[op1] = reg[op1] + reg[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		// MEM - I
		case 6:
			mem[op1] = mem[op1] + op2;
			// Setando ZF e SF
			((mem[op1]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((mem[op1]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - I
		case 7:
			reg[op1] = reg[op1] + op2;

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}		
}

// 03 - SUB
// op1 = op1 - op2
// Afeta -> ZF e SF
void SUB(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];

	switch (codigo) {
		// REG - MEM
		case 3:
			reg[op1] = reg[op1] - mem[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;	
		// MEM - REG
		case 4:
			mem[op1] = mem[op1] - reg[op1];

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - REG
		case 5:
			reg[op1] = reg[op1] - reg[op2];

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		// MEM - I
		case 6:
			mem[op1] = mem[op1] - op2;
			// Setando ZF e SF
			((mem[op1]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((mem[op1]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - I
		case 7:
			reg[op1] = reg[op1] - op2;

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}		
}

// 04 - MUL
// caso byte: AX = AL * op1
// caso word: AX = AX * op1
void MUL(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	
	// Atualizacao do AL.
	reg[0] = reg[0] << 8;
	reg[0] = reg[0] >> 8;
	
	// REG
	if (codigo == 1) {

		switch (op1) {

			// AL
			case 0:
				// Atualiza AL com lower bits de AX
				reg[op1] = reg[2] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[2] = reg[0] * reg[op1];
				break;
			// AH
			case 1: 
				// Atualiza AH com higher bits de AX
				reg[op1] = reg[2] >> 8;

				reg[2] = reg[0] * reg[op1];
				break;
			// BH	
			case 3:
				// Atualiza BH com higher bits de BX
				reg[op1] = reg[5] >> 8;

				reg[2] = reg[0] * reg[op1];
				break;
			//BL
			case 4:
				// Atualiza BL com lower bits de BX
				reg[op1] = reg[5] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[2] = reg[0] * reg[op1];
				break;
			// CL
			case 6:
				// Atualiza CL com higher bits de CX
				reg[op1] = reg[8] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[2] = reg[0] * reg[op1];
				break;
			// CH	
			case 7: 
				// Atualiza CH com higher bits de CX
				reg[op1] = reg[8] >> 8;
				
				reg[2] = reg[0] * reg[op1];
				break;
			// AX ou BX ou CX		
			default:
				reg[2] = reg[2] * reg[op1];
				break;
		}
	}
	// MEM
	if (codigo == 2) {
		reg[2] = reg[2] * mem[op1];
	}
}

// 05 - DIV
// caso byte: AL = AX/op1
//			  AH = resto da div
// caso word: AX = AX/op1	
//			  BX = resto da div
void DIV(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	
	// REG
	if (codigo == 1) {
		// AL = AX / op1 
		// AH = AX % op1
		switch (op1) {
			case 0: // AL 
			case 4: // BL
			case 6: // CL
				// Shift pq so quero os 8 menos significativos
				reg[op1] = reg[2] << 8;
				reg[op1] = reg[2] >> 8;		

				reg[0] = reg[2] / reg[op1];
				reg[1] = reg[2] % reg[op1];
				break;			
			case 1: // AH
			case 3: // BH
			case 7: // CH
				// Shift pq so quero os mais significativos.
				reg[op1] = reg[2] >> 8;

				reg[0] = reg[2] / reg[op1];
				reg[1] = reg[2] % reg[op1];
				break;
			// AX ou BX ou CX		
			default:
				reg[2] = reg[2] / reg[op1];
				reg[5] = reg[2] % reg[op1];
				break;
		}
		// Shift pq so quero os 8 menos significativos
		reg[0] = reg[0] << 8;
		reg[0] = reg[0] >> 8;
		// Shift pq so quero os mais significativos.
		reg[1] = reg[1] << 8;

		reg[2] = reg[1] + reg[0];
	}
	// MEM
	if (codigo == 2) {
		reg[2] = reg[2] / mem[op1];
		reg[5] = reg[2] % mem[op1];
	}
}

// 06 - AND (48bits)
// op1 = op1 AND op2
// Afeta ZF e SF
void AND(int16_t *mem, int16_t *reg, int codigo, int IP) {
	
	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];

	switch (codigo) {
		// REG - MEM
		case 3:
			reg[op1] = (reg[op1]) & (mem[op2]);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;	
		// MEM - REG
		case 4:
			mem[op1] = (mem[op1]) & (reg[op1]);

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - REG
		case 5:
			reg[op1] = (reg[op1]) & (reg[op2]);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		// MEM - I
		case 6:
			mem[op1] = (mem[op1]) & (op2);
			// Setando ZF e SF
			((mem[op1]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((mem[op1]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - I
		case 7:
			reg[op1] = (reg[op1]) & (op2);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}		
}

// 07 - NOT
// op1 = ~op1
// Afeta -> ZF e SF
void NOT(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	
	// REG
	if (codigo == 1) {
		switch (op1) {
			// AL
			case 0:
				// Atualiza AL com lower bits de AX
				reg[op1] = reg[2] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[op1] = ~(reg[op1]);
				reg[op1] = reg[op1] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] << 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// AH
			case 1: 
				// Atualiza AH com higher bits de AX
				reg[op1] = reg[2] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[op1] = ~(reg[op1]);
				reg[op1] = reg[op1] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[2] = reg[2] << 8;				
				reg[2] = reg[2] >> 8;
				reg[2] = reg[2] + reg[op1];
				break;
			// BH	
			case 3:
				// Atualiza BH com higher bits de BX
				reg[op1] = reg[5] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[op1] = ~(reg[op1]);
				reg[op1] = reg[op1] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[5] = reg[5] << 8;
				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] + reg[op1];
				break;
			//BL
			case 4:
				// Atualiza BL com lower bits de BX
				reg[op1] = reg[5] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[op1] = ~(reg[op1]);;
				reg[op1] = reg[op1] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[5] = reg[5] >> 8;
				reg[5] = reg[5] << 8;
				reg[5] = reg[5] + reg[op1];
				break;
			// CL
			case 6:
				// Atualiza CL com lower bits de CX
				reg[op1] = reg[8] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[op1] = ~(reg[op1]);
				reg[op1] = reg[op1] << 8;
				reg[op1] = reg[op1] >> 8;

				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] << 8;
				reg[8] = reg[8] + reg[op1];
				break;
			// CH	
			case 7: 
				// Atualiza CL com higher bits de CX
				reg[op1] = reg[8] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[op1] = ~(reg[op1]);
				reg[op1] = reg[op1] >> 8;
				reg[op1] = reg[op1] << 8;

				reg[8] = reg[8] << 8;
				reg[8] = reg[8] >> 8;
				reg[8] = reg[8] + reg[op1];
				break;
			// AX ou BX ou CX		
			default:
				reg[op1] = ~ (reg[op1]);
				break;
		}
		// Setando ZF e SF
		(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
		(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);		
	}
	// MEM
	if (codigo == 2) {
		mem[op1] = ~ (mem[op1]);
		// Setando ZF e SF
		(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
		(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
				
	}

}

// 08 - OR (48 bits)
// op1 = op1 OR op2
// Afeta -> ZF e SF
void OR(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];

	switch (codigo) {
		// REG - MEM
		case 3:
			reg[op1] = (reg[op1]) | (mem[op2]);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;	
		// MEM - REG
		case 4:
			mem[op1] = (mem[op1]) | (reg[op1]);

			// Setando ZF e SF
			(mem[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(mem[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - REG
		case 5:
			reg[op1] = (reg[op1]) | (reg[op2]);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		// MEM - I
		case 6:
			mem[op1] = (mem[op1]) | (op2);
			// Setando ZF e SF
			((mem[op1]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((mem[op1]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			break;
		// REG - I
		case 7:
			reg[op1] = (reg[op1]) | (op2);

			// Setando ZF e SF
			(reg[op1] == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(reg[op1] >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			AtualizaRegs(reg, op1);
			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}
}

// 09 - CMP
// op1 - op2
void CMP(int16_t *mem, int16_t *reg, int codigo, int IP) {

	int16_t op1 = mem[IP + 1];
	int16_t op2 = mem[IP + 2];

	switch (codigo) {
		// REG - MEM
		case 3:

			// Setando ZF e SF
			((reg[op1] - mem[op2]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((reg[op1] - mem[op2]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			break;	
		// MEM - REG
		case 4:

			// Setando ZF e SF
			((mem[op1] - reg[op1]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((mem[op1] - reg[op1]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);
			
			break;
		// REG - REG
		case 5:
			reg[op1] = (reg[op1] - reg[op2]);

			// Setando ZF e SF
			((reg[op1] - reg[op2]) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((reg[op1] - reg[op2]) >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			break;
		// MEM - I
		case 6:

			// Setando ZF e SF
			(((mem[op1] - op2)) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			(((mem[op1] - op2)) >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			break;
		// REG - I
		case 7:

			// Setando ZF e SF
			((reg[op1] - op2) == 0) ? (reg[12] = 1) : (reg[12] = 0);
			((reg[op1] - op2) >= 0) ? (reg[13] = 0) : (reg[13] = 1);

			break;
		default:
			printf("ERRO: Codigo Operando!\n");
			exit(1);
			break;
	}
}

// 10 - JMP
// Desvia para label indicado.
void JMP(int16_t *mem, int16_t *reg, int IP) {

	int16_t op1 = mem[IP + 1];

	reg[11] = op1;
}

// 11 - JZ
// Se ZF == 1, desvia.
void JZ(int16_t *mem, int16_t *reg, int IP) {

	int16_t op1 = mem[IP + 1];

	if (reg[12] == 1) {
		reg[11] = op1;
	} else {
		reg[11] = reg[11] + 2;		
	}
}

// 12 - JS
// Se SF == 1, desvia.
void JS(int16_t *mem, int16_t *reg, int IP) {

	int16_t op1 = mem[IP + 1];

	if (reg[13] == 1) {
		reg[11] = op1;
	} else {
		reg[11] = reg[11] + 2;		
	}
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
		reg[op1] = mem[reg[10]];

		AtualizaRegs(reg, op1);
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

	scanf("%" SCNx16, &input);
	
	// Setando ZF e SF
	(input == 0) ? (reg[12] = 1) : (reg[12] = 0);
	(input >= 0) ? (reg[13] = 0) : (reg[13] = 1);	
	
	// REG
	if (codigo == 1) {

		reg[op1] = input;

		AtualizaRegs(reg, op1);
		
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