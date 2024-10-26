#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
char currentchar;
Word currentWord;

int main() {
    int i = 0;
    int tot;

    START();
    IgnoreBlanks(); 

    while (!EOP && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i >= NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }

    printWord(currentWord);
    printf("\n%d\n", currentWord.Length);
}