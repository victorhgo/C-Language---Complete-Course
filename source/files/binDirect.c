#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename;

    /* Open in read binary mode */
    filename = fopen("info2.bin", "wb");

    /* Test if file open read successfully */
    if(filename  == NULL) {
        printf("Error when reading file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* Putting some characters in our file */
    fputc(0xAA, filename);
    fputc(0xAB, filename);
    fputc(0xAC, filename);
    fputc(0xAD, filename);
    fputc(0xAE, filename);
    fputc(0xAF, filename);

    /* ld = ftell returns a long 
     - The ftell() function obtains the current value of the file position
     indicator for the stream pointed to by stream.  */
    printf("Pointer's actual address: %ld\n", ftell(filename));

    /* Rewind sets the pointer back to 0 */
    rewind(filename);
    printf("Pointer's actual address: %ld\n", ftell(filename));

    /* We can also use fseek to point the pointer to any position in the file */

    /* Close the file */
    fclose(filename);
    printf("File successfully written.\n");


    return 0;
} /* End main */