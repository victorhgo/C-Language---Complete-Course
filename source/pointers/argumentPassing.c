#include<stdio.h>

int multDouble(int a, int b);
void quadCube(int *a, int *b);

int main(){
    int x = 5, y = 6;

    printf("(2 * %d) * (2 * %d) = %d\n", x, y, multDouble(x,y));
    quadCube(&x, &y);

    printf("After quadCube: x(%d) and y(%d)\n", x, y);

}

int multDouble(int a, int b){
    a *= 2;
    b *= 2;

    return a * b;
} /* End multDouble */

void quadCube(int *a, int *b){
    int temporaryA = *a,
        temporaryB = *b;

    *a = temporaryA * temporaryA;
    *b = temporaryB * temporaryB * temporaryB;
}