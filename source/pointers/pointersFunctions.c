#include<stdio.h>

/* void function(int vector[], int size);

int main(){
    int vector1[10] = {7, 11, 19, 23, 29};

    - function(vector1,10) is the same as
    function(&vector1[0],10);

}

void function(int vector[], int size){
    for(int i = 0; i < size; i++){
        printf("Vector[%d] = %d\n", i, vector[i]);
    }

} End function */

/* So we could refactorate this code as: */

/* Using a pointer as function's parm */
void function(int *vector, int size);

int main(){
    int vector1[10] = {7, 11, 19, 23, 29};

    function(vector1,10);


}

/* Using a pointer as function's parm */
void function(int *vector, int size){
    for(int i = 0; i < size; i++){
        printf("Vector[%d] = %d\n", i, vector[i]);
    }

} /* End function */

