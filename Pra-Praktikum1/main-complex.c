/* File: main.c /
/ Program utama yang menggunakan ADT COMPLEX */

#include <stdio.h>
#include "complex.h"

int main() {
    COMPLEX C1, C2, result;
    float modulus;

    // Baca dua bilangan kompleks
    printf("Masukkan bilangan kompleks pertama:\n");
    BacaCOMPLEX(&C1);

    printf("Masukkan bilangan kompleks kedua:\n");
    BacaCOMPLEX(&C2);

    // Tulis bilangan kompleks yang dibaca
    printf("Bilangan kompleks pertama: ");
    TulisCOMPLEX(C1);

    printf("Bilangan kompleks kedua: ");
    TulisCOMPLEX(C2);

    // Penjumlahan
    result = AddCOMPLEX(C1, C2);
    printf("Hasil penjumlahan: ");
    TulisCOMPLEX(result);

    // Pengurangan
    result = SubtractCOMPLEX(C1, C2);
    printf("Hasil pengurangan: ");
    TulisCOMPLEX(result);

    // Perkalian
    result = MultiplyCOMPLEX(C1, C2);
    printf("Hasil perkalian: ");
    TulisCOMPLEX(result);

    // Pembagian
    result = DivideCOMPLEX(C1, C2);
    printf("Hasil pembagian: ");
    TulisCOMPLEX(result);

    // Modulus dari bilangan kompleks pertama
    modulus = AbsCOMPLEX(C1);
    printf("Modulus bilangan kompleks pertama: %.2f\n", modulus);

    // Modulus dari bilangan kompleks kedua
    modulus = AbsCOMPLEX(C2);
    printf("Modulus bilangan kompleks kedua: %.2f\n", modulus);

    // Konjugasi bilangan kompleks pertama
    result = ConjugateCOMPLEX(C1);
    printf("Konjugasi bilangan kompleks pertama: ");
    TulisCOMPLEX(result);

    // Konjugasi bilangan kompleks kedua
    result = ConjugateCOMPLEX(C2);
    printf("Konjugasi bilangan kompleks kedua: ");
    TulisCOMPLEX(result);

    // Perbandingan apakah dua bilangan kompleks sama (CEQ)
    (CEQ(C1, C2));

    // Perbandingan apakah dua bilangan kompleks tidak sama (CNEQ)
    (CNEQ(C1, C2)) ;
    return 0;
}