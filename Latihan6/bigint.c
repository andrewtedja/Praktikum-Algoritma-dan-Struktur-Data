#include <stdio.h>
#include <math.h>
#include <string.h>
#include "math.h"

int charToNum(char c) 
{
    return (c - '0');
}

char numToChar(int n) 
{
    return (n + '0');
}

int main () {
    char s = numToChar(4);
    printf("%d", s);
}