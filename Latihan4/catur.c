#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix m;
    readMatrix(&m, 8, 8);

    int cekHitamPutih = 0;
    int countHitam = 0;
    int countPutih = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cekHitamPutih++;
            if (i % 2 == 0 && cekHitamPutih % 2 == 1 && (ELMT(m, i, j) == 1)) {
                countHitam++;
            }
            if (i % 2 == 0 && cekHitamPutih % 2 == 0 && ELMT(m, i, j) == 1) {
                countPutih++;
            }
            if (i % 2 == 1 && cekHitamPutih % 2 == 1 && ELMT(m, i, j) == 1) {
                countPutih++;
            }
            if (i % 2 == 1 && cekHitamPutih % 2 == 0 && ELMT(m, i, j) == 1) {
                countHitam++;
            }
        }
        cekHitamPutih = 0;
    }
    printf("%d %d\n", countHitam, countPutih);
}