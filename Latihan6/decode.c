#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h" 

#define MAX_LEN 10001
#define MAX_STACK_SIZE 100

int main() {
    int N;
    scanf("%d", &N);

    char s[N + 1];
    scanf("%s", s);

    Stack countStack;
    CreateEmpty(&countStack);

    char stringStack[MAX_STACK_SIZE][MAX_LEN];
    int stringStackTop = -1;

    char currStr[MAX_LEN] = "";
    int i = 0;
    int len = strlen(s);

    while (i < len) {
        if (isdigit(s[i])) {
            int count = 0;
            while (i < len && isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            if (s[i] == '[') {
                Push(&countStack, count);
                stringStackTop++;
                strcpy(stringStack[stringStackTop], currStr);
                currStr[0] = '\0';
                i++; 
            }
        } else if (s[i] == ']') {
            int count;
            Pop(&countStack, &count);
            char prevStr[MAX_LEN];
            strcpy(prevStr, stringStack[stringStackTop]);
            stringStackTop--;
            char temp[MAX_LEN] = "";
            for (int j = 0; j < count; j++) {
                strcat(temp, currStr);
            }
            strcat(prevStr, temp);
            strcpy(currStr, prevStr);
            i++;
        } else {
            int lenCurr = strlen(currStr);
            currStr[lenCurr] = s[i];
            currStr[lenCurr + 1] = '\0';
            i++;
        }
    }

    printf("%s\n", currStr);

    return 0;
}
