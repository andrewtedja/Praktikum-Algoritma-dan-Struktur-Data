#include <stdio.h>


int main() {
    int num, temp, sum;
    scanf("%d", &num);
    sum = 0;
    while (num > 0) {
        temp = num % 10;
        num = num / 10;
        sum += temp;
    }
    printf("%d", sum);
}