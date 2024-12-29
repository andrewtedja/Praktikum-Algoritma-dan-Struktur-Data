/**
 * Nama: Andrew Tedjapratama
 * NIM: 13523148
 * Jawaban dari soal Monitoring
 */

#include <stdio.h>

void trap(){
    printf("trap");
}

void Monitoring() {
    int a, b, c, d, e, f;
    printf("Input: ");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if (a == 1 && b == 2 && c == 4 && d == 8 && e == 16 && f == 17) {
        printf("Berhasil!");
    } else {
        trap();
    }
    return;
}

int main() {
    Monitoring();
    return 0;
}