#include <stdio.h>
#include <stdbool.h>


int main(){
    int n ;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int array_count[n];
    int new_array[n];
    int count;
    int mark = -99999;
    bool ada = false;

    for ( int i = 0 ; i < n ; i++){
        new_array[i] = mark;
        array_count[i] = mark;
    }


    for (int i = 0 ; i < n ; i++){
        count = 0;
        ada = false;
        for (int j = 0 ; j < n ; j++){
            if ( arr[i] == new_array[j]){
                ada = true;
            }
        }

        if ( ada == false){
            for (int x = 0 ; x < n ; x++){
                count += (arr[i]==arr[x]) ? 1 : 0;
            }
            array_count[i] = count; 
            new_array[i] = arr[i];           
    }
    }

    printf("[");
    for (int i = 0 ; i < n; i++){
        if (new_array[i] != mark){
            if (i > 0){
                printf(",");
            }
            printf("%d", new_array[i]);
        }
    }
    printf("]");

    for (int i = 0 ; i < n; i++){
        if (new_array[i] != mark && array_count[i] != mark){
            printf("\n%d %d", new_array[i], array_count[i]);
        }
    }
    printf("\n");
    return 0;

}

