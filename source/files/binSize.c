#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename;

    /* Open in read binary mode */
    filename = fopen("info.bin", "rb");

    /* Test if file open read successfully */
    if(filename  == NULL) {
        printf("Error when reading file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* 0 is the offset, SEEK_END will point to the EOF */
    fseek(filename, 0, SEEK_END);

    /* FTELL will return the pointer's position - which in the EOF */
    printf("%ld bytes\n", ftell(filename));

    /* EOF is the file's size in bytes */

    /* Close the file */
    fclose(filename);
    printf("File successfully written.\n");

    return 0;
} /* End main */