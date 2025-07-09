#include<stdio.h>

int main(){
    /* Two vector with different datatypes */
    short vector1[3] = {2, 4, 6},
          *pointer1 = NULL;

    long  vector2[3] = {1, 3, 5},
          *pointer2 = NULL;

    /* each pointer will point to the vector's first address - vector[0] */
    pointer1 = vector1;
    pointer2 = vector2;

    /* *pointer1 = 2 will change the value in vector1 as saying vector1[0] = 2 */
    *pointer1 = 2;

    /* It will change all the vector's stored values following the rules 2 * i or 3 * i */
    for(int i = 0; i < 3; i++){
        *(pointer1 + i) = 2 * i; /* vector1[i] = 2 * i */
        *(pointer2 + i) = 3 * i; /* vector2[i] = 2 * i */
    }

    printf("Vector1 - Vector2\n");

    for(int i = 0; i < 3; i++){
        printf("%d> %2d  - %2d\n", i, vector1[i], vector2[i]);
    }

    return 0;

}