#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>


BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    Address p = newTreeNode(root);
    if (p != NULL) {
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
    Address p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p) {
    free(p);
}

boolean isTreeEmpty (BinTree p) {
    return p == NULL;
}

boolean isOneElmt (BinTree p) {
    if (p == NULL) return false;
    return LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft (BinTree p) {
    if (p == NULL) return false;
    return (LEFT(p) != NULL) && (RIGHT(p) == NULL);
}

boolean isUnerRight (BinTree p) {
    if (p == NULL) return false;
    return (RIGHT(p) != NULL) && (LEFT(p) == NULL);
}

boolean isBinary (BinTree p) {
    if (p == NULL) return false;
    return (LEFT(p) != NULL) && (RIGHT(p) != NULL);
}

void printPreorder(BinTree p) {
    if (p == NULL) {
        printf("()");
        return;
    }
    printf("(%d", ROOT(p));
    printPreorder(LEFT(p));
    printPreorder(RIGHT(p));
    printf(")");
}

void printInorder(BinTree p) {
    if (p == NULL) {
        printf("()");
        return;
    }
    printf("(");
    printInorder(LEFT(p));
    printf("%d", ROOT(p));
    printInorder(RIGHT(p));
    printf(")");
}

void printPostorder(BinTree p) {
    if (p == NULL) {
        printf("()");
        return;
    }
    printf("(");
    printPostorder(LEFT(p));
    printPostorder(RIGHT(p));
    printf("%d)", ROOT(p));
}

void printTreeHelper(BinTree p, int h, int current) {
    if (p == NULL) return;
    for(int i = 0; i < current * h; i++) printf(" ");
    printf("%d\n", ROOT(p));
    printTreeHelper(LEFT(p), h, current + 1);
    printTreeHelper(RIGHT(p), h, current + 1);
}

void printTree(BinTree p, int h) {
    printTreeHelper(p, h, 0);
}

boolean isEqual(BinTree p1, BinTree p2) {
    if (p1 == NULL && p2 == NULL) return true;
    if (p1 == NULL || p2 == NULL) return false;
    if (ROOT(p1) != ROOT(p2)) return false;
    return isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2));
}

int getMaximumDepth(BinTree p) {
    if (p == NULL) return 0;
    int leftDepth = getMaximumDepth(LEFT(p));
    int rightDepth = getMaximumDepth(RIGHT(p));
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end) {
    if (start > end) return NULL;
    ElType mid = start + (end - start) / 2;
    BinTree root = newTreeNode(arr[mid]);
    LEFT(root) = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
    RIGHT(root) = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
    return root;
}

int countNodes(BinTree p) {
    if (p == NULL) return 0;
    return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
}

int findPath(BinTree p, ElType target, ElType* path, int* length) {
    if (p == NULL) return 0;
    path[*length] = ROOT(p);
    (*length)++;
    if (ROOT(p) == target) return 1;
    if (findPath(LEFT(p), target, path, length) || findPath(RIGHT(p), target, path, length))
        return 1;
    (*length)--;
    return 0;
}

void printPathToElement(BinTree p, ElType target) {
    ElType path[100];
    int length = 0;
    if (!findPath(p, target, path, &length)) {
        printf("-1\n");
        return;
    }
    for(int i = 0; i < length; i++) {
        if (i > 0) printf(" -> ");
        printf("%d", path[i]);
    }
    printf("\n");
}
