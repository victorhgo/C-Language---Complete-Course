#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename;

    char vector[10] = {23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

    /* long vector[4] = {4, 8, 12, 1600}; */

    /* float vector[2] = {3.1415, 1.776}; */

    float value = -3.1415;

    /* Open in write binary mode. .dat is widely used for binary files, also .bin */
    filename = fopen("info.bin", "wb");

    /* Test if open successfully */
    if(filename  == NULL) {
        printf("Error when creating file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* Pass the vector, sizeof(char) to get the size of char elements, storing 10 elements at filename */
    fwrite(vector, sizeof(char), 10, filename);

    /* To write a single value we need to pass the address */
    /* fwrite(&value, sizeof(float), 1, filename); */


    /* For float value = 3.1415 the HEX is 56 0e 49 40 when positive 
    
    But for -3.1415 the HEX value is: 56 0e 49 C0 

    The MSB (most significant byte) 40 - 0100 0000 for positive number
    for negative number C0: 1100 0000

    */

    fclose(filename);
    printf("File successfully written.\n");

    return 0;
} /* End main */