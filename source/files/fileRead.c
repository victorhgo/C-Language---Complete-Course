#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *filename;

	int character;

    /* Test if the file was successfully opened */
    if((filename = fopen("text.txt", "r")) == NULL) {
        printf("Error\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */
	
	while((character = fgetc(filename)) != EOF)
    	printf("%c", character);

	fclose(filename);

	printf("File reading was successfully completed. Goodbye! :)\n");
    
    return 0;
} /* End main */

