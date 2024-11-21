#include <stdio.h>
#include "stack.h" // Assume you have an ADT stack implementation in stack.h

// Non-recursive Fibonacci using stack
int fibonacci(int n) {
    Stack stack;
    CreateEmpty(&stack);  // Initialize stack

    Push(&stack, n);      // Start with fibonacci(n)

    int result = 0;
    int top;
    int f1, f2;

    while (!IsEmpty(stack)) {
        Pop(&stack, &top);

        // If top is 0 or 1, we know the Fibonacci value directly
        if (top == 0) {
            Push(&stack, 0);
        } else if (top == 1) {
            Push(&stack, 1);
        } else {
            // Simulate recursive calls for fibonacci(top) = fibonacci(top-1) + fibonacci(top-2)
            // Push current state back and subproblems
            Push(&stack, top);       // Push current state to revisit later
            Push(&stack, top - 1);   // Push fibonacci(top-1)
            Push(&stack, top - 2);   // Push fibonacci(top-2)
        }

        // Check if the top of the stack has two values to combine
        if (!IsEmpty(stack)) {
            int value1, value2;

            // Pop two values if possible to combine
            Pop(&stack, &value1);
            if (!IsEmpty(stack)) {
                Pop(&stack, &value2);
                result = value1 + value2; // Calculate result for current level
                Push(&stack, result); // Push result back
            } else {
                Push(&stack, value1); // If there's only one, push it back
            }
        }
    }

    // The final result should be on top of the stack
    Pop(&stack, &result);
    return result;
}

int main() {
    int n = 5; // Change n to any desired Fibonacci number
    int result = fibonacci(n);
    printf("fibonacci(%d) = %d\n", n, result);
    return 0;
}
