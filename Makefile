################# Makefile ####################
CC=gcc
CFLAGS=-I.
DEPS = operacoes.h controle.h
OBJ = emulador.o operacoes.o controle.o

all: emulador

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emulador: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm
clean:
	rm -rf *.o
mrproper:
	rm -rf main
