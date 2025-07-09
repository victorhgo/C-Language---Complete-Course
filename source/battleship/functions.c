/* Here we will develop all of the functions 

- Implementation of gameOver() in progress.

*/

#include<stdio.h>
#include<stdlib.h>

/* Time function - Will be used to generate random numbers */
#include<time.h>

/* Include battlemake.h which contains all functions prototypes */
#include"battlemake.h"

/* to use tolower() function or toupper()*/
#include<ctype.h>

void drawBoard(char (*matrix)[10]){
  putchar('\n');   
  printf("       A   B   C   D   E   F   G   H   I   J  \n");
  printf("     _________________________________________\n");   
  printf("  1  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3], matrix[0][4], matrix[0][5], matrix[0][6], matrix[0][7], matrix[0][8], matrix[0][9]);
  printf("     _________________________________________\n");
  printf("  2  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3], matrix[1][4], matrix[1][5], matrix[1][6], matrix[1][7], matrix[1][8], matrix[1][9]);
  printf("     _________________________________________\n");
  printf("  3  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3], matrix[2][4], matrix[2][5], matrix[2][6], matrix[2][7], matrix[2][8], matrix[2][9]);
  printf("     _________________________________________\n");
  printf("  4  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3], matrix[3][4], matrix[3][5], matrix[3][6], matrix[3][7], matrix[3][8], matrix[3][9]);
  printf("     _________________________________________\n");
  printf("  5  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[4][0], matrix[4][1], matrix[4][2], matrix[4][3], matrix[4][4], matrix[4][5], matrix[4][6], matrix[4][7], matrix[4][8], matrix[4][9]);
  printf("     _________________________________________\n");
  printf("  6  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[5][0], matrix[5][1], matrix[5][2], matrix[5][3], matrix[5][4], matrix[5][5], matrix[5][6], matrix[5][7], matrix[5][8], matrix[5][9]);
  printf("     _________________________________________\n");
  printf("  7  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[6][0], matrix[6][1], matrix[6][2], matrix[6][3], matrix[6][4], matrix[6][5], matrix[6][6], matrix[6][7], matrix[6][8], matrix[6][9]);
  printf("     _________________________________________\n");
  printf("  8  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", matrix[7][0], matrix[7][1], matrix[7][2], matrix[7][3], matrix[7][4], matrix[7][5], matrix[7][6], matrix[7][7], matrix[7][8], matrix[7][9]);
  printf("     _________________________________________\n");
  putchar('\n');   
}

/* This function will generate random numbers */
void newSeed(char (*matrix)[10]){
    long capture;
    time(&capture);             /* Based on the OS clock (seconds), we will generate a random seed */
    srand((unsigned)capture);    /* that will use the srand() function */

    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 10; j++){
            unsigned num = rand()%100+1; /* To generate 10 random numbers using the rand() function */
            
            if(num % 2){            /* if odd - write the ship */
                matrix[i][j] = '<';
            } else {                /* if even - empty position (0x20 is empty space)*/
                matrix[i][j] = 0x20; 
            }
        }
    } /* End for loop*/
}

/* Convert the column char to the int for matrix index */
unsigned mapColumns(char *col){

	switch(toupper(*col)){
		case 'A': return 0; break;  
		case 'B': return 1; break;     
		case 'C': return 2; break; 
		case 'D': return 3; break; 
		case 'E': return 4; break; 
		case 'F': return 5; break;  
		case 'G': return 6; break; 
		case 'H': return 7; break; 
		case 'I': return 8; break; 
		case 'J': return 9; break;     
	} /* end switch */
	return 10;    
} /* end mapColumns()*/

void showScore(unsigned *hit, unsigned *misses){
	printf("Targets hit: %d | Missed Shots: %d\n", *hit, *misses);
} /* End showScore()*/

/* char gameOver(char sort){

    char select = 0;
    printf("--- GAME OVER ---\n");

    exit(0);

    printf("Wanna play again?\n");
    printf("Y or N >>> ");
    scanf("%c ", &select);

    if(select != 'Y' && select != 'Y'){
        return sort = 1;
    } else {
        exit(0); Exit program        
    }
} */

