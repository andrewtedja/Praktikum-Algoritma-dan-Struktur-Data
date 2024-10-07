#include <stdio.h>
#include <stdbool.h>


int main(){
    //input jumlah array
    int n ;
    scanf("%d", &n);

    //new array
    int arr[n];

    //isi array dengan n jumlah
    for (int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int array_count[n];
    int new_array[n];
    int count;
    int mark = -99999;
    bool ada = false;

    //inisialisasi
    for ( int i = 0 ; i < n ; i++){
        new_array[i] = mark;
        array_count[i] = mark;
    }


    //loop pengcekan di main array
    for (int i = 0 ; i < n ; i++){
        count = 0;
        ada = false;
        //check di new array loop
        for (int j = 0 ; j < n ; j++){
            if ( arr[i] == new_array[j]){
                ada = true;
            }
        }

        if ( ada == false){
            //loop count
            for (int x = 0 ; x < n ; x++){
                count += (arr[i]==arr[x]) ? 1 : 0;
            }
            array_count[i] = count; 
            new_array[i] = arr[i];           
    }
    }

    //output form new_array
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

    //output per element
    for (int i = 0 ; i < n; i++){
        if (new_array[i] != mark && array_count[i] != mark){
            printf("\n%d %d", new_array[i], array_count[i]);
        }
    }
    printf("\n");
    return 0;

}

// [2,3,4,2,5]
// [2,3,4]
