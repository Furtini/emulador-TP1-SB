################# Makefile ####################
CC=gcc
CFLAGS=-I.
DEPS = operacoes.h carregador.h interpretador.h
OBJ = emulador.o operacoes.o carregador.o interpretador.o

all: emulador

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emulador: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm
clean:
	rm -rf *.o
mrproper:
	rm -rf main
