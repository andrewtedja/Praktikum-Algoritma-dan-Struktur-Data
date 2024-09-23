#include <stdio.h>

int main() {
    int a, b, i;
    scanf("%d %d", &a, &b);

    printf("%d", a);
    for (i = a; i <= b;) {
        if ( i%2 == 0 ) {
            i = i * 2;
        } else {
            i += 1;
        }

        if (i > b) {
            break;
        }

        printf(" %d", i);
    }
    printf("\n");
    return 0;
}