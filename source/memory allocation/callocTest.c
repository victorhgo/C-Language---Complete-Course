#include <stdio.h>
#include <stdlib.h>

long *vectorLong(unsigned amount);

int main(){
    long *pointer;
    register int i;

    /* Pointer will reserve 20 longs and pointer will point to
    20 x 4 bytes = 80bytes reserved space */
    pointer = vectorLong(20);

    /* Store data in pointer */
    for(i = 0; i < 20; i++){
        pointer[i] = i + 1;     /* 0 to 20 */
    } /* End receiving for */

    /* Prints the data stored in pointer */
    for(i = 0; i < 20; i++){
        printf("pointer[%2d] = %2ld\n", i, pointer[i]);
    } /* End printing for */

    /* Freeing the allocated space */
    free(pointer);

    return 0;

} /* End main */


long *vectorLong(unsigned amount){
    long *palloc;

    /* Reserves dynamic memory with calloc */
    palloc = calloc(amount, sizeof(long));

    /* Tests if the allocation was successful */
    if(!palloc){
        printf("Insufficient Memory!\n");
        exit(1);
    } /* End if */

    return palloc;

} /* End function */