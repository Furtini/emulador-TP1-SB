// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 1
// Emulador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior

#ifndef CONTROLE_H
#define CONTROLE_H

#define TAM_MEMORIA 1001

// Inicia memoria.
int16_t *InicializaMemoria();

// Abre arquivo.
FILE *AbreArquivo(const char *nomeArquivo);

// Leitura das instrucoes e salvando na memoria virtualcriada.
// Carregador.
void Carregador(FILE *arq, int16_t *, int *);


#endif	

// ------ Intrucoes ----- 		----- Codigo Operando ------
// 01 - MOV   (48 bits -> 3)		0 - Nenhum Operando
// 02 - ADD	  (48 bits -> 3)		1 - Registrador
// 03 - SUB   (48 bits -> 3)		2 - Memoria
// 04 - MUL   (32 bits -> 2)		3 - Registrador e Memoria
// 05 - DIV   (32 bits -> 2)  		4 - Memoria e Registrador
// 06 - AND   (48 bits -> 3)		5 - Registrador e Registrador
// 07 - NOT   (32 bits -> 2)		6 - Memoria e Imediato
// 08 - OR    (48 bits -> 3)		7 - Registrador e Imediato
// 09 - CMP   (48 bits -> 3)		8 - Imediato
// 10 - JMP   (32 bits -> 2)
// 11 - JZ    (32 bits -> 2)		------ Registradores Geral -----
// 12 - JS    (32 bits -> 2)		0 - AL
// 13 - CALL  (32 bits -> 2)		1 - AH
// 14 - RET   (16 bits -> 1)		2 - AX
// 15 - PUSH  (32 bits -> 2)		3 - BH
// 16 - POP   (32 bits -> 2)		4 - BL
// 17 - DUMP  (16 bits -> 1)		5 - BX
// 18 - READ  (32 bits -> 2)		6 - CL
// 19 - WRITE (32 bits -> 2)		7 - CH
// 20 - HLT   (16 bits -> 1)		8 - CX
