// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174
#ifndef OPERACOES_H
#define OPERACOES_H

// -----------
// Instrucoes:

// 01 - MOV 
void MOV(int16_t *mem, int16_t *reg, int8_t codigo, int IP);

// 02 - ADD	(48 bits)
// op1 = op1 + op2
//Afeta - > ZF e SF
void ADD(int16_t *mem, int16_t *reg, int codigo, int IP);

// 03 - SUB (48 bits)
// op1 = op1 - op2
// Afeta -> ZF e SF
void SUB(int16_t *mem, int16_t *reg, int codigo, int IP);

// 04 - MUL (32 bits)
// caso byte: AX = AL * op1
// caso word: AX = AX * op1
void MUL(int16_t *mem, int16_t *reg, int codigo, int IP);

// 05 - DIV (32 bits)  
// caso byte: AL = AX/op1
//			  AH = resto da div
// caso word: AX = AX/op1	
//			  BX = resto da div
void DIV(int16_t *mem, int16_t *reg, int codigo, int IP);

// 06 - AND (48bits)
// op1 = op1 AND op2
// Afeta ZF e SF
void AND(int16_t *mem, int16_t *reg, int codigo, int IP);

// 07 - NOT (32 bits)
// op1 = ~op1
// Afeta -> ZF e SF
void NOT(int16_t *mem, int16_t *reg, int codigo, int IP);

// 08 - OR (48 bits)
// op1 = op1 OR op2
// Afeta -> ZF e SF
void OR(int16_t *mem, int16_t *reg, int codigo, int IP);

// 09 - CMP (48 bits)
// op1 - op2
// Afeta -> ZF e SF
void CMP(int16_t *mem, int16_t *reg, int codigo, int IP);

// 10 - JMP
// Desvia para label indicado.
void JMP (int16_t *mem, int16_t *reg, int IP);

// 11 - JZ
// Se ZF == 1, desvia.
void JZ(int16_t *mem, int16_t *reg, int IP);

// 12 - JS
// se SF == 1, desvia.
void JS(int16_t *mem, int16_t *reg, int IP);

// 13 - CALL
// Chama procedimento
void CALL(int16_t *mem, int16_t *reg, int IP);

// 14 - RET
// Retorna de um procedimento.
void RET(int16_t *mem, int16_t *reg, int IP);

// 15 - PUSH
// Empilha valor na memoria.
void PUSH (int16_t *mem, int16_t *reg, int codigo, int IP);
   
// 16 - POP
// Desempilha valor da memoria.
void POP (int16_t *mem, int16_t *reg, int codigo, int IP);   
   
// 17 - DUMP
// Imprime todos os registradores. Menos os lower e higher.
void DUMP(int16_t *reg);

// 18 - READ
// Le hexa do teclado e salva em reg ou mem. 
// Afeta -> ZF e SF
void READ(int16_t *mem, int16_t *reg, int8_t codigo, int IP);

// 19 - WRITE
// Escreve na tela valor do registrado ou posicao da memoria pedido.
void WRITE(int16_t *mem, int16_t *reg, int codigo, int IP);

// 20 - HLT
int HLT();

#endif