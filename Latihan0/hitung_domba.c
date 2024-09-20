#include <stdio.h>

int main() {
    int n;
    int multiplier;

    scanf("%d", &n);
    scanf("%d", &multiplier);

    for (int i = 1; i <= n; i++) {
        if (i % multiplier == 0) {
            printf("happy\n");
        } else {
            printf("%d\n", i);
        }
    }
}