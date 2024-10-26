//papan nxn 
// baris r & kolom c
//papan[r][c] = 0 -> tidak ada benteng
//papan[r][c] > 0 -> terdapat benteng {kekuatan papan[r][c]}

//menyerang pada baris dan kolom yang sama

//nilai kekacauan :: total kekuatan benteng yang dapat menyerangnya
//hitung nilai kekacauan tersebut 

#include <stdio.h>
#include "matrix.h"
#include <math.h>

int main(){
    //input n
    int n ;
    scanf("%d", &n);

    //create matrix
    Matrix papan;
    Matrix* ptr_papan = &papan;
    createMatrix(n, n, ptr_papan);


    //input elemen
    readMatrix(ptr_papan, n , n);

    //proses cek 1 1 ya dek ya
    long count = 0;

    //loop master matrix
    for( int i = 0 ; i < n ; i++){
        for (int j =0 ; j < n ; j++){

            //cek kalau misal dia ada benteng
            if ( ELMT(*ptr_papan, i,j) > 0){

                //cek full kiri kanan
                for ( int x = 0; x < n ; x++){
                    if( x!= i){
                        count += (ELMT(*ptr_papan,x,j) > 0) ? ELMT(*ptr_papan,x, j) : 0;
                    }
                }

                //cek full atas bawah
                for ( int y = 0 ; y < n ; y++){
                    if (y!= j){
                        count +=(ELMT(*ptr_papan,i,y) > 0) ? ELMT(*ptr_papan, i, y) : 0;
                    }
                }
            }

        }
    }
    long result = count % (1000000007);
    printf("%d\n", result);
}