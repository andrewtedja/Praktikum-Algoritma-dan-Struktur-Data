#include <stdio.h>
#include <stdbool.h>

#define mark -9999

int max_elemen(int arr[], int n) {
    int max = mark;
    for (int i = 0 ; i < n ; i++ ) {
        if ( max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n ;
    bool ada_second = false;
    scanf("%d", &n);
    if (n == 0) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
        return 0;
    }

    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        scanf("%d" ,&arr[i]);
    }

    int arr_of_index[max_elemen(arr, n)+1];

    for (int i = 0 ; i < sizeof(arr_of_index) / sizeof(int); i++) {
        arr_of_index[i] = 0;
    }

    for (int i = 0 ; i < n ; i++) {
        arr_of_index[arr[i]] += 1;
    }

    int max = max_elemen(arr_of_index,sizeof(arr_of_index)/sizeof(int));

    for (int i = 0 ; i < sizeof(arr_of_index) / sizeof(int); i++) {
        if ( arr_of_index[i] == max){
            arr_of_index[i] = mark;
        }
    }

    int sec_max = max_elemen(arr_of_index,sizeof(arr_of_index)/sizeof(int));
    

    if(sec_max != mark && sec_max != 0){
        for (int i = 0 ; i < sizeof(arr_of_index) / sizeof(int); i++){
            if ( arr_of_index[i] == sec_max){
                sec_max = i;
                ada_second = true;
                break;
            }
        } 
    }
        
    //output
    if(ada_second){
        printf("%d", sec_max);
    }else{
        printf("Tidak ada elemen kedua yang paling sering muncul");
    }

    printf("\n");

    return 0;
}