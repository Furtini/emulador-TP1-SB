// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "operacoes.h"

// -----------
// Instrucoes:

// 01 - MOV (48 bits)
// op1 <- op2
void MOV(int *mem, int *op1, int *op2) {

}

// 02 - ADD	(48 bits)
// op1 = op1 + op2
//Afeta - > ZF e SF
void ADD(int *mem, int *op1, int *op2);

// 03 - SUB (48 bits)
// op1 = op1 - op2
// Afeta -> ZF e SF
void SUB(int *mem, int *op1, int *op2);

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
   
// 17 - DUMP (16 bits)
// Imprime valores de todos os registradores separados por " ".
void DUMP();

// 18 - READ (32 bits)
// Le hexa do teclado e salva em reg ou mem. 
// Afeta -> ZF e SF
void READ(int *mem, int *op1);

// 19 - WRITE (32 bits)
// Escreve na tela valor do operando.
void WRITE(int *mem, int *op1);

// 20 - HLT (16 bits)
// Interrompe execucao.
void HLT();
