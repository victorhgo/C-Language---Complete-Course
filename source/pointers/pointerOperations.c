#include<stdio.h>

int main(){
    short variable = 10;
    short *pointer;

    pointer = &variable;

    printf("&variable: %X\n", &variable);
    printf("pointer: %X\n", pointer);
/* output: 
&Variable: 6D002F7E
pointer: 6D002F7E

Which means:

&variable will print the memory address
pointer also receive variable memory address

But, what if we increment the pointer?
*/
    pointer++;
    printf("pointer++: %X\n", pointer);
/* 

&variable: 6EEB6F7E
pointer: 6EEB6F7E

pointer++: 6EEB6F80
- 7E + 02 = 80 (HEX addition) because short is 2 bytes long
*/

/* What if we print the content of pointer now? */
    printf("*pointer = %d\n", *pointer); /* *pointer = %X = FFFFB5D0 (%d - -18992) - 
    it now points to a different address */

/* We can decrement the pointer and it will point to variable address
again and print the original value: */
    pointer--;
    printf("*pointer: %d\n", *pointer); /* *pointer: 10 */
    printf("*pointer: %X\n", pointer); /* Same value as variable */

}