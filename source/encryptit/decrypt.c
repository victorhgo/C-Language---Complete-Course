#include <stdio.h>
#include <stdlib.h>

/* To use tolower function */
#include <ctype.h>

int main(){
    FILE *encryptFile, *decryptFile;

    int character;

    encryptFile = fopen("encrypt.txt", "r");
    decryptFile = fopen("decrypt.txt", "w");

    if(encryptFile == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for readFile */

    if(decryptFile == NULL) {
        printf("Error opening the file \n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* Exit check for writefile */

    printf("Decryption in progress...\n");
    /* Read readFile and write to writeFile */
    while ((character = fgetc(encryptFile)) != EOF){
        printf("%c", character - 3);
        /* Write the new character in the decrypt file - 
        Each character will regress - 3 in the ASCII */
        fputc(character - 3, decryptFile);
    }
    
    /* Close the files */
    fclose(encryptFile);
    fclose(decryptFile);

    /* Print the results */
    printf("\nFile successfully decrypted!!!\n");
}