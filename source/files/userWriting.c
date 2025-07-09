#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *writeFile;

    char fileName[50];

    printf("Create a new file as >>> ");
    gets(fileName);

    writeFile = fopen(fileName, "w");

    if(writeFile == NULL) {
        printf("Error creating the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    /* We can use fputs to write a new string in the file */
    fputs("Writing this content using fputs() function", writeFile);

    /* Closing the file */
    printf("Closing the file now\n");
    fclose(writeFile);

    printf("Attempting to open the file as read...\n");
    /* Open the file as read now */
    writeFile = fopen(fileName, "r");

    if(writeFile == NULL) {
        printf("Error reading the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    printf("File successfully open as read\n");

    /* Test fgets and print the string */
    if(fgets(fileName, 200, writeFile)) printf(fileName);

    /* Close the file */
    printf("Closing the file now. Goodbye\n");
    fclose(writeFile);

    return 0;
}