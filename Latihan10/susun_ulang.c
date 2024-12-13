#include "listrec.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{
    List result = newNode(0);
    List input = newNode(0);
    boolean remove_first = true;
    boolean first = true;

    int n;
    int bin;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bin);
        input = konsb(input, bin);
    }

    input = tail(input);

    while (!isEmpty(input))
    {
        if (first)
        {
            result = konsb(result, head(input));
            input = tail(input);
            first = false;
        }
        else
        {
            first = true;
            input = reverseList(input);
            result = konsb(result, head(input));
            input = tail(input);
            input = reverseList(input);
        }
        if (remove_first)
        {
            result = tail(result);
            remove_first = false;
        }
    }

    displayList(result);
    return 0;
}
