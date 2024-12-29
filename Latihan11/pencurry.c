#include "bintree.h"
#include <stdlib.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

void itung(BinTree node, int* count, int* no_count){
    if (node == NULL){
        *count = 0;
        *no_count = 0;
        return;
    }
    int left_count, left_no_count, right_count, right_no_count;
    itung(LEFT(node), &left_count, &left_no_count);
    itung(RIGHT(node), &right_count, &right_no_count);
    *count = ROOT(node) + left_no_count + right_no_count;
    *no_count = max(left_count, left_no_count) + max(right_count, right_no_count);
}

int mencurry(BinTree root){
    int count, no_count;
    itung(root, &count, &no_count);
    return max(count, no_count);
}