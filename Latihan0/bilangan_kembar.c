#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b, sum = 0, last_digit, all_same;
    scanf("%d", &a);
    scanf("%d", &b);

    for (int i = a; i <= b; i++) {
        last_digit = i % 10;
        int num = i;
        bool all_same = true;

        while (num > 0) {
            if (last_digit != num%10) {
                all_same = false;
                break;
            }
            num /= 10;
        }
        if (all_same) {
            sum++;
        }
    }
    printf("%d", sum);
}