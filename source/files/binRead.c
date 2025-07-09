#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *filename;

    /* char vector[10] = {}; */

    /* To read a single value */
    float value;

    /* Open in write binary mode. .dat is widely used for binary files, also .bin */
    filename = fopen("info.bin", "rb");

    /* Test if open successfully */
    if(filename  == NULL) {
        printf("Error when creating file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */

    /* fread(vector, sizeof(char), 10, filename); */

    /* To store the value in &value */
    fread(&value, sizeof(float), 1, filename);

    printf("%.4f \n", value);

    /* We need a for loop to read each char from vector */
    /* for (int i = 0; i < 10; i++)
        printf("%d ", vector[i]); */

    fclose(filename);
    printf("\nFile successfully read. Goodbye\n");

    return 0;
} /* End main */