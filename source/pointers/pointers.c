#include<stdio.h>

int main(){
    int vector[10] = {1, 3, 5};
    int *pointer;

    // pointer = &vector[0];

    /* Since the vector's name is a pointer to the first element, we can simply say: */
    pointer = vector;

    printf("vector = %X\n", vector);
    printf("pointer = %X\n", pointer);

    printf("*pointer = %d\n", *pointer); /* This will print the content of vector[0] using *pointer */
    printf("vector[0] = %d\n", vector[0]); /* This will print the content of vector[0] */

/* We can also manipulate data inside a vector using pointers */
    *pointer = 15; /* It will change vector[0] from 1 to 15 */

    printf("vector[0] = %d\n", vector[0]); /* it will print 15 now instead of 1 */
    printf("*pointer = %d\n", *pointer);

/* We can also modify the vector[1] index using the same pointer like: */

    printf("vector[1] = %d\n", vector[1]); /* This will print the content of vector[0] */

    /* We can also manipulate data inside a vector using pointers */
    *(pointer+1) = 17; /* It will change vector[0 + 1] from 3 to 17 */

    printf("vector[1] = %d\n", vector[1]); /* it will print 17 now instead of 3 */
    printf("*(pointer+1) = %d\n", *(pointer+1));

    return 0;
}