#include <stdio.h>

int main() {
    int n, k;
    int arr[10000];
    int i;
    int sum = 0;
    scanf("%d %d", &n , &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            sum += arr[i];
        } else {
            sum += 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}