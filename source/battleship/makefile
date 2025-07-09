# ---  C Implementation of Battleship ---
# by Victor Correa

# to use standard gcc
CC=gcc

# including the -I. flag so gcc can look into the current directory for
# the battlemake.h file
CFLAGS=-I.

battleship: battleship.o functions.o
	$(CC) -o battleship battleship.o functions.o