CC = gcc
CFLAGS = -Wall -g

all: prog

autom.o: autom.c autom.h
	$(CC) $(CFLAGS) -o autom.o -c autom.c

liste.o: liste.c autom.h
	$(CC)  $(CFLAGS) -o liste.o -c liste.c

main.o: main.c liste.c liste.o autom.h
	$(CC) $(CFLAGS) -o main.o -c main.c

prog: main.o autom.o liste.o
	$(CC) $(CFLAGS) -o prog main.o autom.o

clean:
	rm -f *.o

mrproper: clean
	rm -f prog
