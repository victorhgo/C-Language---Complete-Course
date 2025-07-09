/* 4.2.9 - Cadastre em um vetor, 50 números de cheques que foram
recebidos por uma loja em um dia de trabalho. Permita que o
usuário faça uma busca neste vetor, afim de verificar se um
determinado número de cheque foi ou não cadastrado. Dê
mensagem ao usuário mostrando se o número consta ou não no
cadastro de cheques. */

#include <stdio.h>
#include <stdlib.h>
/* To use boolean */
#include <stdbool.h>

int receiveChecks(int checkNumber[]);

void printVector(int checkNumber[]);
bool lookCheck(int checkNumber[]);

int main(){
    int check[10] = {};
        /*checkId = 0; */

    receiveChecks(check);
    printVector(check);
    /* Now it's time to search it: */

    if(lookCheck(check)){
        printf("This check was found!\n");
    } else {
        printf("This check was not found! Please verify!\n");
    }
    return 0;
}

int receiveChecks(int checkNumber[]){
        /* Receive the check numbers */
    for (int i = 0; i < 10; i++) {
        printf("Enter the received check's number digits: ");
        scanf("%i", &checkNumber[i]);
    }
    return checkNumber[10];
}

void printVector(int checkNumber[]){
    for(int i = 0; i < 10; i++){
        printf("checks[%d] = %d\n", i, checkNumber[i]);
    }
}

bool lookCheck(int checkNumber[]){
    int checkId = 0;

    printf("What check number would you like to confirm if it was entered?\n");
    scanf("%d", &checkId);

    /* Check if the check number was entered. */
    for (int i = 0; i < 10; i++) {
        if (checkNumber[i] == checkId) {
            return true;
        }
    }
    return false;
}
