#include <stdio.h>

int main(){

    struct customer{
        char name[20];
        char address[20];
        char city[15];
        char phone[10];
        int postal;
    }infos ; /* Structure's variable - Referral */

    /* We can also function gets() to store value inside a variable like */
    printf("Enter customer's name >>> ");
    gets(infos.name);
    printf("Enter customer's address >>> ");
    gets(infos.address);
    printf("Enter customer's city >>> ");
    gets(infos.city);
    printf("Enter customer's phone >>> ");
    gets(infos.phone);
    printf("Enter customer's postal code >>> ");
    scanf("%d", &infos.postal); /* For int */

    printf("- Customer's data -\n");
    printf("Name: %s\n", infos.name);
    printf("Address: %s\n", infos.address);
    printf("City: %s\n", infos.city);
    printf("Phone: %s\n", infos.phone);
    printf("Postal code: %d\n", infos.postal);

    return 0;
}