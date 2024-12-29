/**
 * Nama: Andrew Tedjapratama
 * NIM: 13523148
 * Jawaban dari soal Eleven
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void trap() {
    printf("trap");
    return;
}

void feel_like_eleven(int input[7]) {
    printf("Input: ");
    int b = scanf("%d %d %d %d %d %d %d", 
        &input[0], &input[1], &input[2], 
        &input[3], &input[4], &input[5], 
        &input[6]);

    if (b < 7) { 
        trap();
        exit(1);
    }
}

void Eleven() {
    int a[7];
    feel_like_eleven(a);

    for (int i = 1; i <= 7; i++) {
        if (i <= 4) {
            if (a[i - 1] != i * i * i) { 
                trap();
                return;
            }
        } else {
            if (a[i - 1] != 2 * i + 1) { 
                trap();
                return;
            }
        }
    }
    printf("Berhasil!");
}

int main() {
    Eleven();
    return 0;
}
