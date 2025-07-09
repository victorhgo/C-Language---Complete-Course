/* Few notes on the format specifiers used in this code:

- The %hd format specifier is used to print short integer 
values in C. The h indicates that the value is short, 
and the d specifies that it is a short integer.

- &p The %p format specifier prints the memory address of a 
pointer variable, which stores the memory address of another 
variable it is pointing to. This is particularly useful for d
ebugging purposes, allowing developers to verify the addresses 
stored in pointer variables.

- 6X hexadecimal - uppercase

- %3h - 3 indicates that it will be short wide

Further reference: https://www.wscubetech.com/resources/c-programming/format-specifiers

*/

#define mapA printf("            |---------|\n");                   \
             printf("  variable2 |  %3hd    | %p\n", variable2, &variable2);  \
             printf("            |---------|\n");                   \
             printf("            |         |\n");                   \
             printf("            |---------|\n");                   \
             printf("  variable1 |  %3hd    | %p\n", variable1, &variable1);  \
             printf("            |---------|\n");                   \
             printf("            |         |\n")                 
              
#define mapB printf("            |---------|\n");                    \
             printf("  pointer   | %X | %p\n", pointer, &pointer);   \
             printf("            |---------|\n");                      \
             printf("            |         |\n");                      \
             printf("            |---------|\n");                      \  
             printf("  Memory:   | Content | Physical Address   \n")