#include <stdio.h>
#include "boolean.h"
#include "stack.h"

boolean number (char x){
    return x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9' || x == '0'; 
}

boolean isOperator (char x){
    return x == 'S' || x == 'A' || x == 'X' || x == '+';
}

int main()
{
    int N, i, result=0;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);

        if (number(ch)){
            Push(&s, ch - '0');
        }
        else if (isOperator(ch)){
            if (N == 1 && ch == 'S' || N == 1 && ch == 'A'){
                printf("0\n");
                return 0;
            }
            else if (ch == 'S'){
                int sum = 0;
                while (!IsEmpty(s)){
                    infotype temp;
                    Pop(&s, &temp);
                    sum += temp;
                }
                Push(&s, sum);
            }
            else if (ch == 'A'){
                int avr;
                int sum = 0;
                int count = 0;
                while (!IsEmpty(s)){
                    infotype temp;
                    Pop(&s, &temp);
                    sum += temp;
                    count++;
                }
                avr = sum/count;
                Push(&s, avr);
            }
            else if (ch == 'X'){
                infotype temp;
                Pop(&s, &temp);
            }
            else if (ch == '+'){
                int a, b;
                Pop(&s, &b);
                Pop(&s, &a);
                Push(&s, a);
                Push(&s, b);
                Push(&s, a + b);
            }
        }
    }
    while(!IsEmpty(s)){
        int temp;
        Pop(&s, &temp);
        result += temp;
    }
    printf("%d\n", result);
    return 0;
}