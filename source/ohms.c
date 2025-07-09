#include<stdio.h>

/* to use atof() ascii to float */
#include<stdlib.h>

/* values will count how many arguments were passed and readings will store all arguments */
int main(int values, char *readings[]){

    printf("Resistance: ");

    /* Starting at 1 and increment 2 to get voltage and current's pair respectively */
    for(register int i = 1; i < values; i += 2){

        /* Return the current following Ohm's law R = V / I */
        printf("%.2f | ", (atof(readings[i]) / atof(readings[i + 1])));

    } /* End for*/

    printf("ohms\n");
    
    return 0;
} /* End main */