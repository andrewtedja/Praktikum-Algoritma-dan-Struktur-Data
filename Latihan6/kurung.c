#include <stdio.h>
#include "stack.h"

int main(){ 
    Stack kurung;
    infotype val;
    int n;
    char ch;
    boolean valid = true;
    scanf("%d", &n);
    CreateEmpty(&kurung);
    
    for ( int i = 0; i < n; i++){
        scanf(" %c", &ch);

        if ( ch != '(' && ch != '[' && ch!= '{' && ch!= '}' && ch != ')' && ch != ']'){
            valid = false;
            break;
        }

        if ( ch == '{' || ch == '(' || ch == '['){
            Push(&kurung,ch);
        }
        else if( IsEmpty(kurung) || (ch == ']' && InfoTop(kurung) != '[') || (ch == '}' && InfoTop(kurung) != '{') || (ch == ')' && InfoTop(kurung) != '(')){
            valid= false;
            break;
        }
        else{
            Pop(&kurung, &val);
        }
    }

    if (valid && IsEmpty(kurung)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}

