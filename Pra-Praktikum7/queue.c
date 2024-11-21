#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    if (isEmpty(q)){
        return false;
    }
    int nexttail = (IDX_TAIL(q) + 1) % CAPACITY;
    return nexttail == IDX_HEAD(q);
}

int length(Queue q) {
    if(isEmpty(q)) {
        return 0;
    }
    if(IDX_HEAD(q) == IDX_TAIL(q)) {
        return 1;
    }
    if(IDX_HEAD(q) > IDX_TAIL(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1;
    }
    return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void enqueue(Queue *q, ElType val) {
    if(isEmpty(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
    }
    else{
        if(IDX_TAIL(*q) != CAPACITY - 1){
            IDX_TAIL(*q)++;
        }
        else{
            IDX_TAIL(*q) = 0;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1) % CAPACITY;
    }
}

void displayQueue(Queue q) {
    ElType val;

    if(isEmpty(q)){
        printf("[]\n");
    }
    else{
        printf("[");
        while (!isEmpty(q)) {
            dequeue(&q, &val);
            if (length(q) != 0) {
                printf("%d,", val);
            } else {
                printf("%d", val);
            }
        }
        printf("]\n");
    }
}