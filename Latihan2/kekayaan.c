#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int n ;
    scanf("%d", &n);
    bool all_nine = true;
    int arr[n];

    for (int i = 0 ; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //check all 9
    for ( int i = 0 ; i < n ; i++) {
        if ( arr[i] != 9) {
            all_nine = false;
        }
    }

    //size new array
    int new_arr[(all_nine) ? n+1 : n];

    //if all 9 di elemen
    if (all_nine) {
        for (int i = 0 ; i < n+1; i++) {
            if ( i == 0) {
                new_arr[i] = 1;
            } else {
                new_arr[i] = 0;
            }
        }
    } else { 
        for (int i = n-1  ; i >= 0 ;i--) {
            if (arr[i] == 9) {
                arr[i] = 0;
            } else {
                arr[i]++;
                break;
            }
        }
            }

    if(!all_nine){
        for (int i = 0 ; i < n ; i++) {
            new_arr[i] = arr[i];
        }

        }

    for ( int i = 0 ; i < sizeof(new_arr)/sizeof(int); i++) {
        if ( i == 0 ) {
            printf("%d", new_arr[i]);
        } else {
            printf(" %d", new_arr[i]);
        }
    }

    printf("\n");
    return 0;
}