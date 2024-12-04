#include <stdio.h>
#include "listlinier.h"

int main(){
    int temp;
    List l;
    CreateList(&l);
    do
    { 
        scanf("%d",&temp);
        if (temp == -9999){
            break;
        }
        if (isEmpty(l)){
            insertFirst(&l,temp);
        } else if (length(l) == 1){
            Address p = FIRST(l);
            if (INFO(p) < temp){
                insertLast(&l,temp);
            } else {
                insertFirst(&l,temp); 
            }
        } else {
            Address p = FIRST(l);
            int i = 0;
            while (p != NULL && temp > INFO(p)){
                p = NEXT(p);
                i++;
            }
            insertAt(&l,temp,i);
        }
    } while (temp != -9999);
    displayList(l);
}