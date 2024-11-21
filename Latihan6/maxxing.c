#include <stdio.h>
#include "boolean.h"
#include "stack.h"

#define MAXN 100010

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    int a[MAXN];
    int prev_smaller[MAXN];
    int next_smaller[MAXN];
    int ans[MAXN];
    int i, len, idx;
    Stack S;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= N; i++) {
        ans[i] = 0;
    }

    CreateEmpty(&S);
    for (i = 0; i < N; i++) {
        while (!IsEmpty(S) && a[InfoTop(S)] >= a[i]) {
            Pop(&S, &idx);
        }
        if (IsEmpty(S)) {
            prev_smaller[i] = -1;
        } else {
            prev_smaller[i] = InfoTop(S);
        }
        Push(&S, i);
    }

    CreateEmpty(&S);
    for (i = N - 1; i >= 0; i--) {
        while (!IsEmpty(S) && a[InfoTop(S)] >= a[i]) {
            Pop(&S, &idx);
        }
        if (IsEmpty(S)) {
            next_smaller[i] = N;
        } else {
            next_smaller[i] = InfoTop(S);
        }
        Push(&S, i);
    }

    for (i = 0; i < N; i++) {
        len = next_smaller[i] - prev_smaller[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    for (i = N - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (i = 1; i <= N; i++) {
        printf("%d", ans[i]);
        if (i != N) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
