/* Argument passing for the main */
#include<stdio.h>

/* atoi() ascii to int */
#include<stdlib.h>

int main(int argc, char *argv[]){
    int number, square;

    printf("number | square\n");

    for(int i = 0; i < argc; i++){
        number = atoi(argv[i]); /* atoi will convert a string to int */
        square = number * number;

        printf("%2d %3d\n", number, square);
    } /* end for */
} /* end main */

/* after compiling it at squares for instance, call it as ./squares 1 2 3 4*/
