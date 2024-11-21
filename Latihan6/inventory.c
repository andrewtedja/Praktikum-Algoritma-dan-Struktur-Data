#include "stack.h"
#include <stdio.h>

int main() {
    int n, temp, temp2, sum = 0, total = 0;
    char cc;
    Stack s, tempS;
    CreateEmpty(&s);
    CreateEmpty(&tempS);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cc);
        if ((n == 1 && cc == 'A') || (n == 1 && cc == 'S')) {
            printf("%d\n", 0);
            return 0;
        }
        else if (cc == 'X') {
            Pop(&s, &temp);
        }
        else if (cc == '+') {
            Pop(&s, &temp);
            Pop(&s, &temp2);
            Push(&s, temp2);
            Push(&s, temp);
            Push(&s, (temp + temp2));
        }
        else if (cc == 'S') 
        {
            sum = 0;
            while (!IsEmpty(s)) {
                Pop(&s, &temp);
                sum += temp;   
            }
            Push(&s, sum);
        }
        else if (cc == 'A') {
            total = 0;
            sum = 0;
            while (!IsEmpty(s)) {
                Pop(&s, &temp);
                sum = sum + temp;
                total += 1;
            }
            sum = sum/total;
            Push(&s, sum);
        }
        else {
            cc = cc - '0';
            Push(&s, cc);
        }
    }
    sum = 0;
    while (!IsEmpty(s)) {
        Pop(&s, &temp);
        sum += temp;
    }
    printf("%d\n", sum);
    return 0;
}