#include <stdio.h>
#include <stdlib.h>

/* Enable string functions like strcpy(), strlen() */
#include <string.h>

int main(){
    FILE *filename;

    /* Pointer that will point the initial address memory block */
    unsigned char *palloc;

    /* Will store the file's size in bytes */
    unsigned long int numBytes = 0;

    /* character will store the read chars */
    int character,
        i = 0;

    /* Opens code.txt in read mode and test it */
    filename = fopen("alchemy.txt", "r");

    if (filename == NULL){
        printf("Error when reading the file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(0);
    } /* End check filename */

    printf("File successfully opened!!!\n");

    /* Read the entire file incrementing numBytes */
    while((character = fgetc(filename)) != EOF){
        numBytes++;
    } /* End while */

    /* numBytes returns the file's size */
    printf("File's size: %lu bytes\n", numBytes);

    /* Returns the filename pointers to the file's beginning */
    rewind(filename);

    /* Dynamic Memory Allocation - numBytes * sizeof(char) to allocate a space that is
    the amount of numBytes times the size of char (for portability )
    
    The casting (unsigned char *) make it compatible for palloc */
    palloc = (unsigned char *) malloc(numBytes * sizeof(char));

    /* Test the memory allocation */
    if (palloc == NULL){
        printf("Insufficient memory\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(0);
    } /* End test allocation */

    /* To fill the dynamically allocated vector palloc */
    while((character = fgetc(filename)) != EOF){

        /* if i <= numByte keep storing the char into palloc[i] */
        if(i <= numBytes){
            palloc[i] = (unsigned char) character;
        } /* end if */

        i++;
    } /* End while */

    printf("Now printing from palloc pointer...\n");

    /* Print palloc vector char by char following the file's size */
    for(i = 0; i < numBytes; i++){
        printf("%c", palloc[i]);
    } /* End for */

    /* Close filename */
    fclose(filename);
    /* Free the allocated memory */
    free(palloc);

    printf("\n> File successfully read. Goodbye :)\n");
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

    return 0;
    
} /* End main */