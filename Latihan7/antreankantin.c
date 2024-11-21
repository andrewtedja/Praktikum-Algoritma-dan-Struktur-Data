#include <stdio.h>
#include <math.h>
#include <string.h>
#include "queue.h"

float average (Queue q)
{
    int panjang = length(q);
    float sum = 0;
    while (!isEmpty(q)) {
        int temp;
        dequeue(&q, &temp);
        sum += temp;
    }
    float average = sum / panjang;
    return average;
}

int main() {
    Queue q, layan;
    CreateQueue(&q);
    CreateQueue(&layan);

    int C;

    while (C != 0) {
        scanf("%d", &C);
        if (C == 1) {
            int X;
            scanf("%d", &X);
            if (isFull(q)) {
                printf("Queue penuh\n");
            } else {
                enqueue(&q, X);
            }
        } else if (C == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            } else {
                int temp;
                dequeue(&q, &temp);
                enqueue(&layan, temp);
            }
        }
    }
    if (C == 0) {
        printf("%d\n", length(layan));
        if (isEmpty(layan)) {
            printf("Tidak bisa dihitung");
        } else {
            printf("%.2f\n", average(layan));
        }
    }
}