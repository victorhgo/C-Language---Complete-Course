#include<stdio.h>

void upton(int n);

int main(){
    upton(5);
}

void upton(int n){
    if (n == 1) return; /* Base case */

    /* General case */
    printf("%d\n", n);
    upton(n - 1);
} /* End function */