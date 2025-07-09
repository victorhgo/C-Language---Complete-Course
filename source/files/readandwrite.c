#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *readFile, *writeFile;

    int character,
        counterA = 0, /* Let's count how many A letters are there in the text */
        counterLines = 0; /* Let's count how many lines in text */

    readFile = fopen("readfile.txt", "r");
    writeFile = fopen("writefile.txt", "w");

    if(readFile == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for readFile */

    if(writeFile == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    /* Read readFile and write to writeFile */
    while ((character = fgetc(readFile)) != EOF){
        printf("%c", character);

        /* Let's count how much letter A has the text */
        if(tolower(character) == 'a') counterA++;

        /* Let's count how many lines. 0x0A (line feed) */
        if(character == 0x0A) counterLines++;

        /* Let's remove every letter E from the text */
        /* if(tolower(character) == 'e') character = ' '; */

        /* We will copy the content from readFile to writeFile */
        fputc(character, writeFile);
    }
    
    /* Close the files */
    fclose(readFile);
    fclose(writeFile);

    /* Print the findings */
    printf("\nThis file has %d letter A\n", counterA);
    printf("This text has %d lines\n", counterLines + 1);
    
    /* Counter lines + 1 to get the correct number of lines */

}