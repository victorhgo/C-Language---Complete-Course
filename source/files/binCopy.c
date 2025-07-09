#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename, *filecopy;

    int character;

    /* Open in read binary mode */
    filename = fopen("info.bin", "rb");

    /* Test if file open read successfully */
    if(filename  == NULL) {
        printf("Error when reading file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* Open in write binary mode */
    filecopy = fopen("copy.bin", "wb");

    /* Test if copy open write successfully */
    if(filecopy  == NULL) {
        printf("Error when creating file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* feof() - find end of file */
    while(!feof(filename)){
        character = fgetc(filename);

        if (!feof(filename))
            fputc(character, filecopy);

    } /* End while */


    /* Close the file */
    fclose(filename);
    fclose(filecopy);
    printf("File successfully written.\n");

    return 0;
} /* End main */