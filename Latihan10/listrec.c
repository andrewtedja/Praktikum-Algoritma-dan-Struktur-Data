#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listrec.h"

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(List l) {
    return (l == NIL);
}

boolean isOneElmt(List l) {
    return (length(l) == 1);   
}

ElType head(List l) {
    return (INFO(l));
}

List tail(List l) {
    return (NEXT(l));
}

List konso(List l , ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        NEXT(p) = l;
        return p;
    } else {
       return l;
    }
}

List konsb(List l , ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        if (isEmpty(l)) {
            return p;
        } else {
            NEXT(l) = konsb(tail(l) , e);
            return l;
        }
    } else {
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)) , head(l));
    }
} 

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else if (isEmpty(l2)) {
        return copy(l1);
    } else {
        return konso(concat(tail(l1) , l2) , head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l , ElType x) {
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l) , x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n" , head(l));
        displayList(tail(l));
    }
}

List insertAt(List l , ElType e , int idx) {
    if (idx == 0) {
        return konso(l , e);
    } else {
        return konso(insertAt(NEXT(l) , e , idx - 1) , INFO(l));
    }
}

List deleteFirst(List l) {
    Address p = l;
    l = NEXT(l);
    free(p);
    return l;
}

List deleteAt(List l , int idx) {
    if (idx == 0) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(NEXT(l) ,idx - 1) , INFO(l));
    }
}

List deleteLast(List l) {
    return deleteAt(l , length(l) - 1);
}

List reverseList (List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return l;
    } else {
        return konsb(reverseList(tail(l)) , head(l));
    }
}

void splitOddEven (List l , List *l1 , List *l2) {
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else {
        if (head(l) % 2 == 0) {
            splitOddEven(tail(l) , &*l1 , &*l2);
            *l1 = konso(*l1 , head(l));
        } else {
            splitOddEven(tail(l) , &*l1 , &*l2);
            *l2 = konso(*l2 , head(l));
        }
    }
}

void splitOnX (List l , ElType x , List *l1 , List *l2) {
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (x > 0) {
            splitOnX(tail(l) , x - 1 , &*l1 , &*l2);
            *l1 = konso(*l1 , head(l));
        } else {
            splitOnX(tail(l) , x , &*l1 , &*l2);
            *l2 = konso(*l2 , head(l));
        }
    }
}

ElType getMiddle(List l) {
    int size = length(l);
    int i = 0;
    Address p = l;
    int pos = size / 2;
    while (i < pos) {
        p = tail(p);
        i++;
    }
    return head(p);
}