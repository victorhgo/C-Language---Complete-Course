#include <stdio.h>
#include <stdlib.h>

int main(){
    /* Let's manipulate some bits */
    unsigned char reg1 = 0x80; /* bin: 1000 0000*/

    /* .2X to show nibbles and zeros */
    printf("Before: %.2X\n", reg1);
    /* Operators to manipulate bits in C */
    reg1 = ~reg1;              /* bin: 0111 1111 - 7 F*/
    printf("After ~: %.2X\n", reg1);

    /* Another operator - shift right >> shift_times */

    reg1 = reg1 >> 1; /* Will shift from 0111 1111 to 0011 1111*/
    printf("After shifting right 1 time: %.2X\n", reg1); /* 3F */

    reg1 = reg1 >> 3; /* Will shift from 0011 1111 to 0000 0111 */
    printf("After shifting right 3 times: %.2X\n", reg1); /* 07 */

    /* Shift left << same as shift right */
    reg1 = reg1 << 5; /* Will shift from 0000 0111 to 1110 0000 */
    printf("After shifting left 5 times: %.2X\n", reg1); /* E0 */
    printf(" End operations with register1\n");

    /* Some logical operations - AND (&), OR and XOR */
    reg1 = 0x27; /* 0010 0111 */

    unsigned char reg2 = 0x64, /* 0110 0100 */
                  reg3;

    /* AND Operation & */
    reg3 = reg1 & reg2; /* 27 AND 64 = 24hex */

    /* AND Operation: 27 = 0010 0111
                      64 = 0110 0100
                 27 & 24 = 0010 0100  = 24hex */
   
    printf("Reg1 & Reg2 = %.2X\n", reg3);

    /* OR Operation | */
    reg3 = reg1 | reg2; /* 27 OR 64 = 67hex */

    /* OR  Operation: 27 = 0010 0111
                      64 = 0110 0100
                 27 | 24 = 0110 0111  = 67hex */
    
    printf("Reg1 | Reg2 = %.2X\n", reg3); /* Will print 67 */

    /* XOR - Exclusive OR ^*/
    reg3 = reg1 ^ reg2;

    /* XOR Operation: 27 = 0010 0111
                      64 = 0110 0100
                 27 | 24 = 0100 0011  = 43hex */
    printf("Reg1 ^ Reg2: %.2X\n", reg3);

    return 0;
} 
