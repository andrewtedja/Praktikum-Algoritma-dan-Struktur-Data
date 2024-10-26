#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"

int main() {
    int N;
    scanf("%d", &N);

    ListDin l1;
    CreateListDin(&l1, N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &ELMT(l1, i));
    }
    NEFF(l1) = N; 

    int *max_left = (int *)malloc(N * sizeof(int));
    int *min_right = (int *)malloc(N * sizeof(int));

    max_left[0] = -1; 
    min_right[N - 1] = 1000001; 

    // Compute max_left
    for (int i = 1; i < N; i++) {
        if (ELMT(l1, i - 1) > max_left[i - 1]) {
            max_left[i] = ELMT(l1, i - 1);
        } else {
            max_left[i] = max_left[i - 1];
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        if (ELMT(l1, i + 1) < min_right[i + 1]) {
            min_right[i] = ELMT(l1, i + 1);
        } else {
            min_right[i] = min_right[i + 1];
        }
    }

    int valid_pivots = 0;
    for (int i = 0; i < N; i++) {
        boolean isValid = true;

        if (i > 0 && max_left[i] > ELMT(l1, i)) {
            isValid = false;
        }

        if (i < N - 1 && ELMT(l1, i) >= min_right[i]) {
            isValid = false;
        }

        if (isValid) {
            valid_pivots++;
        }
    }

    printf("%d\n", valid_pivots);

    dealocateList(&l1);
    free(max_left);
    free(min_right);

    return 0;
}
