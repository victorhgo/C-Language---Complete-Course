#include <stdio.h>
#include <stdlib.h>

int main(){
    /* Each port has 1 bit */
    struct reg{
        unsigned P0 : 1;
        unsigned P1 : 1;
        unsigned P2 : 1;
        unsigned P3 : 1;
        unsigned P4 : 1;
        unsigned P5 : 1;
        unsigned P6 : 1;
        unsigned P7 : 1;
    } PORT;

    /* We can access using the . operator*/
    PORT.P0 = 1;
    PORT.P1 = 0;
    PORT.P2 = 1;

    /* What's not initialized is put to zero */

    
}