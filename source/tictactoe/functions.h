/* Function's prototypes */

/* Draw board */
void drawBoard(char (*matrix)[3]);

/* Functions to verify if there's winner */
bool verifyRow(char (*matrix)[3]);
bool verifyCol(char (*matrix)[3]);
bool verifyDiag(char (*matrix)[3]);

/* Function to convert from char to numbers */
unsigned mapColumns(char *columns); 