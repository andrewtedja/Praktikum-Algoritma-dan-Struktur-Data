#include <stdio.h>
#include "listdin.h"
#include "boolean.h"

int main() {
    int n;
    scanf("%d", &n); 

    ListDin l1;
    CreateListDin(&l1, n + 2);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertLast(&l1, value);
    }

    int newStart, newEnd;
    scanf("%d %d", &newStart, &newEnd); 

    ListDin result;
    CreateListDin(&result, n + 2);

    int i = 0;
    boolean inserted = false;

    while (i < NEFF(l1)) {
        int currStart = ELMT(l1, i);
        int currEnd = ELMT(l1, i + 1);

        if (!inserted && newStart < currStart) {
            if (newEnd >= currStart) {
                currStart = (newStart < currStart) ? newStart : currStart;
                currEnd = (newEnd > currEnd) ? newEnd : currEnd;

                i += 2;
            } else {
                insertLast(&result, newStart);
                insertLast(&result, newEnd);
                inserted = true;
            }
        } else if (!inserted && newStart <= currEnd) {
            currStart = (newStart < currStart) ? newStart : currStart;
            currEnd = (newEnd > currEnd) ? newEnd : currEnd;
            i += 2;
            inserted = true;
        } else {
            i += 2;
        }

        while (i < NEFF(l1)) {
            int nextStart = ELMT(l1, i);
            int nextEnd = ELMT(l1, i + 1);

            if (currEnd >= nextStart) {
                currEnd = (currEnd > nextEnd) ? currEnd : nextEnd;
                i += 2;
            } else {
                break;
            }
        }

        insertLast(&result, currStart);
        insertLast(&result, currEnd);
    }


    if (!inserted) {
        if (NEFF(result) >= 2 && ELMT(result, NEFF(result) - 1) >= newStart) {
            ELMT(result, NEFF(result) - 1) = (newEnd > ELMT(result, NEFF(result) - 1)) ? newEnd : ELMT(result, NEFF(result) - 1);
        } else {
            insertLast(&result, newStart);
            insertLast(&result, newEnd);
        }
    }


    for (int j = 0; j < NEFF(result); j++) {
        printf("%d", ELMT(result, j));
        if (j != NEFF(result) - 1) {
            printf(" ");
        }
    }
    printf("\n");


    dealocateList(&l1);
    dealocateList(&result);

    return 0;
}
