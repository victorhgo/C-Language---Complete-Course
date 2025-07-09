#include<stdio.h>

int main(){

    int variable1,
        *pointer1,
        variable2,
        *pointer2;

    pointer1 = &variable1;
    pointer2 = &variable2;

    printf("Var1 address: %p\n", pointer1);
    printf("Var2 address: %p\n", pointer2);

    /* Compare which is bigger */
    if (pointer1 > pointer2) printf("Var1 address is bigger than Var2\n");
    else printf("Var2 address is bigger than Var1\n");

    return 0;
}