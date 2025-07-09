#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename;

    /* Open in write binary mode */
    filename = fopen("info3.bin", "wb");

    /* Test if file open read successfully */
    if(filename  == NULL) {
        printf("Error when writing file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    fputc(0xBC, filename);
    fputc(0x3C, filename);

    /* To create a partition on address 0x0B (11) -
    
    SEEK_SET from the beginning of the file, move 11 positions (0x0B)

    */
    fseek(filename, 0xFF, SEEK_SET);

    fputc(0xA1, filename);
    fputc(0x74, filename);
    fputc(0xA5, filename);
    fputc(0xC3, filename);
    fputc(0xE1, filename);
    fputc(0x93, filename);
    fputc(0x01, filename);
    fputc(0x43, filename);

    /* Set back -20 positions from current position */
    fseek(filename, -20, SEEK_CUR);

    fputc(0x00, filename);
    fputc(0x01, filename);
    fputc(0x02, filename);
    fputc(0x03, filename);
    fputc(0x04, filename);
    fputc(0x05, filename);
    fputc(0x06, filename);
    fputc(0x07, filename);
    fputc(0x08, filename);
    fputc(0xFF, filename);

    /* Close the file */
    fclose(filename);
    printf("File successfully written.\n");

    return 0;
} /* End main */