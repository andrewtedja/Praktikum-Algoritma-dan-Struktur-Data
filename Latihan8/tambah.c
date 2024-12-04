#include <stdio.h>
#include "listlinier.h"

int main(){
    int temp;
    List l1;
    CreateList(&l1);
    int length1 = 0;
    do
    { 
        scanf("%d",&temp);
        insertLast(&l1,temp);
        length1++;
        
    } while (temp != -1);
    deleteLast(&l1,&temp);
    length1--;

    List l2;
    CreateList(&l2);
    int length2 = 0;
    do
    { 
        scanf("%d",&temp);
        insertLast(&l2,temp);
        length2++;
    } while (temp != -1);
    length2--;
    deleteLast(&l2,&temp);

    List l3;
    CreateList(&l3);
    int max = length1;
    if (length2 > max){
        max = length2;
    }
    if (max == length1){

        for (int i = 0; i < max-length2; i++){
            insertFirst(&l2,0);
        }
    } else {
        for (int i = 0; i < max-length1; i++){
            insertFirst(&l1,0);
        }
    }

    temp = 0;
    for (int i = 0; i < max; i++){
        int val1,val2;
        deleteLast(&l1,&val1);
        deleteLast(&l2,&val2);
        int val3 = (val1 + val2 + temp)%10;
        temp = (val1 + val2 + temp)/10;
        
        insertFirst(&l3,val3);
    }
    if (temp != 0){
        insertFirst(&l3,temp);
    }
    while (!isEmpty(l3)){
        deleteFirst(&l3,&temp);
        if (isEmpty(l3)){
            printf("%d",temp);
        } else {
            printf("%d ",temp);
        }
        
    }
    printf("\n");
}
