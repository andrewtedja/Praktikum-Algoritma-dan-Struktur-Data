#include <stdio.h>
#include "list_circular.h"

int main() {
    int N;  
    List l;
    CreateList(&l);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        insertLast(&l, temp);
    }

    //Find a and b ( a = difference, b = first element)
    Address p;
    p = FIRST(l);
    int x = INFO(p);
    p = NEXT(p);
    int y = INFO(p);

    // -1 5 11 17 -> 6i - 7 = 6(i-1) - 1
    int a; // a = difference
    a = y - x;
    int b = x;

    // Cek aritmetika
    boolean aritmatika = true;
    int j = 1;
    while (!isEmpty(l) && j<= N) {
        int val;
        int elmt = a*(j-1) + b;
        deleteFirst(&l, &val);
        if (val != elmt) {
            aritmatika = false;
        }
        j++;
    }

    if (aritmatika) {
        printf("%d %d\n", a, b);
    } else {
        printf("%d %d\n", 0, 0);
    }
} 