#include<stdio.h>

int main(){
    int variable = 5,
        *pointer = NULL;

    pointer = &variable; /* To store it's value */

    printf("%X - pointer to variable\n", pointer);
    printf("%d - Variable content\n", *pointer);
    printf("Variable will receive a new value now > \n");
    *pointer = 6;
    printf("*pointer++: %d - variable: %d\n", *pointer, variable);

}