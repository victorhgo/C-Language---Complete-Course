/* Here we will declare all Functions prototypes

This file will be called by gcc using the flag -I. */

void drawBoard(char (*matrix)[10]);

/* Function to randomize numbers based on seeds*/
void newSeed(char (*matrix)[10]);
/* Function to convert column char to column int*/
unsigned mapColumns(char *col); 

/* Function to show the score */
void showScore(unsigned *hit, unsigned *misses);

/* char gameOver(char sort); */