#include "list_circular.h"
#include <stdio.h>

int main(){
    boolean clockwise = true;
    boolean c_clockwise = false;
    int n ;
    scanf("%d", &n);

    List l1;
    CreateList(&l1);
    List l2;
    CreateList(&l2);

    int input;
    for ( int i = 0 ; i < n ; i++){
        scanf("%d" , &input);
        insertLast(&l1, input);
        insertLast(&l2, input);
    }

    int min = INFO(FIRST(l1)) ;
    Address p = FIRST(l1);
    while (NEXT(p) != FIRST(l1)){
        if(INFO(p) < min){
            min = INFO(p);
        }
        p = NEXT(p);
    }

    int bin;
    deleteLast(&l1, &bin);
    insertLast(&l1, bin);

    if(bin < min){
        min = bin;
    }

    while(INFO(FIRST(l1)) != min){
        deleteLast(&l1, &bin);
        insertFirst(&l1, bin);
    }

    p = FIRST(l1);
    while (NEXT(p) != FIRST(l1)){
        if (INFO(NEXT(p)) < INFO(p)){
            clockwise = false;
        }
        p = NEXT(p);
    }

    if(!clockwise){
        c_clockwise = true;
        int max = INFO(FIRST(l2)) ;
        p = FIRST(l2);
        while (NEXT(p) != FIRST(l2)){
            if(INFO(p) > max){
                max = INFO(p);
            }
            p = NEXT(p);
        }

        deleteLast(&l2, &bin);
        insertLast(&l2, bin);

        if(bin > max){
            max = bin;
        }

        while(INFO(FIRST(l2)) != max){
            deleteLast(&l2, &bin);
            insertFirst(&l2, bin); 
        }

        p = FIRST(l2);
        while (NEXT(p) != FIRST(l2)){
            if (INFO(NEXT(p)) > INFO(p)){
                c_clockwise = false;
                break;
            }
            p = NEXT(p);
        }

    }
    if (c_clockwise || clockwise) {
        printf("YES");
    } else {
        printf("NO");
    }
    printf("\n");

    return 0;
}
