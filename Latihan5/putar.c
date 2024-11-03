#include <stdio.h>
#include "mesinkata.h"

void reverseWord() {
    int i, len = currentWord.Length;
    for (i = 0; i < len / 2; i++) {
        char temp = currentWord.TabWord[i];
        currentWord.TabWord[i] = currentWord.TabWord[len - i - 1];
        currentWord.TabWord[len - i - 1] = temp;
    }
}

int main() {
    int wordIndex = 1, i;
    STARTWORD();

    while (!EndWord) {
        if (wordIndex % 2 == 1) reverseWord();

        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }

        ADVWORD();
        if (!EndWord) printf(" ");
        
        wordIndex++;
    }

    printf("\n");
    return 0;
}