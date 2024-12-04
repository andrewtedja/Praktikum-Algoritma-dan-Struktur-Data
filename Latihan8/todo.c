#include <stdio.h>
#include "listlinier.h"

int main(){
    char temp;
    int val;
    List l;
    CreateList(&l);
    do {
        scanf("%c",&temp);
        if (temp == 'P'){
            scanf("%d",&val);
            insertFirst(&l,val);
        } else if (temp == 'I'){
            scanf("%d",&val);
            insertLast(&l,val);

        } else if (temp == 'C'){
            if (!isEmpty(l)){
                
                deleteFirst(&l,&val);
            }
        } else if (temp == 'D'){
            scanf("%d",&val);
            int idx = indexOf(l,val);
            if (idx !=-1){
                deleteAt(&l,idx,&val);
            }
        }
    } while (temp != 'X');
    displayList(l);
    // printf("\n");
}