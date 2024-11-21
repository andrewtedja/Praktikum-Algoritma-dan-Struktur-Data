#include <stdio.h>
#include "queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    int temp_input, bin;
    int val;

    int n ; 
    scanf("%d", &n);

    for ( int i = 0 ; i < n ; i++){
        scanf("%d", &temp_input);
        if (temp_input == 1){
            scanf("%d", &val);
            if( isFull(q)){
                printf("Queue Penuh\n");
            }
            else{
                enqueue(&q, val);
                printf("Enqueue %d Berhasil\n", val);
            }
        }
        else if ( temp_input == 2){
            if ( isEmpty(q)){
                printf("Queue Kosong\n");
            }
            else{
                dequeue(&q, &bin);
                printf("Dequeue %d Berhasil\n", bin);
            }
        }
        else if ( temp_input == 3){
            if ( isEmpty(q)){
                printf("Queue Kosong\n");
            }
            else{
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        }
        else if ( temp_input == 4){
            printf("Ukuran Queue saat ini adalah %d\n" ,length(q));
        }
    }
    displayQueue(q);
}