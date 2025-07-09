#include <stdio.h>

int main(){
    float number1, number2;

    printf("Enter the first number: ");
    scanf("%f", &number1);
    printf("Enter the the second number: ");
    scanf("%f", &number2);

    printf("%.2f * %.2f is %.2f\n", number1, number2, number1 * number2);
}