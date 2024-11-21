#include "prioqueue.h"
#include "boolean.h"
#include <stdio.h>

void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq) {
    return (IDX_HEAD(pq) == IDX_UNDEF) || (IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq) {
    return length(pq) == CAPACITY;
}

int length(PrioQueue pq) {
    if (isEmpty(pq)) return 0;
    else if (IDX_HEAD(pq) <= IDX_TAIL(pq)) return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    else return (IDX_TAIL(pq) + 1) + (CAPACITY - IDX_HEAD(pq));
}

void enqueue(PrioQueue *pq, ElType val) {
    boolean akhir = true;
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    }
    else {
        IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
        for (int i = IDX_HEAD(*pq), count = 0; count < length(*pq) - 1; i = (i+1) % CAPACITY, count++) {
            if ((*pq).buffer[i] < val) {
                for (int j = IDX_TAIL(*pq), count2 = count; count2 < length(*pq); j = (j <= 0 ? CAPACITY-1 : j-1), count2++) {
                    (*pq).buffer[j] = (*pq).buffer[(j <= 0 ? CAPACITY-1 : j-1)];
                }
                (*pq).buffer[i] = val;
                akhir = false;
                break;
            }
            else continue;
        }
        if (akhir) TAIL(*pq) = val;
    }
}

void dequeue(PrioQueue *pq, ElType *val) {
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % CAPACITY;
    }
}

void displayPrioQueue(PrioQueue pq) {
    printf("[");
    if (IDX_HEAD(pq) != IDX_UNDEF && IDX_TAIL(pq) != IDX_UNDEF) {
        for (int i = IDX_HEAD(pq), count = 0; count < length(pq); i = (i+1) % CAPACITY, count++) {
            printf("%d",pq.buffer[i]);
            if (i != IDX_TAIL(pq)) printf(",");
        }
    }
    printf("]\n");
}