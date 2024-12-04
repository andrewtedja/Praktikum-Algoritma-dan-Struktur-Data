#include "list_circular.h"
#include <stdio.h>

int main(){
    int N; 
    int input;
    scanf("%d", &N);
    List l;
    CreateList(&l);

    for (int i = 0; i < N; i++){
        scanf("%d", &input);
        insertLast(&l, input);
    }

    int max = 0;
    Address p_max = FIRST(l);
    while (NEXT(p_max) != FIRST(l)){
        if (INFO(p_max) > max) {
            max = INFO(p_max);
        }
        p_max = NEXT(p_max);
    }

    int bin;
    deleteLast(&l, &bin);
    insertLast(&l, bin);

    if (max < bin) {
        max = bin;
    }

    while (INFO(FIRST(l)) != max){
        deleteLast(&l, &bin);
        insertFirst(&l, bin);
    }
    
    displayList(l);
    return 0;
}
