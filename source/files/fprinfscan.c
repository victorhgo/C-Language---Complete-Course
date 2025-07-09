#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *readFile, *writeFile;

    int character;

    readFile = fopen("text.txt", "r");
    writeFile = fopen("newtext.txt", "w");

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
    while (fscanf(readFile, "%c", &character) != EOF){
        fprintf(writeFile, "%c", character);
    } /* End while */
    
    /* We can use fputs to write a new string in the file */
    fputs("Writing some content using fputs() function", writeFile);
    /* Fputc to put a new line */
    fputc(0x0A, writeFile);
    /* Writing a new line on the file*/
    fputs("Writing a new line on the file", writeFile);
    /* Fputc to put a new line */
    fputc(0x0A, writeFile);

    printf("File successfully copied\n");

    /* Close the files */
    fclose(readFile);
    fclose(writeFile);

    return 0;
}