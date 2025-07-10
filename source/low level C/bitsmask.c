#include <stdio.h>
#include <stdlib.h>

void printBin(unsigned char reg);

int main(){
    /* We can have an operator & to keep/remove the mask like*/
    unsigned char reg1 = 0x32;

    printf("No mask: ");
    printBin(reg1);     /* 0011 0010b*/

    /* Reduced &= eq to (reg1 = reg1 & F0)*/
    reg1 &= 0xF0;       /* keep the 4 most significant bits */

    /* AND Operation: 32 = 0011 0010   (we will preserve 0011)
                      F0 = 1111 0000
                 32 & F0 = 0011 0000  = 24hex */

    printf("\nAfter mask: ");
    printBin(reg1);     /* 0011 0000b - preserving 3hex */

}

void printBin(unsigned char reg){

    for (int i = 7; i >= 0; i--){
        (reg>>i) & 1 ? putchar('1') : putchar('0');
    } /* End for */

    printf(" bin\n");
}