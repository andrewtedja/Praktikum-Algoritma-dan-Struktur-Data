#include <stdio.h>
#include <stdbool.h>
#include "mesinkata.h"

int char_to_integer(char x) {
    switch (x) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1; 
    }
}

int main() {
    char separator = '@';
    bool isAlay;
    int num;
    int digit;
    STARTWORD(); 

    while (!EndWord) {
        isAlay = true;
        num = 0;
        int segment = 0;

        if (currentWord.Length > 1 && currentWord.TabWord[0] == '0' && currentWord.TabWord[1] != separator) {
            isAlay = false;
        }

        int i = 0;
        while (i < currentWord.Length && isAlay) {
            num = 0;
            bool hasDigit = false;

            while (i < currentWord.Length && currentWord.TabWord[i] != separator) {
                digit = char_to_integer(currentWord.TabWord[i]);
                if (digit == -1) {
                    isAlay = false;
                    break;
                }

                if (!hasDigit && digit == 0 && (i + 1 < currentWord.Length) && currentWord.TabWord[i + 1] != separator) {
                    isAlay = false;
                    break;
                }
                hasDigit = true;
                num = num * 10 + digit;
                i++;
            }

            if (num < 0 || num > 255) {
                isAlay = false;
                break;
            }

            segment++;

            if (i < currentWord.Length && currentWord.TabWord[i] == separator) {
                i++;

                if (i >= currentWord.Length || currentWord.TabWord[i] == separator) {
                    isAlay = false;
                    break;
                }
            }
        }

        if (segment != 4) {
            isAlay = false;
        }

        printf("%s", isAlay ? "4Lay" : "ewh");

        ADVWORD(); 

        if (!EndWord) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
