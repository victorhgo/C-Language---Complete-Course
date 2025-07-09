/* Let's implement a datastructure - stack in C (Last in, First Out)*/
#include<stdio.h>
#include<stdlib.h>

#define LEVELS 10

/* Function prototypes */
void displayStack(); /* Display the stack */
void push(int i); /* Inserts data in the stack - push */
int pop(); /* Removes data from the stack - pop */


/* Global Variables */
int *pointer1,
    *pointer2,
    stack[LEVELS],
    counter = 0;

int main(){

    int dataStack,
        option;

    /* Both pointers are pointing to the stack's initial address */
    pointer1 = stack;
    pointer2 = stack;

    for( ; ; ){
        printf("1 - Show Stack\n");
        printf("2 - Insert data\n");
        printf("3 - Remove data\n");
        printf("4 - Exit\n");
        printf(">>> ");
        scanf("%d", &option);

        switch(option){
            case 1:
                displayStack();
                /* Press any key to continue on MacOS */
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
                break;
            case 2:
                printf("Enter integer >>> ");
                scanf("%d", &dataStack);
                push(dataStack);
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(0);
        } /* End switch*/

        /* Clear screen */
        system("clear");

    } /* End for */

}

void displayStack(){
    /* Display the stack */
    for(int i = 0; i <= counter; i++){
        printf("Stack level %d: %d\n", i, stack[i]);
    } /* End for */

}

void push(int value){

    /* This variable will generate a delay */
    register long t;

    /* On each push we increment the address pointed by pointer1 */
    pointer1++;

    /* Increment the data counter */
    counter++;

    if(pointer1 == (pointer2 + LEVELS)){ /* To see if the stack is full or not*/
        printf("STACK OVERFLOW!!!\n");
        exit(0);

    } else {
        printf("Added!\n");

    } /* end if/else */

    /* 1E7 = 10000000 iterations */
    for(t = 0; t < 1E9; t++); /* Delay */

    *pointer1 = value; /* Store the value in pointer1 */
}

int pop(){
    register long t; /* Same delay variable as above */

    /* If they are pointing to the same address, the stack is empty */
    if(pointer1 == pointer2){
        printf("STACK IS EMPTY\n");
        for(t = 0; t < 1E9; t++); /* Delay */
        return 0;
        
    } else {
        printf("Removed\n");
    } /* End if-else */

    for(t = 0; t < 1E9; t++); /* Delay */

    pointer1--; /* Subtract one address */

    counter--; /* Decrement the datacounter */

    /* Return the value of */
    return *(pointer1+1); /* To return what was removed */
}

