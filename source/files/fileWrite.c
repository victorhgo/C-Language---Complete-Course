#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *filename;

    filename = fopen("test.txt", "w");

    /* Test if the file was successfully opened */
    if(filename == NULL) {
        printf("Error\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(1);
    } /* End if */

    /* file put char */
    /* fputc('e', filename); */

/*
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 40; j++){
            fputc('A', filename);
        }
        fputc('\n', filename);
    } */

    fclose(filename);
}