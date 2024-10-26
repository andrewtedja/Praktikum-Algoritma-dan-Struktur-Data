#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

int main() {
    int N, i, j, steps = 0, currHeight;
    ListDin l1;


    scanf("%d", &N);

    CreateListDin(&l1, N);

    for (i = 0; i < N; i++) {
        scanf("%d", &currHeight);

        int position = NEFF(l1); 
        for (j = 0; j < NEFF(l1); j++) {
            if (ELMT(l1, j) > currHeight) {
                position = j; 
                break;
            }
        }

        steps += NEFF(l1) - position;
        for (j = NEFF(l1); j > position; j--) {
            ELMT(l1, j) = ELMT(l1, j - 1);
        }

        ELMT(l1, position) = currHeight;
        NEFF(l1)++;
    }


    printf("%d\n", steps);


    dealocateList(&l1);

    return 0;
}
