#include <stdio.h>
#include <stdlib.h>

/* Union declaration */
union contents{
    unsigned short value;
    unsigned char twoBytes[2];
}; /* end union */

/* Function to record the file - returns a unsigned short */
unsigned short record(union contents *pointer, FILE *fileName);

int main(){
    FILE *dataFile; /* Pointer to file */

    /* Variable cont type union contents */
    union contents cont;

    /* Assign 2178 to value - unsigned short (in the 2 bytes range )*/
    cont.value = 2178;

    /* Test if the file was successfully generated - if 1 True, if 0*/
    if(!record(&cont,dataFile)){ /* First parm - cont address (pointer to union), pointer to file */

        printf("Error when creating file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1); /* Finish the program */

    } /* End if */

    printf("Success!\n");
    return 0;    
} /* End main */

/* A pointer to union contents and fileName pointer as parameter*/
unsigned short record(union contents *pointer, FILE *fileName){

    /* Open fileName in write binary mode and tests if returns NULL - error when creating file */
    if((fileName = fopen("record.dat","wb")) == NULL) return 0;

    /* Using fputc to store values in twoBytes[0] and [1] position */
    fputc(pointer->twoBytes[0], fileName);
    fputc(pointer->twoBytes[1], fileName);

    /* Closes the file and returns 1 */
    fclose(fileName);
    return 1;
} /* End function */
