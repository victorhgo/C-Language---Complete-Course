#include <stdio.h>
#include <stdlib.h>

/* We declare a structure clock referred by the variable watch */
struct clock{
    int hours;
    int minutes;
} watch;

/* We pass the structure clock to the function prototype and var will be the referral during the function development */
void function1(struct clock var);

int main(){
    watch.hours = 22;
    watch.minutes = 11;

    /* We call the function passing the referral name only */
    function1(watch);

    return 0;
}

void function1(struct clock var){

    /* We use the var. to point the structure's variable */
    printf("Hours: %d\n", var.hours);
    printf("Minutes: %d\n", var.minutes);

}