#include <stdio.h>
#include <stdlib.h>

struct drinks{
    int negroni,
        martini,
        margarita;
} openBar;

struct drinks *cheers;

void barman(struct drinks *pointer);


int main(){
    cheers = &openBar;

    cheers->negroni = 7;             /* Will manipulate the value in negroni thru the pointer */
    (*cheers).martini = 11;            /* Will manipulate the value in martini thru the pointer */
    cheers->margarita = 13;          /* Will manipulate the value in margarita thru the pointer */

    printf("%d\n", cheers->negroni);    /* Will print the value stored in negroni */
    printf("%d\n", (*cheers).margarita);  /* Will print the value stored in margarita using the other way */

    barman(&openBar);                   /* Instead of using the cheers pointer, pass the address */
    printf("%d\n", openBar.negroni);    /* Will print the value stored in negroni */
    printf("%d\n", openBar.margarita);  /* Will print the value stored in margarita using the other way */

}

/* barman will manipulate the structure's variable thru the pointer */
void barman(struct drinks *pointer){
    pointer->negroni = 19;
    pointer->margarita = 3;

}