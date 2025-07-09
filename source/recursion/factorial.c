/* A program that receives a integer and returns it's factorial in the form of !n */
#include <stdio.h>

/* Function prototype */
int factorial(int number);

int main(void){
    int number;

    printf("Enter an integer number: ");
    scanf("%d",&number);
    printf("The factorial of %d is %d\n", number, factorial(number));

    return 0;
} /* End main */

int factorial(int number){
    if (number == 0){ /*Base case - We know that !0 = 1 */
        return 1;
    }
    else {       /* General case - When n != 0*/
        return number * factorial(number - 1); /* Returns the factorial of a number */
    } /* End if-else */

} /* End factorial () */

/* Bug # 1 - When dealing with negatives numbers, we get a segmentation fault issue. I suspect it's
 because we are using int and not float, but:

- Int can be values from -32768 to 32767 or between 0 and 65535 when unsigned
- Segmentation fault 6190 indicates the process attempts to access a memory segment that it's not 
allowed to.
- If we use unsigned integers, this issue won't happen because

- unsigned int don't have a + or - sign associated with them

My suspicion is that when using a negative number at number * factorial(number - 1) it will try to
sum both negative numbers as (-n) - 1 = -(n + 1)

*/ 


