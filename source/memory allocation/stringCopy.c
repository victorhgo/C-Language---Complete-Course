#include <stdio.h>
#include <stdlib.h>

/* Enable string functions like strcpy(), strlen() */
#include <string.h>

int main(){
    /* String with 100 bytes reserved to it*/
    char string[100],

    /* This pointer will point to the first address of memory's block */
         *palloc;


    /* Enter the string and store it */
    printf("Enter the string > ");
    gets(string);

    /* Allocates memory 
    
    We verify the size of string with strlen(string) and sums +1
    to reserve a space for the null character.
    
    Cast this pointer to char * with (char *) to return to the pointer
    palloc */

    palloc = (char *)malloc(strlen(string) + 1);

    /* We verify the size of string with strlen(string) and sums +1
    to reserve a space for the null character.
    
    Cast this pointer to char * with (char *) to return to the pointer
    palloc */

    /* Check if the memory was successfully allocated */
    if(palloc == NULL) puts("Insufficient memory\n");

    /* Copy the string*/
    else{

        /* Copy the string to palloc */
        strcpy(palloc,string);

        putchar(0x0A); /* New line */
        printf(string); /* print the original string */
        putchar(0x0A);  /* New line */
        printf(palloc); /* Print the palloc */

        /* This function will free the allocated space */
        free(palloc);

    } /* End else */

} /* End main */