#include <stdio.h>

void decode1(int *xp, int *yp, int *zp) {
    int a = *xp;
    int b = *yp;
    int c = *zp;

    *xp = b;
    *yp = c;
    *zp = a;

}

int main() {
    int *xp, *yp, *zp;
    scanf("%d %d %d", &xp, &yp, &zp);
    printf("%d %d %d", &xp, &yp, &zp);
}