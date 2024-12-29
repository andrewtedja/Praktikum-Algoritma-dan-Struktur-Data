#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    if ( *p == NULL){
        return ;
    }
    BinTree temp;
    temp = RIGHT(*p);
    RIGHT(*p) = LEFT(*p);
    LEFT(*p) = temp;
    invertTree(&RIGHT(*p));
    invertTree(&LEFT(*p));
}