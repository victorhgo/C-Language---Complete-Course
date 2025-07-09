#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *readFile;

    int character;

    /* Create a file called test.txt at textfiles and open as append to add new info */
    readFile = fopen("textfiles/test.txt", "a");

    if(readFile == NULL) {
        printf("Error creating the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    fputs("Writing on an external file1", readFile);
    /* New line */

    fclose(readFile);

    return 0;
}