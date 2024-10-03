#include <stdio.h>
#include "point.h"

int main() {
    POINT P1, P2, P3;
    float deltaX, deltaY, angle;

    /* Membaca POINT dari input */
    printf("Masukkan POINT P1 (X Y): ");
    BacaPOINT(&P1);
    printf("Masukkan POINT P2 (X Y): ");
    BacaPOINT(&P2);

    /* Menulis POINT */
    printf("P1: ");
    TulisPOINT(P1);
    printf("\nP2: ");
    TulisPOINT(P2);
    printf("\n");

    /* Operasi relasional */
    if (EQ(P1, P2)) {
        printf("P1 dan P2 sama.\n");
    } else {
        printf("P1 dan P2 tidak sama.\n");
    }

    /* Operasi menentukan letak P1 */
    if (IsOrigin(P1)) {
        printf("P1 adalah titik origin.\n");
    } else if (IsOnSbX(P1)) {
        printf("P1 berada di sumbu X.\n");
    } else if (IsOnSbY(P1)) {
        printf("P1 berada di sumbu Y.\n");
    } else {
        printf("P1 berada di kuadran %d.\n", Kuadran(P1));
    }

    /* Operasi lain: Geser, Mirror, Rotate */
    printf("\nGeser P1: Masukkan deltaX dan deltaY: ");
    scanf("%f %f", &deltaX, &deltaY);
    Geser(&P1, deltaX, deltaY);
    printf("P1 setelah digeser: ");
    TulisPOINT(P1);
    printf("\n");

    printf("Cerminkan P1 terhadap sumbu X: ");
    Mirror(&P1, true);
    TulisPOINT(P1);
    printf("\n");

    printf("Putar P1: Masukkan sudut (derajat): ");
    scanf("%f", &angle);
    Putar(&P1, angle);
    printf("P1 setelah diputar: ");
    TulisPOINT(P1);
    printf("\n");

    /* Menghitung jarak */
    float jarak = Jarak0(P1);
    printf("Jarak P1 ke (0,0): %.2f\n", jarak);

    float panjang = Panjang(P1, P2);
    printf("Panjang garis antara P1 dan P2: %.2f\n", panjang);

    /* Persamaan Linear Dua Variabel */
    PersamaanLinearDuaVariabel(P1, P2);

    return 0;
}