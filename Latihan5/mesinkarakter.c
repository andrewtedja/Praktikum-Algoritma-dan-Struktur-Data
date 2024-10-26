#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;    
boolean EOP; 

FILE *pita ;
int retval;

void START(){
    pita = stdin;
    ADV();
    }

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP){
        fclose(pita);
    }
}

