/* Reads a binary file and follow this structure, displaying HEX and also the file size

00 01 02 03 04 05 06 07 08 09
-- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- --
...
File size: -- bytes

The bytes vector should be dynamically allocated
*/
#include <stdio.h>
#include <stdlib.h>

/* main function */
int main(){
    FILE *binaryFile;

    /* This pointer will point to the binary file */
    unsigned char *binPointer;

    /* Will store the file's size (in bytes)*/
    unsigned long int sizeBytes = 0;

    /* This character variable will store each character */
    int character,
            i = 0; /* Increment */

    /* Open the file in binary read mode and test it */
    binaryFile = fopen("copy.bin", "rb");

    if(binaryFile == NULL){
        printf("Error when reading file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(0);
    } /* End if for binaryFile testing */

    /* Read the entire file incrementing sizeBytes */
    while((character = fgetc(binaryFile)) != EOF){
        sizeBytes++;
    } /* End while */

    /* TEST PURPOSE ONLY - To be removed - sizeBytes returns the file's size */

    /* Returns the binPointer pointers to the file's beginning */
    rewind(binaryFile);

    /* Stores all the content into a vector */

    /* Dynamic Memory Allocation - numBytes * sizeof(char) to allocate a space that is
    the amount of numBytes times the size of char (for portability )
    
    The casting (unsigned char *) make it compatible for palloc */
    binPointer = (unsigned char *) malloc(sizeBytes * sizeof(char));

    /* Test the memory allocation */
    if (binPointer == NULL){
        printf("Insufficient memory\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(0);
    } /* End test allocation */

    /* Stores the content of file into the pointer */

    /* To fill the dynamically allocated vector binPointer */
    while((character = fgetc(binaryFile)) != EOF){
        /* if i <= numByte keep storing the char into binPointer[i] */
        if(i <= sizeBytes){
            binPointer[i] = (unsigned char) character;
        } /* end if */

        i++;
    } /* End while */

    /* Display the vector in the right format 00 to 09 then new line */
    printf("       00 01 02 03 04 05 06 07 08 09\n");
    printf("       -- -- -- -- -- -- -- -- -- --");
    /* Print palloc vector char by char following the file's size */
    for(i = 0; i < sizeBytes; i++){
        /* Each 10 bytes inserts a new line and also show the current line */
        if (i % 10 == 0){
            putchar(0x0A); /* Inserts a new line */
            printf("%.4X | ", i);
        }
        printf("%.2X", binPointer[i]);
        putchar(0x20); /* Space in hex code -  to display data like 00 10 AB*/
    } /* End for */

    printf("\nFile size: %lu bytes\n", sizeBytes);
    /* Closes the file and free the pointer */

} /* End main*/
