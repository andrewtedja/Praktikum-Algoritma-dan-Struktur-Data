#include <stdio.h>
#include <math.h>
#include "listdin.h"
#include <stdlib.h>

int main () {
    ListDin(lA);
    CreateListDin(&lA, 0);

    int query, Q;

    int C = CAPACITY(lA);
    scanf("%d", &C);
    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        scanf("%d", &query);
        if (query == 1) {
            int X;
            scanf("%d\n", &X);

            int last = getLastIdx(lA);
            while (X > ELMT(lA, last)) {
                deleteLast(&lA, &ELMT(lA, last));
                last--;
            }
            insertLast(&lA, X);

        } else if (query == 2) {
            printf("%d\n", NEFF(lA));
            printList(lA);
            printf("\n");
        }
    }
}