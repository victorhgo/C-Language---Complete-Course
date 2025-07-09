#include <stdio.h>
#include <stdlib.h>

void displayData(FILE *filename);
void writeData(FILE *filename);

int main(){
    FILE *loggerRead,
         *loggerWrite;

    float temperature[10] = {0};

    /* Open logger.dat as read binary */
    loggerRead = fopen("logger.dat", "rb");

    /* Test if the file is ok when opening for read */
    if(loggerRead == NULL){
        printf("File does not exist\n");
        printf("Creating file...\n");
        writeData(loggerWrite);
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        return 0;
    }

    /* Display all data from file */
    displayData(loggerRead);
    
    /* Closes the file in read mode */
    fclose(loggerRead);
    printf("\nFile successfully read. Now opening in writing mode\n");

    writeData(loggerWrite);

    return 0;
}

void displayData(FILE *filename){

    float temperature[10] = {0};
    /* Prints the content in loggerRead!!! */
    fread(temperature, sizeof(float), 10, filename);

    for(int i = 0; i < 10; i++) printf("Temp %d: %.2f\n", i, temperature[i]);

} /* Function display data */

void writeData(FILE *filename){
    /* Open logger.dat as write binary */
    filename = fopen("logger.dat", "wb");

    printf("Opening file...\n");
    /* Test if the file is ok when opening for writing it */
    if(filename == NULL){
        printf("Error when creating the file\n");
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        exit(0);
    }

    printf("Enter the temperatures in Celsius\n");

    float temperature[10];
    /* Receives the values on temperature[] and stores them in logger */
    for(int i = 0; i < 10; i++){
        printf("Temp %d >>> ", i);
        scanf("%f", &temperature[i]);
    }

    /* To write the temperature into logger */
    fwrite(temperature, sizeof(float), 10, filename);

    /* Close the file */
    fclose(filename);

    /* Print if successful */
    printf("Successfully written on logger! Goodbye :)\n");
}