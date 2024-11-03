#include <stdio.h>
#include "mesinkata.h"

int char_to_integer(char x){
    switch (x){
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case '0' : return 0;
        default : return -1;
    }
}

int string_to_integer(){
    int num = 0 ; 
    for ( int i = 0 ; i < currentWord.Length; i++){
        num = num * 10 + char_to_integer(currentWord.TabWord[i]);
    }
    return num;
}

int main(){
    STARTWORD();

    if ( EndWord){
        printf("\n");
        return 0;
    }
    int encrypt = string_to_integer() % 26;
    ADVWORD();
    int shift_char;

    while ( !EndWord){
        for ( int i = 0 ; i < currentWord.Length; i++){
            if ( currentWord.TabWord[i] <= 'z' && currentWord.TabWord [i]>= 'a'){
                shift_char= (currentWord.TabWord[i] - encrypt < 'a') ? -1 * (26 - encrypt) : encrypt;
                printf("%c", currentWord.TabWord[i] - shift_char);
            }
            else if ( currentWord.TabWord[i] <= 'Z' && currentWord.TabWord [i] >= 'A'){
                shift_char= (currentWord.TabWord[i] - encrypt < 'A') ? -1 * (26 - encrypt) : encrypt;
                printf("%c", currentWord.TabWord[i] - shift_char);
            }
            else{
                printf("%c", currentWord.TabWord[i]);
            }
        }

        ADVWORD();
        if(!EndWord){
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}