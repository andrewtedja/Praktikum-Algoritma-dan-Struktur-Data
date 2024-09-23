#include <stdio.h>


int fibo(int n, int a, int b) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return a;
    }
    else if (n == 2) {
        return b;
    }
    else {
        return fibo(n-1, a, b) + fibo(n-2, a, b);
    }
}

int main() {
    int n;
    int a, b;
    int fibo_sum;
    scanf("%d %d %d", &n, &a, &b);

    fibo_sum = fibo(n, a, b);
    printf("%d\n", fibo_sum);

    return 0;
}