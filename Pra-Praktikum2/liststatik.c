#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    int length = 0;
    while (length < CAPACITY && ELMT(l, length) != MARK) {
        length++;
    }

    return length;
}

IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    return listLength(l) - 1;
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < listLength(l));
}

boolean isEmpty(ListStatik l) {
    return (ELMT(l, IDX_MIN) == MARK);
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l) {
    int n, i;
    ElType val;
    CreateListStatik(l);
    
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        ELMT(*l, i) = val;
    }
}

void printList(ListStatik l) {
    int i;
    printf("[");
    for (i = 0; i < listLength(l); i++) {
        printf("%d", ELMT(l, i));
        if (i < listLength(l) - 1) {
            printf(",");
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l;
    int i;
    CreateListStatik(&l);
    for (i = 0; i < listLength(l1); i++) {
        if (plus) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    int i;
    for (i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    return true;
}

int indexOf(ListStatik l, ElType val) {
    int i;
    for (i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    int i;
    for (i = 1; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val) {
    int i;
    for (i = listLength(*l); i > 0; i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    int i;
    for (i = listLength(*l); i > idx; i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val) {
    *val = ELMT(*l, 0);
    int i;
    for (i = 0; i < listLength(*l) - 1; i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    *val = ELMT(*l, idx);
    int i;
    for (i = idx; i < listLength(*l) - 1; i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
    *val = ELMT(*l, listLength(*l) - 1);
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
    int i, j;
    ElType temp;
    for (i = 0; i < listLength(*l) - 1; i++) {
        for (j = 0; j < listLength(*l) - i - 1; j++) {
            if ((asc && ELMT(*l, j) > ELMT(*l, j+1)) || (!asc && ELMT(*l, j) < ELMT(*l, j+1))) {
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j+1);
                ELMT(*l, j+1) = temp;
            }
        }
    }
}