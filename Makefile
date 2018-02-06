CC = gcc
FLAGS = -Wall -std=c99
LIBS = main fraction


default:
	$(CC) $(flags) -c fraction.c
	$(CC) $(flags) -c main.c
	$(CC) $(flags) -o main main.o fraction.o
	@rm -rf *.o