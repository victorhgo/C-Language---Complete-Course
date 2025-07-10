#include <stdio.h>
#include <stdlib.h>

/* Enable string functions like strcpy(), strlen() */
#include <string.h>

int main(){

    /* Pointer for the initial address */
    char *palloc;

    /* 8 bytes that palloc will point to.
        No need for casting it as (char *)malloc(8 * sizeof(char))
    because we are dealing with char */
    palloc = malloc(13);

    /* Test the allocation if successful */
    if(!palloc){
        puts("Insufficient memory\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* End check */

    /* Copy the string into palloc */
    strcpy(palloc,"Hello there,"); /* 13 bytes + 1 null character */

    /* Reallocate memory to concatenate another string into palloc */
    palloc = realloc(palloc, 22);

    if(!palloc){
        puts("Insufficient memory\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* End check */

    /* Concatenates Victor to palloc */
    strcat(palloc, " Victor"); /* 7 bytes */
    
    /* Prints palloc to see if successfully concatenates */
    printf(palloc);
    free(palloc);

    putchar('\n');
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

    return 0;
}