#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(List l) {
    return l == NULL;
}

boolean isOneElmt(List l) {
    return (!isEmpty(l) && NEXT(l) == NULL);
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address P = newNode(e);
    if (P != NULL) {
        NEXT(P) = l;
        return P;
    } else {
        return l;
    }
}

List konsb(List l, ElType e) {
    Address P = newNode(e);
    if (P != NULL) {
        if (isEmpty(l)) {
            return P;
        } else {
            Address last = l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = P;
        }
    }
    return l;
}

List copy(List l) {
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}


int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx) {
    if (idx == 0) {
        return konso(l, e);
    return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l){
    return konso(tail(tail(l)), head(tail(l)));
    // or return tail(l);
}

List deleteAt(List l, int idx) {
    if (idx == 0) {
        return deleteFirst(l);
    }
    if (idx == length(l) - 1) {
        return deleteLast(l);
    }
    return konso(deleteAt(tail(l), idx-1), head(l));
}

List deleteLast(List l) {
    if (isOneElmt(l) || isEmpty(l)) {
        return NULL;
    }
    return konso(deleteLast(tail(l)), head(l));
}

List inverseList (List l){
    if (isOneElmt(l) || isEmpty(l)){
        return l;
    }

    return konsb(inverseList(tail(l)), head(l));
}

void splitPosNeg (List l, List *l1, List *l2){
    if (!isEmpty(l)){
        if (head(l) >= 0){
            *l1 = konsb(*l1, head(l));
        }
        else{
            *l2 = konsb(*l2, head(l));
        }
        splitPosNeg(tail(l), l1, l2);
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2){
    if (!isEmpty(l)){
        if (head(l) < x){
            *l1 = konsb(*l1, head(l));
        }
        else{
            *l2 = konsb(*l2, head(l));
        }
        splitOnX(tail(l), x, l1, l2);
    }
}

List removeDuplicate(List l, List unique){
    if (!isEmpty(l)){
        if (isEmpty(unique)){
            unique = konso(unique, head(l));
        }
        else{
            if (!isMember(unique, head(l))){
                unique = konso(unique, head(l));
            }
        }
        unique = removeDuplicate(tail(l), unique);
    }
    else{
        return unique;
    }
}