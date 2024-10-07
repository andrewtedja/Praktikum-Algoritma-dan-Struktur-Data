#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main() {
    ListDin(l1);
    CreateListDin(&l1, 0);
    int Q;
    int tipe; //query

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d", &tipe);
        if (tipe == 1) {
            int x;
            scanf("%d", &x);
            if (isEmpty(l1)) {
                expandList(&l1, 1);
                insertLast(&l1, x);
            } else if (isFull(l1)) {
                expandList(&l1, CAPACITY(l1));
                insertLast(&l1, x);
            }
        } else if (tipe == 2) {
            IdxType val;
            deleteLast(&l1, &val);
            if (NEFF(l1) <= round(CAPACITY(l1)/2)) {
                CAPACITY(l1) = round(CAPACITY(l1)/2);
            }
        } else { // query 3
            printf("%d ", CAPACITY(l1));
            printList(l1);
            printf("\n");
        }
    }

}