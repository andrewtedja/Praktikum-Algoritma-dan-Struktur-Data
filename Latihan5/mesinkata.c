#include "mesinkata.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK && currentChar != MARK){
        ADV();
    }
};


void STARTWORD(){
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }else{
        EndWord = false;
        CopyWord();
    }
    
};


void ADVWORD(){
    IgnoreBlanks();
    if ( currentChar == MARK){
        EndWord = true;
    }else{
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
    int i = 0;

    while ( currentChar != BLANK && currentChar != MARK){
        if( i < NMax){
            currentWord.TabWord[i] = currentChar;
        }
        ADV();
        i++;
    }

    if ( i < NMax){
        currentWord.Length =i ;
    }
    else {
        currentWord.Length = NMax;
    }
}

