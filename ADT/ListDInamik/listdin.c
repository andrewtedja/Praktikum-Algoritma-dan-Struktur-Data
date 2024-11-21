#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
{
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l)
{
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l)
{
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
{
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i)
{
    return (i >= IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i)
{
    return (i >= IDX_MIN && i < NEFF(l));
}

boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l)
{
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l)
{
    int n;
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY(*l));

    NEFF(*l) = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListDin l)
{
    printf("[");
    for (int i = 0; i < NEFF(l); i++) {
        printf("%d", ELMT(l, i));
        if (i < NEFF(l) - 1) printf(",");
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin result;
    CreateListDin(&result, CAPACITY(l1));
    NEFF(result) = NEFF(l1);

    for (int i = 0; i < NEFF(l1); i++) {
        if (plus) {
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return result;
}

boolean isListEqual(ListDin l1, ListDin l2)
{
    if (NEFF(l1) != NEFF(l2)) return false;

    for (int i = 0; i < NEFF(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) return false;
    }

    return true;
}

IdxType indexOf(ListDin l, ElType val)
{
    for (int i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) return i;
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min)
{
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (int i = 1; i < NEFF(l); i++) {
        if (ELMT(l, i) > *max) *max = ELMT(l, i);
        if (ELMT(l, i) < *min) *min = ELMT(l, i);
    }
}

void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    for (int i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l)
{
    ElType sum = 0;
    for (int i = 0; i < NEFF(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val)
{
    int count = 0;
    for (int i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) count++;
    }
    return count;
}

void sort(ListDin *l, boolean asc)
{
    for (int i = 0; i < NEFF(*l) - 1; i++) {
        for (int j = 0; j < NEFF(*l) - i - 1; j++) {
            if ((asc && ELMT(*l, j) > ELMT(*l, j + 1)) || 
                (!asc && ELMT(*l, j) < ELMT(*l, j + 1))) {
                ElType temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j + 1);
                ELMT(*l, j + 1) = temp;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l)--;
}

void expandList(ListDin *l, int num)
{
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num)
{
    CAPACITY(*l) -= num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l)
{
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}