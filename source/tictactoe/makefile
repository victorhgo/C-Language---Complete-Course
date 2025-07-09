# Makefile for tictactoe
# by Victor Correa

# use the gcc compiler
CC = gcc

# including the -I. flag so gcc can look into the current directory for
# the battlemake.h file
CFLAGS = -I.

tictactoe: tictactoe.o functions.o
	$(CC) -o tictactoe tictactoe.o functions.o
