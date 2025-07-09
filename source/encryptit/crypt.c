#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *message, *encryptFile;

    int character;

    message = fopen("message.txt", "r");
    encryptFile = fopen("encrypt.txt", "w");

    if(message == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for readFile */

    if(encryptFile == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    printf("Encryption in progress...\n");
    /* Read readFile and write to writeFile */
    while ((character = fgetc(message)) != EOF){
        printf("%c", character + 3);
        /* Write the new character in the encryptfile - 
        Each character will advance + 3 in the ASCII */
        fputc(character + 3, encryptFile);
    }
    
    /* Close the files */
    fclose(message);
    fclose(encryptFile);

    /* Print the results */
    printf("\nFile successfully encrypted!!!\n");
}