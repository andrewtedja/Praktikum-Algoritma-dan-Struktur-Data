#include "listrec.h"

void mergeSortedUnique(List l1, List l2, List *res) {
    if (isEmpty(l1) && isEmpty(l2)) {
        return;
    }
    
    if (isEmpty(l1)) {
        *res = konsb(*res, INFO(l2));
        mergeSortedUnique(l1, tail(l2), res);
        return;
    }
    
    if (isEmpty(l2)) {
        *res = konsb(*res, INFO(l1));
        mergeSortedUnique(tail(l1), l2, res);
        return;
    }

    if (INFO(l1) < INFO(l2)) {
        if (!isMember(*res, INFO(l1))) {
            *res = konsb(*res, INFO(l1));
        }
        mergeSortedUnique(tail(l1), l2, res);
        return;
    } 
    else if (INFO(l2) < INFO(l1)) {
        if (!isMember(*res, INFO(l2))) {
            *res = konsb(*res, INFO(l2));
        }
        mergeSortedUnique(l1, tail(l2), res);
        return;
    } 
    else {
        *res = konsb(*res, INFO(l1));
        mergeSortedUnique(tail(l1), tail(l2), res);
        return;
    }
}
