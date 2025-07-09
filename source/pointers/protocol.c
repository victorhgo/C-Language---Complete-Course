/* Exercise: A function protocol() verifies two operands, if the first is greater, 
the function returns a 'H' for High, otherwise it will return 'L' fow Low:
Now implements a function that will receive two integer operands and the protocol() 
function as a parm, interpreting the protocol correctly and returns: */

#include<stdio.h>

/* Function prototypes */
char protocol(int operand1, int operand2);
void verifyProtocol(int operand1, int operand2, char (*function) (int, int));

int main(){

    /* Test only - Signals are read in HEX but program interprets them as int */
    unsigned int oper1 = 0x7C,
                 oper2 = 0x80;

    verifyProtocol(oper1, oper2, protocol);

} /* End Main */

/* Function that tests the protocols */
char protocol(int operand1, int operand2){
    /* Ternary operator - which operand is higher */
    const char response = operand1 > operand2 ? 'H' : 'L';

    return response;
} /* End protocol */

/* Function that will verify the protocol */
void verifyProtocol(int operand1, int operand2, char (*function) (int, int)){
    if(function(operand1, operand2) == 'H')
        printf("Signal 1 is higher\n");
    else
        printf("Signal 2 is higher\n");
} /* End Verify Protocol */