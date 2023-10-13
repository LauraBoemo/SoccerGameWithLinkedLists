CC=gcc
CFLAGS=-Wall
EXECUTABLE=main
main: linkedlist.o main.c
	$(CC) $(CFLAGS) linkedlist.o main.c -o $(EXECUTABLE)
linkedlist.o: linkedlist.h 