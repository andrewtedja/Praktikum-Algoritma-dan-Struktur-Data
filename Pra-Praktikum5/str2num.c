#include <stdio.h> 
#include <string.h>
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "boolean.h"

boolean compareWord(Word w, char* s) {
    int len = strlen(s);
    if (w.Length != len) return false;
    for (int i = 0; i < len; i++) {
        if (w.TabWord[i] != s[i]) return false;
    }
    return true;
}

boolean is_unit(Word w) {
    return get_unit_value(w) != -1;
}

int get_unit_value(Word w) {
    if (compareWord(w, "nol")) return 0;
    else if (compareWord(w, "satu")) return 1;
    else if (compareWord(w, "dua")) return 2;
    else if (compareWord(w, "tiga")) return 3;
    else if (compareWord(w, "empat")) return 4;
    else if (compareWord(w, "lima")) return 5;
    else if (compareWord(w, "enam")) return 6;
    else if (compareWord(w, "tujuh")) return 7;
    else if (compareWord(w, "delapan")) return 8;
    else if (compareWord(w, "sembilan")) return 9;
    else return -1;
}

boolean is_teens(Word w) {
    return compareWord(w, "sepuluh") || compareWord(w, "sebelas");
}

int get_teens_value(Word w) {
    if (compareWord(w, "sepuluh")) return 10;
    else if (compareWord(w, "sebelas")) return 11;
    else return -1;
}

boolean is_belas(Word w) {
    return compareWord(w, "belas");
}

boolean is_tens(Word w) {
    return compareWord(w, "puluh");
}

boolean is_hundred(Word w) {
    return compareWord(w, "ratus");
}

boolean is_seratus(Word w) {
    return compareWord(w, "seratus");
}

void printWord(Word w) {
    for (int i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}

int parse_number_phrase(Word *lastWord) {
    int total = 0;
    boolean parsing = true, found = false;
    Word prevWord = currentWord;

    while (parsing && !EndWord) {
        if (is_unit(currentWord)) {
            int unit = get_unit_value(currentWord);
            prevWord = currentWord;
            ADVWORD();

            if (!EndWord && is_hundred(currentWord)) {
                total += unit * 100;
                prevWord = currentWord;
                ADVWORD();
                found = true;
            } else if (!EndWord && is_belas(currentWord)) {
                total += unit + 10;
                prevWord = currentWord;
                ADVWORD();
                found = true;
            } else if (!EndWord && is_tens(currentWord)) {
                total += unit * 10;
                prevWord = currentWord;
                ADVWORD();
                if (!EndWord && is_unit(currentWord)) {
                    total += get_unit_value(currentWord);
                    prevWord = currentWord;
                    ADVWORD();
                }
                found = true;
            } else {
                total += unit;
                found = true;
            }
        } else if (is_seratus(currentWord)) {
            total += 100;
            prevWord = currentWord;
            ADVWORD();
            found = true;
        } else if (is_teens(currentWord)) {
            total += get_teens_value(currentWord);
            prevWord = currentWord;
            ADVWORD();
            found = true;
        } else {
            parsing = false;
        }
    }
    *lastWord = prevWord;
    return found ? total : -1;
}

int main() {
    STARTWORD();
    Word lastWord;
    boolean firstWord = true;

    while (!EndWord) {
        int number = -1;
        if (is_unit(currentWord) || is_teens(currentWord) || is_seratus(currentWord)) {
            number = parse_number_phrase(&lastWord);
            if (number != -1) {
                Word w = lastWord;
                int len = w.Length, puncIndex = len;

                for (int i = 0; i < len; i++) {
                    if (!((w.TabWord[i] >= 'a' && w.TabWord[i] <= 'z') || 
                          (w.TabWord[i] >= 'A' && w.TabWord[i] <= 'Z'))) {
                        puncIndex = i;
                        break;
                    }
                }

                if (!firstWord) printf(" ");
                printf("%d", number);

                for (int i = puncIndex; i < w.Length; i++) {
                    printf("%c", w.TabWord[i]);
                }
                firstWord = false;
                continue;
            }
        }

        if (!firstWord) printf(" ");
        printWord(currentWord);
        firstWord = false;
        ADVWORD();
    }

    printf("\n");
    return 0;
}
