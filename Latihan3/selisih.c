#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include <math.h>

int main() {
    ListDin(l1);
    CreateListDin(&l1, 100);
    readList(&l1);

    if (listLength(l1) <= 1) {
        printf("%d\n", 0);
    } 
    else {
        int max, min, selisih;
        extremeValues(l1, &max, &min);
        selisih = fabs(max - min) + 1;
        printf("%d\n", selisih);
}
}