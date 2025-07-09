#include<stdio.h>
#include<stdlib.h>

/* To use isalpha() function */
#include<ctype.h>

/* isalpha() - a good C function to return letters (will ignore everything else) */

int stringSize(const char *string);
int letters(const char *string);

/* The function that receives letter() will print how much letters function has*/
void printAmount(const char *string, int (*function) (const char *));

/* If the function received two strings:

void printAmount(const char *string, int (*function) (const char *, const char *));

two ints:

void printAmount(const char *string, int (*function) (int, int));

And goes on and on...

*/

int main(){
    char name[] = "Victor Correa";


    printAmount(name, letters);

    /* Because stringSize() has the same prototype, this would also work */
    printAmount(name, stringSize);

}

int stringSize(const char *string){
    register int i = 0;

    while(string[i] != '\0')
        i++;

    return i;
}

int letters(const char *string){
    register int i = 0,
             letters = 0;

    while(string[i] != '\0'){
        if(isalpha(string[i])) letters++;
        i++;
    }

    return letters;
}

void printAmount(const char *string, int (*function) (const char *)){

    printf("The amount of letters in this string is: ");
    printf("%d\n", (*function) (string));

}


