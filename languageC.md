<a name="pages"></a>
# C Language
###### Index

- [Structure of language C](#page1)
- [Functions](##page2)
- [Vectors and Matrices](#page3)
- [Pointers](#page4)
- [Argument passing in C and Recursion](#page5)
- [Files in C](#page6)
- [Structures in C](#page7)
- [Bit to bit operations and bit fields](#page8)
- [Dynamic Memory Allocation](#page9)

---
##### by Victor Correa
---

<a id="page1"></a>

## Structure of Language C

```C
#include <stdio.h>

/* Main function */
int main(){

    printf("Hello, World!\n");

    return 0; /* Since the main() function is an int it has to return something */

} /* End main function */
```

To compile it:

```sh
$ gcc -ansi -Wall -pedantic-errors -Werror -g -lm **program.c** -o **executable**
```

What are those flags?

- ***-ansi***: To use the standard C89 (most portable C language version)

- ***-Wall***: to return more compilation *warnings* like a variable not being used, if the ";" is missing on any line.

- ***-pendantic-errors***: force to follow the **ANSI** standard

- ***-Werror***: *warnings* will become compilation errors and the program will not be compiled

- ***-g***: allow to use the **gdb** (*Gnu debugger*) tools and **valgring** (it will help to find some issues and look into certain memory sessions).

- ***-lm***: allows to use mathematical functions imported from math library *math.h*.

- ***-o***: it will be the executable file.

What does a C program looks like?

```C
// A simple program to write a name using the scanf() function, store into the char variable name and print it on the screen using the printf() function:
#include <stdio.h>

int main() {
    char name[30];
    printf("What is your name?\n");
// When using the scanf to enter a string, don't use the & to store the data into a variable.    
    scanf("%s",name);
    printf("Hello %s, how are you?\n", name);

    return 0;
}
```

A program that squares a number using the pow() function from math.h library:

```C
#include <stdio.h>
#include <math.h>

int main() {
    /* float type */
    float square;

    printf("Enter a number: ");
    scanf("%f", &square);
    
    // to use the function pow(power of) = pow(base, exponent)
    printf("The square of %.2f is %.2lf\n", square, pow(square, 2.0)); 

    return 0;

}
```

To compile the above example, don't forget to use the -lm flag on the gcc command.

A not good way to do multiplication (or any other mathematical operation):

```C
#include <stdio.h>
#define multiplication number1 * number2

int main(){
    float number1, number2, result;

    printf("Enter the first number: ");
    scanf("%f", &number1);
    printf("Enter the the second number: ");
    scanf("%f", &number2);

    result = multiplication;

    printf("%.2f * %.2f is %.2f\n", number1, number2, result);

    return 0;
}
```

A better way to do it:

```C
#include <stdio.h>

int main(){
    float number1, number2:

    printf("Enter the first number: ");
    scanf("%f", &number1);
    printf("Enter the the second number: ");
    scanf("%f", &number2);

    printf("%f X %f is %f\n", number1, number2, (number1*number2));
}
```

### Using while loop

Using while loop to print the 10 first integers:

```C

#include <stdio.h>

int main(){
    
    int num = 0;
    while (num <= 10) {
        printf("%d\n", num);
        num = num + 1;
    }
    return 0;
}
```

### Using for loop

Using for loop to enter 5 numbers and show them reversed:

```C
#include <stdio.h>

int main(){
    int i, vector[5];

    for(i = 0; i < 5; i++){
        printf("Enter a number to store in the vector variable\n");
        scanf("%d", &vector[i]);
    }
    for(i = (i-1); i >= 0; i--){
    printf("The entered numbers are %d \n", vector[i]);
    }
}
```

<a id="page2"></a>
## Functions in C

It's always a good practice to implement functions to avoid code repetition for instance, because if you want to change the code you only need to change it once. Another good practice is to always use function prototype. A good example for that is an algorithm that returns the factorial of a number. 

The factorial of a number $!n$ is defined by:

$$n! = n \cdot (n - 1) \cdot (n - 2) \cdot ...$$

A C code to factorize a number can be written as:

```C
int main(){

    int count = 1, factorial = 1, number;
    printf("What number would you like to factorize? ");
    scanf("%d", &number);
//    1 * 2 * 3 * ... * n
    while(count <= number){
        factorial = count * factorial;
        count++;
    }
    printf("The factorial of %d is %d", number, factorial);
}

```

But a good practice would be writing a function that returns the factorial of a number, like this one:

```C
int fat(int n){
    if (n == 0){ /* Base case */
        return 1;
    }    
    else {       /* General case */
        return n * fat(n - 1); /* Returns the factorial of a number (non-void function)*/
    }    
}
```

To call the factorial function _fat()_ during the program's execution:

```C
fat(int n);
```

So in the first example, instead of writing all the code block whenever we need the factorial of a number, we could simply use the fat() function to do it. *The function prototype must be always declared before the main() function*

The syntax for the prototype is:

```C
datatype functionName(parameters);

// Except for the void function, like:

void menuDraw();
```

To call the function during the code execution:

```C
int main(){

    int count = 1, factorial = 1, number;
    printf("What number would you like to factorise? ");
    scanf("%d", &number);
//    1 * 2 * 3 * ... * n
    // This is the function call:
    //fat(number); << 
    while(count <= number){
        factorial = count * factorial;
        count++;
    }
    printf("The factorial of %d is %d", number, factorial);
}
```

### Void Functions - Functions that returns no value

One example, a function to draw a menu, which we will call menuDraw:

```C
void menuDraw(){
    printf("---- Main menu----\n");
    printf("1 - Option 1\n");
    printf("2 - Option 2\n");
    ...
    printf("n - Option n\n");
}

// Whenever we want to call this function on the program, we use the function call
menuDraw();
```

### Functions that returns no value but accept parameter

We can have a void function that accepts parameter, this can be useful to perform specific tasks that requires an external value. For instance, we can have a function that tells if an input number is even or odd:

A number $n$ is even if the remainder of the division by two is equal zero, so:

```C
void verifyParity(unsigned int number){
    if (number % 2 == 0){
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
}
```

We could call this function above and as a parm, input the desired number to check. Is 5 and odd or even?

```C
verifyParity(5);
```
```sh
$ 5 is odd
```

We can have void functions that performs mathematical calculations for instance.

A function to calculate and oscillator's frequency with 555 integrated circuit. The function will receive $Ra$, $Rb$ and $C$ and print the value on the screen.

$$ f = \frac{1.44}{(Ra + 2Rb) * C} $$

```c
void oscillatorFrequency(float ra, float rb, float c){
    float frequency = 0;

    frequency = 1.44/((ra + 2*rb)*c);

    printf("Frequency = %.2fHz\n", frequency);

    //printf("Frequency = %.2fHz\n", (1.44/((ra + 2*rb)*c)));

}
```

Since this function does not return any value, we could get rid of variable _frequency_ and perform the calculations during the print process like:

```C
    printf("Frequency = %.2fHz\n", (1.44/((ra + 2*rb)*c)));
```

### Functions that returns something (non void)

We could rewrite the above function to verify the parity of numbers that returns a boolean value based whether the number is odd or even.

```C
/* Returns True (1) if number has odd parity, or False (0) if number has even parity */
bool verifyParity(unsigned int number){
    bool parity = 0;

    while(number){
        parity = !parity;
        number = number & (number - 1);
    }
    return parity;
}
```
Pseudocode for the above program (from https://www.geeksforgeeks.org/dsa/program-to-find-parity/)
```
Algorithm: verifyParity(n)
1. Initialize parity = 0
2. Loop while n != 0      
      a. Invert parity 
             parity = !parity
      b. Unset rightmost set bit
             n = n & (n-1)
3. return parity

Example: Initialize: n = 13 (1101)   parity = 0

n = 13 & 12  = 12 (1100)   parity = 1
n = 12 & 11 = 8   (1000)   parity = 0
n = 8 & 7 = 0     (0000)   parity = 1
```

We can return any kind of data: _int_, _float_, _char_, _bool_... 

### Local and Global variables

The main difference between global and local variables is that global variables can be accessed globally in the entire program, whereas local variables can be accessed only in the block or function they are declared.

```C
/* Libraries */

/* Function prototypes */
void function1()

/* Global variables - Can be accessed everywhere in the code */
int global = 3;

/* Main function */
main(){
    /* In this example, this is a local variable that only exists in the context of the main function*/
    int localvar1 = 1;
    printf("%d", localvar1); // It will print 1
    printf("%d", global); // It will print 3
}

/* If we try to access the localvar1 on the function1, it won't work because it was declared locally only in the main function*/
void function1(){
    int localvar1 = 2;
    printf("%d", localvar1); // It will print 2
    printf("%d", global); // It will print 3
}
```

- _static_ variables: To preserve the content of a variable between two functions call
- _volatile_ variables: To tell the compiler that the content of a variable can be modified implicitly
- _register_ : To assign a local variable to a CPU register instead of memory (can't use pointers for instance)
- _auto_ : For local variables, not really useful nowadays, ported from B language

#### External Variables

It's a good practice to keep all files separated to make it easier to read and maintain the source code. We can create a file to separate variables, functions and other contents, keeping the main.c (which contains the main function) clean and easy to keep. Within the same folder we created the main.c file, we can create a _functions.c_ that will look like:

```C
/* We will import the global variables from the main.c file using the extern parm */
extern int value,
           number,
           test;

void sum(){
    int sum;
    sum = value + number + test;

    printf("Sum = %d\n",sum);
}

```

Where the _main.c_ file would look like:

```C
/* Global Variables*/
int value = 1,
    number = 2,
    test = 3;

/* Function prototype - also use the extern to call it from a external file*/
extern void sum();

main(){
    sum();
}

```

#### Compiling a program with external files and using makefile

We can write the whole main() session of a program in a single file, and separate all the functions in another file or files, to keep it simple to maintain as the program might be getting bigger and complicated over time.

Let's take an example a program that executes a function _function()_ and returns 0. We can start by creating a file called _myprogram.c_ which will contain:

```C
#include"functions.h>

int main(){
    /* Call the functions that currently is in another file */
    function();

    return 0;
}
```

The _functions.h_ is a header file were we will declare only the function's prototypes for every new function we want to implement on our program:

```C
/* Function's prototypes: */

void function();
```

At last, we can write the functions.c where we will develop our functions to be called in the _main()_ function:

```C
/* functions.c - where we develop our functions */
void function(){
    printf("Hello, I'm a function that returns nothing!\n");

    return;
}
```

##### Compiling with GCC

We can compile the above code with _gcc_ as:

```sh
$ gcc -o myprogram myprogram.c functions.c -I.
```

This command will compile the two _.c_ files and create as executable, the _myprogram_ which we can run. 

Right now I won't enter in further details regarding the linker process. But pay attention to always include the flag _-I._ which will tell _gcc_ to look the current directory for the include file _functions.h_.

##### Using a make file to compile everything at once

We can use a _makefile_, execute the make command and compile everything at once as we wrote in the makefile. Taking the above example as above, we can write the _makefile_ as:

```sh
# This constant is to use gcc as the default compiler
CC=gcc

# including the -I. flag
CFLAGS=-I.

myprogram: myprogram.o functions.o
    $(CC) -o myprogram myprogram.o functions.o
```

Then we simply type _make_ in the command line and wait for the compiler to finish it's process.

> for further reference: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

And we can also utilize make's manual

```sh
$ man make
```

<a id="page3"></a>

## Vectors and Matrices

Vectors can be accessed using the index of data, for instance the vector with the 10 first integers from 0 to 9:

```C
int integers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```
Where

```C
integers[0] = 0;
integers[1] = 1;
integers[2] = 2;
...
integers[10] = 9;
```

We can play along with vectors, like the program below that receives 5 integers into a vector and then reverses it:

```C
#include <stdio.h>

int main(){
    int i, vector[5];

    for(i = 0; i < 5; i++){
        printf("Enter a number to store in the vector variable\n");
        scanf("%d", &vector[i]);
    }
    for(i = (i-1); i >= 0; i--){
    printf("The entered numbers are %d \n", vector[i]);
    }
}
```

#### Vectors as parameter to functions

We can work with vectors using functions, to do that there are three 3 different ways to do that. Pointers will be left for upcoming levels, but for now we will work with the vector itself specifying the vector's elements.

The other way of doing it without pointers is using the vector's self parameter.

An example below to print the vector's values:

```C
#include<stdio.h>

/* number will be the vector's index */
#define number 10

void function(int vector[], int number);

main(){
    int vec[number];

    function(vec, number);

    return 0;
}

void function(int vector[], int number){

    for(int i = 0; i < number; i++){
        printf("vector[%d] = %d\n", i, vector[i]);
    }
}
```

Example: working with True RMS formula where a function will receive the point's number of voltage in the discrete domain:

$$V_{RMS} =  \sqrt{\frac{1}{N}\sum_{i=0}^{n-1}v^2(i)}$$

where $N$ is the sample's amount on tension signal and $v$ equals the voltage in the point.

```C
float trueRMS(float volts[], int samples){
    float rms = 0.0;

    for (int i = 0; i < samples; i++){
        volts[i] *= volts[i];
    }
    for (int i = 0; i < samples; i++){
        rms += volts[i];
    }

    rms /= samples;

    return sqrt(rms);
}
```
### Matrices - m[][]

To work with matrices in functions, we can use like the following:

```C
void drawMatrix(int matrix[3][3]);

void drawMatrix(int matrix[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; i < 3; i++){
            printf("%3d ", matrix[i][j]);
        }
    }
}
```

### Strings

C can't deal with strings directly like other languages (Python for instance), but we can use vectors to store the characters and a delimiter character. 

```
"This is a string"
"This is also a string"
```

To tell the compiler the end of a string, we use the null character *\0*. For instance:

- Always remember the null character occupies one space of a vector

```C
char name[256] = "Victor Correa" /* String */
char name1[256] = {'V', 'i', ..., 'a'}; /* Vector of characters */

/* Data format: %s */
printf("My name is %s\n", name);
printf("The size of this string is %d bytes\n", sizeof(name));

/* We can also use the puts() function to print strings */
```
The execution would print:

```
$ My name is Victor Correa
  The size of this string is 14 bytes
```

We can write data inside a string using the _scanf()_ function:

- *Note*: When writing a string with scanf() if we put a space it will automatically save as *\0* char, ignoring every data written after the space/tab/etc...

```C
char name[];

scanf("%s", name);

/* Note that we don't use the & operand when working with scanf() with strings */
```

Therefore when working with strings it's a good practice to use the _gets()_ function, that allows us to work with complete sentences:

```C
char name[];

printf("Enter your name: "):
gets(name);
printf("Welcome, %s", name);
```

#### Functions to manipulate strings

To write functions that accepts a string as parameter, we can use the following scope:

```C
void function(char str[]);

main(){
    char string[];

    /* Calling the function */
    function(string);
}
```

But the best practice is to use pointers (*) when dealing with strings in C/C++. I will develop pointers in the further chapter but for now, let's just use strings as:

```C
/* Function prototype that receives a string with the operator * (pointer) */
void receiveString(char *string);

/* Function prototype that receives a string and also returns a string */
char *returnString(char *str);
```


#### The _string.h_ library and it's functions

C offers a library _string.h_ with a lot of useful functions to deal with strings such as:

- _strcat()_ - to concatenate two strings
- _strcmp()_ - to compare two strings
- _strcopy()_ - to copy the content of a string into another
- _strlen()_ - returns the length of a string (ignoring the \0 character)

*Exercise from 7.5 - Write a interpreter for some instructions*

<a id="page4"></a>

## Pointers

Pointers are fundamental variables in C for more efficient programs since they point to a variable's memory address,  allowing us to access the hardware memory address, dynamic memory allocation. By doing that we can manipulate data directly from the computer's memory.

```C
main(){
    int variable = 15;

/* Will print the memory address - where variable is stored in the physical memory (hardware) */ 
    printf("%X", &variable);

/* We can use %p to print the memory format from the current machine */
}
```

Pointers can be declaring the same way we declare other variables, but with an * (it's known as the indirection operand) before it's name, also don't forget to declare it's type, usually compatible with the variable it will point to:

```C
int *variable1; /* an integer pointer */

float *variable2; /* a float pointer */

char *variable2; /* a char pointer */

double *variable3; /* a double pointer */
```

One example to point to an integer:

```C
int main(){
    int *pointer, variable;

    variable = 10;

    /* pointing to variable's address */
    pointer = &variable;

    printf("&variable: %X\n", &variable);
    printf("pointer: %X\n", pointer);
    printf("variable: %X\n", variable); /* return hex */
    printf("&pointer: %X\n", &pointer); 
    /* To access the variable's content thru a pointer */
    printf("variable content thru pointer: %X\n", *pointer);

    /* we can also modify the content of variable thru the pointer */

    *pointer = 8;

    printf("changing variable content to: %X\n", variable);

    /* This functionality helps us to working directly on the hardware's memory */
}
```

Running the above code on my terminal, it returned:

```
$ ./pointers
&variable: 6D0B6F74
pointer: 6D0B6F74
variable: A
&pointer: 6D0B6F78
variable content thru pointer: A
changing variable content to: 8
```

It's always important to initialize pointers before using then, otherwise problems might occur during the execution. If a pointer points to nothing, it's a good practice to initialize it the _NULL_ const which means memory address $0$.

```C
int *pointer = NULL;
```

#### Pointers and Vectors

```C
int vector[10] = {1, 3, 5};

/* This will print the memory address where the vector is stored - for the first element of vector */
printf("%X\n", vector);
printf("%X\n"), &vector[0]); /* It will show the same address */

```

We can now conclude that when we call the vector in the first _printf()_ function it will print the address where this vector is stored, therefore _vector_ is a constant pointer:

> The vector's name is a pointer to the first vector's element.

We can declare a new pointer to manipulate this vector:

```C
int vector[10] = {1, 3, 5};
int *pointer;

// pointer = &vector[0];
/* Since the vector's name is a pointer to the first element, we can simply say: */

pointer = vector;

printf("vector = %X\n", vector);
printf("pointer = %X\n", pointer);

printf("*pointer = %d\n", *pointer); /* it will print the content of vector[0]; */
```

Executing the program above:

```sh
$ ./pointers
vector = 6D27AF50
pointer = 6D27AF50
*pointer = 1
```

This way we can modify the vector's data using the pointer by using the * operator:

For instance, taking the above code and applying this modification:

```C
int vector[10] = {1, 3, 5};
int *pointer;

// pointer = &vector[0];
/* Since the vector's name is a pointer to the first element, we can simply say: */

pointer = vector;

printf("vector = %X\n", vector);
printf("pointer = %X\n", pointer);

printf("*pointer = %d\n", *pointer); /* This will print the content of vector[0] using *pointer */
printf("vector[0] = %d\n", vector[0]); /* This will print the content of vector[0] */

/* We can also manipulate data inside a vector using pointers */
*pointer = 15; /* It will change vector[0] from 1 to 15 */

printf("vector[0] = %d\n", vector[0]); /* it will print 15 now instead of 1 */
printf("*pointer = %d\n", *pointer);
```

Running the above program:

```sh
$ ./pointers
vector = 6DA7AF50
pointer = 6DA7AF50
*pointer = 1
vector[0] = 1
vector[0] = 15
*pointer = 15
```

We can also modify the _vector[1]_ index using the same pointer like:

```C
int vector[10] = {1, 3, 5};
int *pointer;

// pointer = &vector[0];
/* Since the vector's name is a pointer to the first element, we can simply say: */

pointer = vector;

printf("vector = %X\n", vector);
printf("pointer = %X\n", pointer);

printf("*pointer = %d\n", *pointer); /* This will print the content of vector[0] using *pointer */
printf("vector[1] = %d\n", vector[1]); /* This will print the content of vector[0] */

/* We can also manipulate data inside a vector using pointers */
*(pointer+1) = 15; /* It will change vector[0 + 1] from 3 to 15 */

printf("vector[1] = %d\n", vector[1]); /* it will print 15 now instead of 1 */
printf("*(pointer+1) = %d\n", *(pointer+1));
```

The output of the above program is:
```sh
$ ./pointers
vector = 6B5B2F50
pointer = 6B5B2F50
*pointer = 1
vector[0] = 1
vector[0] = 15
*pointer = 15
vector[1] = 3
vector[1] = 17
*(pointer+1) = 17
```

We can use this technique to manipulate data from any vector's index by pointing the correct index number with the pointer. This technique can be used for any kind of vector's data including char, which will be useful when dealing with strings.

#### Using pointers to deal with strings

When dealing with strings is a good practice to use vectors as auxiliaries when manipulating data from a string directly.

```C
char name[] = "Victor Correa";
char *pointer;

/* It will point the first string's element */
pointer = name; 

/* Let's change the name on the string */
for (int i = 0; i < 15; i++){
    *(pointer + i) = 0x30 + i /* 0x30 is 1 on ASCII */
}

printf("%s\n", name);
```

#### Pointer's Arithmetics

We can perform some arithmetic operations (adding and subtracting) and comparison (equal, >, <) that will help us to manipulate data structures using pointers as auxiliaries, keeping in mind that when dealing with pointers increment/decrement we cannot look them as regular variables.

Increment/decrement pointers is actually applying to _sizeof(datatype)_ (in hexadecimals):

- _char_ : 1 byte
- _short_ : 2 bytes each increment/decrement
- _long_ : 4 bytes each increment/decrement
- _double_ : 8 bytes each increment/decrement

##### Manipulating vectors with pointers

> note: Codes are developed under _source/pointers_ to better understand this topic

Also the implementation of a memory stack using vectors.

> Implement a stack with 16 levels where each level will store 1 byte. To display the stack, data and address should be shown in hexadecimal

#### Pointers and Functions (and function as parameter)

!!! S Important topic!

Using pointers as function's parameters:

```C
void function(int vector[], int size);

int main(){
    int vector1[10] = {7, 11, 19, 23, 29};

    function(vector1,10);


}

void function(int vector[], int size){
    for(int i = 0; i < size; i++){
        printf("Vector[%d] = %d\n", i, vector[i]);
    }

} /* End function */
```

When we call the function _function(vector1,10)_ we are actually putting the vector's first element's address to this function, not the entire vector. Because the _vector1_ is an abstraction of its first element, like _function(&vector1[0],10)_

So we could use a pointer as a parameter, in the following way:

```C
void function(int *vector, int size);

int main(){
    int vector1[10] = {7, 11, 19, 23, 29};

    function(vector1,10);


}

void function(int *vector, int size){
    for(int i = 0; i < size; i++){
        printf("Vector[%d] = %d\n", i, vector[i]);
    }

} /* End function */
```

But we can also use a function as a parm to another function!!!

A function has a address associated with it's input, so when we define a new _function()_ it exists on a memory's region, so we can use pointers with functions and use them as parameters to another functions. Let's take a look on a function that returns the size of a string:

```C
int stringSize(char *string);

int main(){

}

int stringSize(char *string){
    register int i = 0;

    while(string[i] != '\0')
        i++;

    return i;
}
```

To use a function as a parm to another function, we need a pointer for functions, this function's prototype needs to have a declared parm compatible with the function's prototype that we will pass to it. For the program bellow, we want to implement a new function that receives the letters() function as a parm and print on the screen the amount of letters on the string.

```C
/* To use isalpha() function */
#include<ctype.h>

/* isalpha() - a good C function to return letters (will ignore everything else) */

int stringSize(const char *string);
int letters(const char *string);

int main(){
    char name[] = "Victor Correa";

    printf("Size of String: %d\n", stringSize(name));
    printf("Letter's Amount: %d\n",letters(name));

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
```

To do that, we can declare the new function as the bellow:

```C
/* it will receive our string and the function as: type (*function) - to
declare the function's vector. Then we put the types of parameters this function
will receive as (char *) - char of type pointer * */
void printAmount(char *string, int (*function) (const char *));

int main(){

    /* To call the function in the program */
    printAmount(string, function);

    /* We can also call using a string directly */
    printAmount("Hello world", function); 

}

void printAmount(char *string, int (*function) (const char *)){

    printf("The amount of letters in this string is: ");
    printf("%d\n", (*function) (string));

}
```

Exercise: The function _protocol()_ below verifies two operands, if the first is greater, the function returns a 'H' for High, otherwise it will return 'L' fow Low:

```C
char protocol(int operand1, int operand2){
    char response;

    response = op1 > op2 ? 'H' : 'L';

    return response;
} /* End protocol */
```

Now implements a function that will receive two integer operands and the _protocol()_ function as a parm, interpreting the protocol correctly and returns:

"Protocol Result: H" or "Protocol Result: L"

Implementation:

```C
/* Function that will verify the protocol */
void verifyProtocol(int operand1, int operand2, char (*function) (int, int)){
    if(function(operand1, operand2) == 'H')
        printf("Signal 1 is higher\n");
    else
        printf("Signal 2 is higher\n");
} /* End Verify Protocol */
```

Where we call both functions in the main function as:

```C
verifyProtocol(oper1, oper2, protocol);
```

> About _op1 > op2 ? 'H' : 'L';_

`The conditional operator in C, also known as the ternary operator, is a good and elegant way to perform conditional evaluations. It is the only operator in C that takes three operands and follows the syntax: condition ? expression1 : expression2;.`

`If the condition evaluates to true, expression1 is executed; otherwise, expression2 is executed. This operator provides a shorthand for simple if-else statements, making the code more readable and efficient.`

#### Pointers of Pointers

_Multiple indirection_, or pointer that points to another pointer's address. Although this technique exists, it's rare the situations where we will use multiple indirection in our codes, but can be useful for some tasks. In C++ for instance it's not used anymore. 

But to implement it:

```C
int variable = 13,
    **pointer1 = NULL, /* Using 2 indirection operator */
    *pointer2 = NULL;

    pointer2 = &variable /* pointer2 receives variable address */
    pointer1 = &pointer2 /* pointer1 receives pointer2 address */

    printf("variable: %d\n", variable);
    printf("*pointer2: %d\n", *pointer2);
    printf("**pointer1: %d\n", **pointer1);

    /* will print:
    variable: 13
    *pointer2: 13
    **pointer1: 13
    - But if we modify **pointer1: */

    **pointer1 = 19;

    printf("variable: %d\n", variable);
    printf("*pointer2: %d\n", *pointer2);
    printf("**pointer1: %d\n", **pointer1);

    /* Now will print it as:
    variable: 19
    *pointer2: 19
    **pointer1: 19
    - but if we modify *pointer2? */

    *pointer2 = 23;

    /* Now will print it as:
    variable: 23
    *pointer2: 23
    **pointer1: 23 */

```

There's no limit for multiple indirection, so you can declare a pointer for a pointer for a pointer ...

<a id="page5"></a>
## Argument passing in C and Recursion

We can use argument passing in C for functions, how can we modify a variable's value and how to use argument passing thru the command line where we can pass the arguments to the main function and recursion, where a function calls itself helping to execute successive calculations without the need for iterations.

## Argument passing to a function by value

When we pass an argument by value, we are sending a variable's value copy for the function, for instance:

```C
/* This function will receive two variables a and b, double them and return the multiplication */
int multDouble(int a, int b);

main(){
    int x, y;
    printf("%d", multDouble(x,y));
}

int multDouble(int a, int b){
    a *= 2;
    b *= 2;

    return a * b;
} /* End multDouble */
```

In the above code, the values of $x$ and $y$ won't be modified during the function's execution because when we pass the arguments _int a, int b_, we are actually passing a copy of the content in variables $x$ and $y$, so $a$ and $b$ will be immediately wiped out when _multDouble()_ returns $a * b$.

But to modify the content of both $x$ and $y$, we would need to pass their addresses (pointers). The function bellow will receive two numbers and print their squares and cubes:

```C

void quadCube(int *a, int *b);

int main(){
    int x = 5, y = 6;

    /* We are passing their addresses now */
    quadCube(&x, &y);

}

void quadCube(int *a, int *b){

    /* These two temporary variables will receive the value of each variable
    and will indirectly refresh their values */
    int temporaryA = *a,
        temporaryB = *b;

    *a = temporaryA * temporaryA;
    *b = temporaryB * temporaryB * temporaryB;
}
```

In this example we are modifying the variables themselves using their addresses implicitly. So after executing it, $x$ and $x$ values will be permanently changed to their squares and cubes respectively.

### Argument passing thru the command line

To pass and argument thru the Operating System's command line, the command line send to program's execution should be recognised when the execution starts. Therefore the _main()_ function should receive this arguments:

```C
main(int argc, char *argv[]);
```
The first int _argc_ indicates how many arguments will be passed thru the command line. The second one char _*argv[]_ will store the strings for the passed arguments. The function below will return the square of each entered number:

```C
main(int argc, char *argv[]){
    int number, square;

    printf("number | square\n");

    for(int i = 0; i < argc; i++){
        number = atoi(argv[i]); /* atoi will convert a string to int - stdlib.h*/
        square = number * number;

        printf("%2d %3d\n", number, square);
    } /* end for */
} /* end main */
```

After compiling it and calling the executable as _squares_ for instance, we can call the program with the arguments and it will return the squares:

```sh
$ ./squares 1 2 3 4 5
number | square
 0   0
 1   1
 2   4
 3   9
 4  16
 5  25

# If executed empty:

$ ./squares
number | square
 0   0
```

> Exercise: type ohm on the command line followed by voltage and current values and calculate the resistance value, following the Ohm's law:

$$ R = \frac{V}{I} $$

Use the function _atof()_ that converts a string to double (float).

Demonstration:
```sh
$ ./ohms 5.3 0.82 15 2 12 1
Resistance: 6.46 | 7.5 | 12 | ohms
```

Implementation:

```C
/* values will count how many arguments were passed and readings will store all arguments */
int main(int values, char *readings[]){

    printf("Resistance: ");

    /* Starting at 1 and increment 2 to get voltage and current's pair respectively */
    for(register int i = 1; i < values; i += 2){

        /* Return the current following Ohm's law R = V / I */
        printf("%.2f | ", (atof(readings[i]) / atof(readings[i + 1])));

    } /* End for*/

    printf("ohms\n");
    
    return 0;
} /* End main */
```

### Recursion

Recursion is a resource where a function calls itself. We have two types of recursion:

- _Direct Recursion_ - A function calls itself
- _Indirect Recursion_ - A functionA calls functionB which calls back functionA

We have worked with the _factorial()_ function in the recursive form, where it calls itself to return the factorial of a number. Another example is a function that will print numbers from $n$ to 0;

```C
void downto0(int n){
    if (n < 0) return; /* Base case */

    /* General case */
    printf("%d\n", n);
    downto0(n - 1);
} /* End function */
```

Recursion although really powerful and beauty, is not recommended for systems where memory resources are limited due to it's high demand of memory utilization.

Suppose we call the function as _downto0(5)_, then $n = 5$, so the function will print each $n$ and call itself again for $n - 1$.

The function that returns the size of a string can also be recursive:

```C
int stringSize(const char *string){
    if(*string == '\0') /* Looking for the \0 character (end of string) */
        return 0;
    else
        return 1 + stringSize(string + 1);
} /* End function */
```

- Note - We can print a string only by pointing it to the printf as printf(string);

> Exercise: Write a recursive function that will print numbers from 1 to $n$ where $n$ is the given number.

<a id="page6"></a>

## Files in C

One of the most important topics since C offers a lot of resources and functions to manipulate files, where we can store and access data for our programs, also access other Operating System's files to develop better applications and softwares.

For C, files are just a sequential collection of bytes (also know as _stream_) where even a line is a character.

To work with files in C, we need to open the file and store it in a variable. After working with this file we have to close it again.

To open a file we can use a pointer to files, with the _FILE_ type (defined in the standard _stdio.h_ library). We can declare a pointer to file following this syntax:

```C
FILE *fileName;
```

The function _fopen()_ will be used when opening a file, its prototype is known as:

```C
FILE *fopen(const char *fileName, const char *mode);
```

Where:

- _fileName_ is the file's name with it's extension (ex: readme.txt)
- _mode_ is the string that contains how we will open the file (read, write)

Some opening modes are:

| **Mode** |                **Description**               |
|:--------:|:--------------------------------------------:|
|     r    |         Open a text file as read mode        |
|     w    |       Creates a text file as write mode      |
|     a    |          Append data to a text file          |
|    rb    |          Open a binary file as read          |
|    wb    |          Open a binary file as write         |
|    ab    |         Append data to a binary file         |
|    r+    |        Open a text file as read/write        |
|    w+    |      Creates a text file for read/write      |
|    a+    | Append or creates a text file for read/write |
|    r+b   |       Open a binary file for read/write      |
|    w+b   |     Creates a binary file for read/write     |
|    a+b   |    Append to a binary file for read/write    |

If the file already exists and you open as write for instance, it will open the existing file in write mode.

After manipulating all desired data inside a file, we need to free the allocated memory by function _fopen()_. To do that, we use the function _fclose()_ that has the following prototype:

```C
int fclose(FILE *filename);
```

This function returns 0 if successful or _EOF_ (end of file)

When opening a file it's a good idea to test if the file was successfully opened by the program. To verify that we can check if the pointer is pointing to NULL. If it's true that's because the file was not successfully opened. Possible issues that might happen are: the file does not exist, the file is corrupted, the provided name is wrong.

```C
FILE *filename;

filename = fopen("test.txt", "w");

/* Test if the file was successfully opened */
if(filename == NULL) {
    printf("Error\n");
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    exit(1);
} /* End if */
```

To open a file as read we could open the same way as above but changing it to _"r"_ mode instead of _"w"_:

```C
filename = fopen("test.txt", "w");

/* Test if the file was successfully opened */
if(filename == NULL) {
    printf("Error\n");
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    exit(1);
} /* End if */
```

To read a file, _stdio.h_ function has a constant called _EOF_ for _end of file_, so we can read all the file's content with a loop until the program finds the _EOF_:

```C
int character;

while((character = fgetc(filename) != EOF))
    printf("%c", character);

fclose(filename);
```

The _fgetc()_ function is to get one char at each execution until the while loop finds the _EOF_. It's also important to note that characters must be an integer because _EOF_ character is out of ASCII scope. (ASCII has 256 characters) and we need to be able to read from 0 to 255 characters that is outside of ASCII range. Since integers and characters can be easily converted into each other, we can use this way. *REVISE*

Check at _source/files/fileRead.c_ as example, reading the _text.txt_ file and printing all of it's content on the console.

We can also open a file to read and then write some content in it. Check _readandwrite.c_ for some nice works with it. When writing the file we can have a different extension for the project for instance.

#### Functions _fprintf()_ and _fscanf()_ when working with text files only.

We can use _fprintf()_ and _fscanf()_ when working with files

Remember that _printf()_ has the following prototype:

```C
printf("String to be printed\n", variables);
```

For _fprintf()_, it has the following function prototype:

```C
fprintf(filePointer, "%c", characterVariable);
```

Remember that _scanf()_ has the following prototype:

```C
scanf("%c", &character);
```

For _fscanf()_ the following function prototype:

```C
fscanf(fileRead, "%c", &characterVariable);
```

Where: _fileRead_ and _filePointer_ are the file's pointer.

We can also write full strings on the file using _fputs()_ and also _puts()_.

```C
puts("Writing in the console");
fputs("Writing in the file", filePointer);
```

We can also create and read files from external folders, just pointing the right path.

*Exercise*: Write a program to cryptograph a text file, moving the characters three positions up (Manipulating the ASCII like char + 3). Then write a program that receives this text and decrypt it saving in a new file.

Implemented as encryptit.

#### Working with Binary files

Binary files can store a lot of different information from programs like data, variable contents, parameters. When dealing with binary files, we write bytes thru a vector and we can use access functions like _fread_ and _fwrite_ to access elements directly.

Os arquivos binários salvam vários bytes em 1 arquivo, cada byte preenche um determinado endereço do arquivo. No endereço 0 gravamos um dado, no endereço 1 outro...

Cada endereço tem a dimensão de 8bits. Quando armazenamos um inteiro (short) esse inteiro tem 2 bytes, quando é long, 4 bytes. Float também 4 bytes, double 8 bytes...

Entao a mesma memoria que o tipo de dado ocupa no computador ocupa também no arquivo binário

> Remember that 8bits = 1 byte


_fwrite's_ prototype:

```C
int fwrite(const void *pointer, int size, int number, FILE *filename);
```

Where _*pointer_ is a pointer to _void_ that can point to any type and stores the address of what we want to store in file, _size_ is the size (in bytes) of each element to be stored. Is a best practice to use _sizeof()_ function to get the required size. _number_ is the element's number we are going to write and _*filename_ is the file's pointer.

> Podemos declarar um ponteiro do tipo void que aponta pra qualquer tipo

A sample to a program that writes 10 bytes in a binary file:

```C
main(){

    FILE *filename;

    char vector[10] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};

    filename = fopen("info.dat", "wb"); /* Open in write binary mode */

    /* Test if open successfully */

    fwrite(vector, sizeof(char), 10, filename);

    fclose(filename);
} /* End main */
```

!!! I It's a nice idea to see how float numbers are stored in the memory

Function _feof()_ ...

Direct access on binary files:

functions: _fseek()_ _rewind_ _ftell_...

_fseek()_ prototype:

```C
int fseek(FILE *filename, long offset, int org);
```

Where _offset_ is the number of bytes we want to forward (positive value) or rewind (negative value) in the file. _org_ indicates the start place in the file where the skips will begin, this parm has 3 constants:

 - SEEK_SET (or 0) - skips from the file's beginning position.
 - SEEK_CUR (or 1) - skips from the file's current position.
 - SEEK_END (or 2) - skips from the file's end position.

A program to read the file's size without the need of a complete file scan:

```C
main(){
    FILE *filename;

    filename = fopen("file.bin", "rb");

    /* Test if opens with no error */

    fseek(filename, 0, SEEK_END);

    printf("%ld bytes\n", ftell(filename));
}
```

> Exercise - Write a program that enters 10 temperature value and stores in a temperature.dat. User must enter 10 new values after showing

!!! S SECTION NOT READY

<a id="page7"></a>

## Structures in C

Structures, or _structs_ in C are data structures where we can store data with different types. We are going to see _unions_, _enums_ and _typedef_ in C

Structures are data sets where we can store different types of data and access them with a common element, here's the structure's syntax in C:

```C
struct tagName {
   type member1;
   type member2;
};
```

The _tagName_ is optional in some contexts, for instance when the structure has only one variable, or referral.

We can initialize a struct by defining it's tagName, variables and referrals like the struct customer:

```C
/* This is a variable, type struct customer */

struct customer{
    char name[10];
    char address[50];
    char city[30];
    char phone[20];
    int postal;
}infos ; /* Structure's variable */

/* Other way of doing this */
struct customer infos;

infos.postal = 12345;

printf("Customer's postal code is %d\n", infos.postal);

/* We can also function gets() to store value inside a variable like */
printf("Enter customer's name >>> ");
gets(infos.name);

printf("Welcome, %s\n", infos.name);

...
```

Now we can work with all variables inside it using the struct variable and an operator called _dot ._. For instance, we want to store the integer postal code, we could do it by:

```C
main(){
    infos.postal;
}
```

We can have different referrals to the structure, using the customer as example:

```C
/* This is a variable, type struct customer */
struct customer{
    char name[10];
    char address[50];
    char city[30];
    char phone[20];
    int postal;
}infos, data, information ; /* Structure's variable - referral */
```

We can also pass elements to a function in the same way as any other variable, only remember to use the dot operator:

```C
struct test{
    float alpha;
    int beta;
    char delta[10];
}theta;

/* We will pass the element alpha to the function1 */
function1(theta.alpha);

/* But if we want to work with the addresses */
function(&theta.beta);
function2(&theta.alpha);
function3(theta.delta); /* Because delta is a vector */
```

One example at _/structures/clock.c_ we will work to pass more than 1 structure to a function. But the syntax is:

```C
type function(struct tagName variable);
```

#### Declaring a pointer to a structure

We can declare a pointer to a structure in the two following ways:

```C
struct tagName {
   type member1;
   type member2;
} *pointer;

/* Or we could do it like: */
struct tagName {
   type member1;
   type member2;
};

struct tagName *pointer;
```

Why is it important to access struct's content using pointers? When we are passing data from struct to function, we can pass the struct's address instead of complete struct, this gives us more processing speed, saving processing time when processing or refreshing data for this structure.

When working with pointers to structures, we will use a new operator in C, the arrow pointer _->_ in this way:

```C
struct tagName {
   type member1;
   type member2;
} referralName;

struct tagName *pointer;

main(){
    pointer = &referralName;

    pointer->member1 = data;

    printf("%s", pointer->member1); /* Would print the data stored in member1 */

}
```

Another syntax instead of the _->_ operator would be the following example, but it's not elegant and can cause some confusion when reading the source code.

```C
struct tagName {
   type member1;
   type member2;
} referralName;

struct tagName *pointer;

main(){
    pointer = &referralName;

    (*pointer).member1 = data;

    printf("%s", (*pointer).member1); /* Would print the data stored in member1 */

}
```

> More examples at at _/structures/structPointers1.c_...

A function that would receive a pointer as parms would have the following syntax:

```C
type function(struct tagName *pointer);
```

#### Unions in C

_Unions_ are like structures, they even follow the same syntax, but unions are variable's groups with different types that will share the same address. Syntax:

```C
union tagName{
    type value1;
    type value2;
} referral;
```

We can write more efficient programs using unions specially when writing to files since all the data will occupy the same address.

> Note: I won't go that deep right now into unions but there's an example at _/structures/unions.c_ that shows how to deal with them

#### Enumeration (enum) in C

Enumeration is a special type that represents a group of *constants*, where each declared symbols represents an *integer value*.

Enum is declared in the following syntax:

```C
enum level {
    low,    /* It will be assigned the value 0 */
    medium, /* 1 */
    high    /* 2 ... */
} temperature;

/* It also can be declared as */
enum level {low, medium, high};
```

They are useful when we want to group a set list for instance, so the code can be more friendly and readable, in a _switch_ statement for instance:

```C
switch(temperature){
    case low: turnoffAC(); break;
    case medium: openWindow(); break;
    case high: turnonAC(); break;
} /* End switch */
```

Example at _/structures/enum.c_...

#### Typedef - define new types in C

A method to define new types in C is _typedef_ where we can use it with _structs_, _unions_, _enum_ and even simpler C types. 

For instance: we know that real is the set of all numbers, so we can store every real as a float in C. We can define a type called real to declare float numbers:

```C
typedef float real;

main(){
    real pi; /* define pi as a real number */

    pi = 3.1415; /* Store pi with it's 4 first digits */
    printf("%.4f\n", pi);
}
```

Typedef is good for portability between different machines since each architecture can have different values for each type.

> Exercise: Implement the customer sign up program to study further concepts like nested structures.

<a id="page8"></a>

## Bit to bit operations and bits fields

C language allows us to work in low levels working with the hardware itself. bit wise, bit to bit, bit field (for systems with low memory)... develop further

#### Operators to manipulate bits

_not_ operator that complements the bit, on the register below:

```C
unsigned char reg1 = 0x80; /* bin: 1000 0000*/

/* Operators to manipulate bits in C */
reg1 = ~reg1; /* 7F - 0111 1111 */
```

_shift right_ shifting to right _>>_: 

```C
/* Another operator - shift right >> shift_times */

reg1 = reg1 >> 1; /* Will shift from 0111 1111 to 0011 1111*/
printf("After shifting right 1 time: %.2X\n", reg1);
```

_shift left_ shifting to left _<<_: 

_AND_, _OR_ and _XOR_:

For a _XOR_ output to be True, the amount of True inputs must be *odds*

!!!!! FINISH THIS

A function to print binary:

```C
void printBin(unsigned char reg){

    for (int i = 7; i >= 0; i--){
        (reg>>i) & 1 ? putchar('1') : putchar('0');
    } /* End for */

    printf("bin\n");
}
```
> Exercise: Explain the function above

(reg>>i) & 1 - bits mask

#### Bits mask

Operators bit to bit can be used in the bits mask concept, we use it when we want to keep/remove, concatenate or invert punctual bits

!!!! D Develop more too

##### Concatenating bits 

!!!! D Develop more too

#### Bits field

Bits fields are an extension for structs and it can be used when mapping registers on microcontrollers or displaying information in a single bit in the program, it's syntax:

```C
struct reg{
    unsigned name : size_in_bits;
    .
    .
    .
} regist;
```

Unsigned because it's an integer with no signal
: operator 

!!!! R Revise too

> Do the exercise after revision

<a id="page9"></a>

## Dynamic Memory Allocation

Dynamic Memory Allocation can help us when working with higher amount of data, it reservers the necessary space in memory during the execution for the current application. This approach is better than allocating a bigger amount of memory for a vector for instance, by declaring it bigger than it needs to be. 

If you need a char vector but you don't know exactly the size of it, it could be 10 bytes or 1000 bytes. Usually it would be declared a big one like _vector[1000]_, but this approach is not good because either this space will never be used or it might get full and overflow the memory.

To deal with cases like that, C allows the programmer to dynamically allocate the memory during the program's execution, increasing the size when needed or freeing it when not needed anymore.

The first function to work with these cases is the _malloc()_ function from _stdlib_, which means _memory allocation_. The _malloc()_ function allocates size bytes of memory and returns a pointer to the allocated memory. It's syntax is:

```C
void *malloc(size_t size);
```

Where size_t is usually defined by _unsigned int_ on the _stdlib.h_ library by a _typedef_. The function _malloc_ creates a block _size_ with _n bytes_ and returns a pointer to this block. If the allocation fails, the function returns _NULL_.

Free function ...

Memory allocation is also good when reading files and doing a processing from them because the program can allocate the sufficient memory amount to deal with it.

Another resource when working with memory allocation is the _calloc()_ function. The _calloc()_ function contiguously allocates enough space for _count_ objects that are _size_ bytes of memory each and returns a pointer to the allocated memory.  The allocated memory is filled with bytes of value zero. It's syntax is:

```C
void *calloc(size_t count, size_t size);
```

Where it will allocate a memory amount equal the product of _count_ and _size_ (_count_ x _size_).

The below function returns a pointer to a vector of _amount_ x _long_:

```C
long *vectorLong(unsigned amount){
    long *palloc;

    palloc = calloc(amount, sizeof(long));

    if(!palloc){
        printf("Insufficient Memory\n");
        exit(1);
    }

    return palloc;
} /* End function */
```

Another resource is _realloc()_ function (reallocation function). This function tries to change the memory size that was allocated previously and pointed by _pointer_ for the _size_ type. It will return a pointer to the memory block, and it can move this block to increase size. If _pointer_ is _NULL_, _realloc_ will return a pointer to the allocated memory. If _size_ is 0, the memory pointed by _pointer_ will be free. It's syntax is:

```C
void *realloc(void *pointer, size_t size);
```

The code in _/memory allocation/reallocExample.c_ is used when trying to reallocate space to concatenate two strings.

> Exercise: Write a binary reader that shows in the screen all bytes organized in the screen. This bytes vector to show the content must be dynamically allocated. The display should be like:

```sh
00 01 02 03 04 05 06 07 08 09
-- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- --
...
```

All other dynamic memory allocations functions can be found in the _malloc.h_ library.

## windows.h library for software development in Windows - look for Mac and Linux libraries (MacWindows.h)

## Pausing theoretical part, will focus on exercises now and finish the files and bit to bit sessions!