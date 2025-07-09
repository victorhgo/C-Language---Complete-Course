#include <stdio.h>
#include <stdlib.h>

enum level{
    low,
    medium,
    high,
    /* 20 to extremeHigh, next one will be 21...*/
    extremeHigh = 20,
    supremeHigh
} element;

int main(){
    printf("Low: %d\n", low);
    printf("High: %d\n", high);

    printf("Extreme high: %d\n", extremeHigh);
    printf("Supreme: %d\n", supremeHigh);

    return 0;
}