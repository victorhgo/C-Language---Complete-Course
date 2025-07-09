/* Development of functions to be used in game */
#include <stdio.h>
#include <stdlib.h>

/* To use toupper() function */
#include<ctype.h>

/* To utilize the boolean functionalities */
#include <stdbool.h> 

#include"functions.h"


void drawBoard(char (*matrix)[3]){
    putchar('\n');
    printf("    A    B   C\n");
    printf("   _____________\n");
    printf(" 0 | %c | %c | %c |\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("   -------------\n");
    printf(" 1 | %c | %c | %c |\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("   -------------\n");
    printf(" 2 | %c | %c | %c |\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    printf("   -------------\n");
}

bool verifyRow(char (*matrix)[3]){
    for(int i = 0; i < 3; i++){
        /* Store char from matrix[i][0] to verify during the for loop */
        char row = matrix[i][0];

        /* Verify each Row with for loop */
        if ((row == 'X' || row  == 'O') && matrix[i][1] == row && matrix[i][2] == row){
            printf("Rows: %c is winner\n", row);
            return true;
        } /* End if verification */
    } /* End for loop */
    return false; /* No winners */
}

bool verifyCol(char (*matrix)[3]){
    for(int i = 0; i < 3; i++){
        /* Store char from matrix[i][0] to verify during the for loop */
        char col = matrix[0][i];

        /* Verify each column with for loop */
        if ((col == 'X' || col  == 'O') && matrix[1][i] == col && matrix[2][i] == col){
            printf("Cols: %c is winner\n", col);
            return true;
        } /* End if verification */
    } /* End for loop */
    return false; /* No winners */
}

bool verifyDiag(char (*matrix)[3]){
    /* First diagonal - Store char from matrix[i][0] to verify during the for loop */
    char first = matrix[0][0];

    /* Verify the diagonal1 / */
    if((first == 'X' || first == 'O') && matrix[1][1] == first && matrix[2][2] == first){
        printf("Diag1: %c is winner\n", first);
        return true;
    } /* End if first diagonal */

    /* Second diagonal - Store char from matrix[i][0] to verify during the for loop */    
    char second = matrix[0][2];
    
    /* Verify the diagonal2 \ */
    if((second == 'X' || second == 'O') && matrix[1][1] == second && matrix[2][0] == second){
        printf("Diag2: %c is winner\n", second);
        return true;
    } /* End if second diagonal */

    return false; /* No winners */
}

unsigned mapColumns(char *columns){

  switch(toupper(*columns)){
    case 'A': return 0; break;  
    case 'B': return 1; break;     
    case 'C': return 2; break;   
  } /* end switch */ 
  return 10;
}

/* 
    ROWS: 
    if((matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') || (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')){
        printf("%c is winnerA\n", matrix[0][0]);
        return true;
    }
    if((matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') || (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')){
        printf("%c is winnerB\n", matrix[1][0]);
        return true;
    }
    if((matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') || (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')){
        printf("%c is winnerC\n", matrix[0][0]);
        return true;
    } else {
        return false;
    } 
      
    COLS: 
    if((matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') || (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')){
        printf("%c is winner A\n", matrix[0][0]);
        return true;
    }
    if((matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') || (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')){
        printf("%c is winner B\n", matrix[1][0]);
        return true;
    }
    if((matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') || (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[1][2] == 'O')){
        printf("%c is winner C\n", matrix[0][0]);
        return true;
    } else {
        return false;
    }    
    
    Diag:
    if((matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') || (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')){
        printf("%c is winner A\n", matrix[0][0]);
        return true;
    }
    if((matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X') || (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')){
        printf("%c is winner B\n", matrix[1][0]);
        return true;
    } else {
        return false;
    }
    
    
    */