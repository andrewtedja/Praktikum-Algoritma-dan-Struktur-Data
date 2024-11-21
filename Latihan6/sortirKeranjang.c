#include <stdio.h>
#include "stack.h"

int SortirKeranjang(Stack *S1, Stack *S2) {
    Stack temp;
    CreateEmpty(&temp);

    infotype X, Y;
    while (!IsEmpty(*S1)) {
        Pop(S1, &X);
        if (IsEmpty(temp) || X >= InfoTop(temp)) {
            Push(&temp, X);
        }
        else {
            while (!IsEmpty(temp) && X < InfoTop(temp)) {
                Pop(&temp, &Y);  // pop into Y to keep X unchanged
                Push(S1, Y);
            }
            Push(&temp, X); 
        }
    }

    while (!IsEmpty(temp)) {
        Pop(&temp, &X);
        Push(S2, X);
    }

    return 0;  
}

int main() {
    Stack S1, S2;
    CreateEmpty(&S1);
    CreateEmpty(&S2);

    // Add elements to S1 for testing
    Push(&S1, 3);
    Push(&S1, 1);
    Push(&S1, 4);
    Push(&S1, 2);

    SortirKeranjang(&S1, &S2);

    infotype X;
    while (!IsEmpty(S2)) {
        Pop(&S2, &X);
        printf("%d\n", X);
    }

    return 0;
}