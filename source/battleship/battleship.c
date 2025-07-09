/*  ---  C Implementation of Battleship --- version 0.9 (playable)

This is a simple implementation of Battleship for C, as a part of my C language
certification which will help me understand better the utilization of vectors
in the form of vector[][] (matrices).

Also a nice implementation of the time() function (time.h library) which will allow
the program to generate random numbers based on the hardware time.

To do: 

- Implement gameOver() function with beeps - started but needs further development
- Make the ships invisible to increase the level of difficult:
> For that we can generate the board, randomize the targets but only prints the board
with an * for hit targets and something else for missed ones

> drawBoard() function can be ignored when 

- Implement a gameWin() function when all targets are over
- Implement makefile (done on 04/Jul/2025)

- Press (E) to exit the game not working yet

by Victor Correa  */
#include<stdio.h>
#include<stdlib.h>

/* Time function - Will be used to generate random numbers */
#include<time.h>

/* Include battlemake.h which contains all functions prototypes */
#include"battlemake.h"

/* to use tolower() function or toupper()*/
#include<ctype.h>

int main(){

    char board[8][10] = {0},     /* Store enemy positions */
         option = 'p',           /* User option - Start as  */
         sort = 1,               /* Flag for sorts*/
         col = 0;                /* Columns*/

    unsigned row = 0,            /* Rows (1 to 8) */
             hit = 0,          	 /* Targets successfully hit*/
             miss = 0;           /* Miss shots */

/* Starting the sorting loop */
    do {
        if(sort){
            system("clear");  	 /* To clean the screen */
            newSeed(board);      /* Apply a random seed */
            drawBoard(board);    /* To draw the board */
        } else {
            printf("Invalid option\n");
            sort = 1;            /* Set flag for a new sort as true */
        } /* end if-else sort */

            printf("Press (S) to sort again\n");
            printf("Press (P) to play the game\n");
            printf("Press (E) to exit the game\nEnter >>> ");
            scanf(" %c", &option);

            if (tolower(option) != 's') sort = 0; 	/* If different than S put the sort flag to False */

    } while(tolower(option) != 'p'); 			  	/* end this loop when start to play*/

    system("clear");
    drawBoard(board);
	showScore(&hit, &miss);

    while(1){
        printf("Enter a position to shot >>> ");
        scanf(" %c%d", &col, &row);

        system("clear");

		/* If the selected position contains a boat (<) then you hit the target, incrementing the hits variable */
        if(board[row - 1][mapColumns(&col)] == '<'){ 

            board[row-1][mapColumns(&col)] = '*';
            hit++;
            putchar('\a'); /* Beep sound */

        } else {
            miss++;
			/* Put a beep here too */
            if(miss > 5){
                printf("You lost. Game Over!!!\n");
                exit(0);
            } /* End if mistakes */
        } /* End else */

        drawBoard(board);
		showScore(&hit, &miss);

    } /* End while loop */

    return 0;

}