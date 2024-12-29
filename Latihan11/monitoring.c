#include <stdio.h>

void Monitoring() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if (a == 1 && b == 2 && c == 4 && d == 8 && e == 16 && f == 17) {
        printf("berhasil");
    } else {
        printf ("trap") ;
    }
    return;
}