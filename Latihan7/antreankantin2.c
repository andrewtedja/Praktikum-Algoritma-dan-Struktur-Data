#include <stdio.h>
#include <math.h>
#include <string.h>
#include "queue.h"

float average(Queue q) {
    int panjang = length(q);
    float sum = 0;

    while(!isEmpty(q)) {
        int temp;
        dequeue(&q, &temp);
        sum += temp;
    }
    float average = sum / panjang;
    return average;
}

int main() {
    Queue q, layan;
    CreateQueue(&layan);
    CreateQueue(&q);

    int command;
    while(command != 0) {
        scanf("%d", &command);
        if (command == 1) {
            int val;
            scanf("%d", &val);
            if (isFull(q)) {
                printf("Queue penuh\n");
            } else {
                enqueue(&q, val);
            }
        } else if (command == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            } else {
                int temp;
                dequeue(&q, &temp);
                enqueue(&layan, temp);
            }
        }
    }
    if (command == 0) {
        printf("%d\n", length(layan));
        if (isEmpty(layan)) {
            printf("Tidak bisa dihitung\n");
        } else {
            printf("%.2f", average(layan));
        }
    }
}