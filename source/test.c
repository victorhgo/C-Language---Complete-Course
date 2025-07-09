#include<stdio.h>
#include<stdlib.h>

/* number will be the vector's index */
int number = 5;

void function(int vector[], int number);

int main(){
    int vec[number];

    function(vec, number);

    return 0;
}

void function(int vector[], int number){

    for(int i = 0; i < number; i++){
        printf("vector[%d] = %d\n", i, vector[i]);
    }
}