/* A processor must receive bytes and cryptograph it following the rule :

- It should sum 5 to the even vector's elements and subtract 3 from the odds.

Example: date{0xA0,0x73,0x25,0xD3,0xCA,0xFE} should convert it to:
cryptograph{0xA5,0x70,0x2A,0xD0,0xCF,0xFB}

Now write a function to decrypt it
*/
#include <stdio.h>

/* Function prototypes */
char encrypt(char list[]);
void decrypt(char list[]);

int main(){
    char crypt[5] = {0xA0, 0x73, 0x25, 0xD3, 0xCA};

    decrypt(crypt);

    encrypt(crypt);

    for(int i = 0; i < 5; i++){

/* %hhX - makes the display on upper case and & 0xff get rids of 
000000/ffffff on the code, because it will mask out the upper bits 
and keep only the upper 8 bits that we want. (%hhx for lower case)

Explanation: 

- You are seeing the ffffff because char is signed on your system. 
In C, vararg functions such as printf will promote all integers smaller 
than int to int. Since char is an integer (8-bit signed integer in your case), 
your chars are being promoted to int via sign-extension. (from Stack)

- There is type conversion to int. Also you can force type to char by 
using %hhx specifier: printf("%hhX", a) (ISO/IEC 9899:201x) */
        //printf("Crypt =  %hhX\n", crypt[i] & 0xff);
/* We could also cast it using: */
        printf("Crypt = %X\n", ((unsigned char)crypt[i]));
    }
    decrypt(crypt);
}

char encrypt(char list[]){

    for(int i = 0; i < 5; i++){
        if(i % 2 == 0){
            list[i] += 5;
        } else {
            list[i] -= 3;
        }
    }
    return list[5];
}

void verifyParity(unsigned int number){
    if (number % 2 == 0){
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
}

void decrypt(char list[]){
    for(int i = 0; i < 5; i++){
        printf("Char - %c \n", list[i]);
    }
}

