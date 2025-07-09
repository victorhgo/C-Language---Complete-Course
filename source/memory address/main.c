#include<stdio.h>
#include<stdlib.h>

#include"macros.c"


int main(){
    /* 2 bytes - short */
    short *pointer, variable1, variable2, update = 0;

    variable1 = 0;
    pointer = NULL;
    variable2 = 0;

    while(1){

        system("clear");
        mapA;
        mapB;

        printf("variable1,variable2 >>> ");
        /* *c - to insert a character that will be surpassed by scanf*/
        scanf("%hd%*c%hd", &variable1, &variable2);

        system("clear");

        mapA;
        mapB;

        printf("Pointer: \n");
        printf("1 - to point to variable1\n");
        printf("2 - to point to variable2\n");
        printf("Enter option >>> ");

        scanf("%hd", &update);

        if (update == 1){
            pointer = &variable1;
        } else {
            pointer = &variable2;
        }

        system ("clear");
        mapA;
        mapB;

        printf("*pointer >>> ");
        scanf("%hd", pointer);

    } /* End while */

    return 0;

}