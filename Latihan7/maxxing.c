#include <stdio.h>
#include "boolean.h"
#include "prioqueue.h"

int main() {
    int n; scanf("%d", &n);
    PrioQueue pqA, pqB;
    CreatePrioQueue(&pqA);
    CreatePrioQueue(&pqB);

    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&pqA, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&pqB, b);
    }

    long long ans = 0;
    while (!isEmpty(pqA) && !isEmpty(pqB)) {
        int a, b;
        dequeue(&pqA, &a);
        dequeue(&pqB, &b);
        ans += (long long)a * b;
    }

    printf("%lld\n", ans);
    return 0;
}