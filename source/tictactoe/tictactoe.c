/*  ---  C Implementation of Tictactoe --- version 1.0 (playable)

This is a simple implementation of Tictactoe for C, as a part of my C language
certification which will help me understand better the utilization of vectors
in the form of vector[][] (matrices).

To do: 
- Implement verifyWinner() function to verify winners without the need of many ifs
- Implement a simple AI to play against computer
- Implement makefile (done on 06/Jul/2025)

by Victor Correa  */
#include <stdio.h>
#include <stdlib.h>

/* To utilize the boolean functionalities */
#include <stdbool.h> 

#include"functions.h"

int main(){

    int plays = 0,
        row = 0;
    
    char col,
         board[3][3] = {0x20, 0x20, 0x20,
                        0x20, 0x20, 0x20,               
                        0x20, 0x20, 0x20},
         flag;
    
    /* Maybe I can turn this into a function - firstRounds() ?*/
    while(plays < 4){
        drawBoard(board);

        flag = 1;
        while(flag){
            printf("X >> ");
            scanf(" %c%d", &col, &row);

            /* If the selected position contains a empty space (0x20) put the marker and increment plays */
            if(board[row][mapColumns(&col)] == 0x20){
                board[row][mapColumns(&col)] = 'X';
                plays++;
                flag = 0;

            } else {
                printf("Invalid placement, try again\n");
                flag = 1;
            }
        }

        drawBoard(board);
        
        flag = 1;
        while(flag){

            printf("O >> ");
            scanf(" %c%d", &col, &row);

            /* If the selected position contains a empty space (0x20) put the marker and increment plays */
            if(board[row][mapColumns(&col)] == 0x20){
                board[row][mapColumns(&col)] = 'O';
                plays++;
                flag = 0;

            } else {
                printf("Invalid placement, try again\n");
                flag = 1;
            }
        }
    
    } /* End first while */

    printf("First part completed\n");
    drawBoard(board);
    /* Check if there's a winner - can be also a function checkWinner() */
    if(verifyRow(board)) return 0;

    if(verifyCol(board)) return 0;

    if(verifyDiag(board)) return 0;

    while(1){

        flag = 1;
        while(flag){
            printf("X >> ");
            scanf(" %c%d", &col, &row);

            /* If the selected position contains a empty space (0x20) put the marker and increment plays */
            if(board[row][mapColumns(&col)] == 0x20){
                board[row][mapColumns(&col)] = 'X';
                plays++;
                flag = 0;

            } else {
                printf("Invalid placement, try again\n");
                flag = 1;
            }
        } /* End while X*/

        drawBoard(board);

    if(verifyRow(board)) return 0;

    if(verifyCol(board)) return 0;

    if(verifyDiag(board)) return 0;

    if(plays == 9){
        printf("There's no winner\n");
        return 0;
    }
        
        flag = 1;
        while(flag){

            printf("O >> ");
            scanf(" %c%d", &col, &row);

            /* If the selected position contains a empty space (0x20) put the marker and increment plays */
            if(board[row][mapColumns(&col)] == 0x20){
                board[row][mapColumns(&col)] = 'O';
                plays++;
                flag = 0;

            } else {
                printf("Invalid placement, try again\n");
                flag = 1;
            }
        } /* End while O */

    drawBoard(board);

        /* Verify winner */
    if(verifyRow(board)) return 0;

    if(verifyCol(board)) return 0;

    if(verifyDiag(board)) return 0;

    if(plays == 9){
        printf("There's no winner\n");
        return 0;
    }

    } /* End second while*/

    return 0;
} /* End main() */