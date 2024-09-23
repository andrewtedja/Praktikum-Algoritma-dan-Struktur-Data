#include <stdio.h>

int main() {
    int n;
    int i;
    int j;
    scanf("%d", &n);
    for(i = 1; i<= n; i++) {
        int stars = 2 * (n-i+1) - 1;

        for(j = 1; j < i; j++) {
            printf(" ");
        }

        for(j = 1; j <= stars; j++) {
            printf("*");
        }
    printf("\n");
    }

    return 0;
}