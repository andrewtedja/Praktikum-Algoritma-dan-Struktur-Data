#include <stdio.h>
#include "listlinier.h"

int main() {
    List cache;
    CreateList(&cache);

    int N;
    scanf("%d", &N);
    float counthit = 0;

    int ops;
    scanf("%d", &ops);
    for (int i = 0; i < ops; i++) {
        ElType mem;
        scanf("%d", &mem);
        if (N == 0) { // ukuran maks 0
            printf("miss ");
            displayList(cache);
            printf("\n");
        } else { // ukuran maks bukan 0
            if (isEmpty(cache)) { // cache empty
                insertFirst(&cache, mem);
                printf("miss ");
                displayList(cache);
                printf("\n");
            } else { // cache not empty
                if (indexOf(cache, mem) != IDX_UNDEF) {
                    // mem ada pada list
                    int temp;
                    deleteAt(&cache, indexOf(cache, mem), &temp); // delete elemen yang sama, simpen di temp
                    insertFirst(&cache, temp); // masukin temp kembali di depan
                    printf("hit ");
                    displayList(cache);
                    printf("\n");
                    counthit++;
                } else { 
                    // mem gada pada list
                    if (N == length(cache)) { // cache sudah penuh
                        int val;
                        insertFirst(&cache, mem);
                        deleteLast(&cache, &val);
                        printf("miss ");
                        displayList(cache);
                        printf("\n");
                    } else { // cache belum penuh
                        insertFirst(&cache, mem);
                        printf("miss ");
                        displayList(cache);
                        printf("\n");
                    }
                }
        }
    }
    float ratio;
    if (ops == 0) {
        ratio = 0;
        printf("Hit ratio: %.2f", ratio);
    } else {
        ratio = counthit / ops;
        printf("Hit ratio: %.2f", ratio);
    }
}
}