/**
 * Nama: Andrew Tedjapratama
 * NIM: 13523148
 * Jawaban dari soal Bakenohana
 */

#include <stdio.h>

void trap(){
    printf("trap");
}

void check(int a, int b) {
    int counter = 0;
    int current_char = a;
    int target_char = b;

    while (counter <= 5) {
        int temp = counter * 3 + current_char;
        int adjusted = ((temp * 0x4ec4ec4f) >> 3) - (temp >> 31);
        adjusted = temp - (adjusted * 26) + 0x61;

        if (current_char == adjusted) {
            break;
        }
        counter++;
    }

    if (counter > 5) {
        trap();
    }
    return;
}

void Bakenohana(char *input) {
    int value;

    check(input[0], 0x69);
    check(input[1], 0x66);
    check(input[2], 0x73);
    check(input[3], 0x74);
    check(input[4], 0x69);
}