#include <stdio.h>
#include <stdlib.h>

int fileSize(FILE file);

int main(){

	FILE *filename;

	int character;

    /* Test if the file was successfully opened */
    if((filename = fopen("writefile.txt", "r")) == NULL) {
        printf("Error\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    } /* End if */
	
    printf("This text has %d characters\n", fileSize(*filename));

	fclose(filename);

	printf("File reading was successfully completed. Goodbye! :)\n");
    
    return 0;
} /* End main */

int fileSize(FILE file){
    int character,
        counter = 0;

    /* Begin while to count characters in text except EOF */
    while((character = fgetc(&file)) != EOF)

        /* Count everything except lines */
        if(character != 0x0A) counter++;
    
    return counter;
}

