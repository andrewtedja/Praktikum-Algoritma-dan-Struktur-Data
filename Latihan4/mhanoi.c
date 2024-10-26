#include "matrix.h"
#include <stdio.h>

int main() {

    //inisialisasi & read & contructor
    Matrix board, piece;
    int N;
    scanf("%d", &N);

    createMatrix(N, N, &board);
    readMatrix(&board, N, N);

    createMatrix(2, 2, &piece);
    readMatrix(&piece, 2, 2);

    Matrix rotations[4];
    int numRotations = 1;

    createMatrix(2, 2, &rotations[0]);
    copyMatrix(piece, &rotations[0]);

    //matrix rotasi
    createMatrix(2, 2, &rotations[1]);
    createMatrix(2, 2, &rotations[2]);
    createMatrix(2, 2, &rotations[3]);


    //proses

    //90
    ELMT(rotations[1], 0, 0) = ELMT(piece, 1, 0);
    ELMT(rotations[1], 0, 1) = ELMT(piece, 0, 0);
    ELMT(rotations[1], 1, 0) = ELMT(piece, 1, 1);
    ELMT(rotations[1], 1, 1) = ELMT(piece, 0, 1);

    //180
    ELMT(rotations[2], 0, 0) = ELMT(piece, 1, 1);
    ELMT(rotations[2], 0, 1) = ELMT(piece, 1, 0);
    ELMT(rotations[2], 1, 0) = ELMT(piece, 0, 1);
    ELMT(rotations[2], 1, 1) = ELMT(piece, 0, 0);

    //270 
    ELMT(rotations[3], 0, 0) = ELMT(piece, 0, 1);
    ELMT(rotations[3], 0, 1) = ELMT(piece, 1, 1);
    ELMT(rotations[3], 1, 0) = ELMT(piece, 0, 0);
    ELMT(rotations[3], 1, 1) = ELMT(piece, 1, 0);

    //remove duplicate
    for (int i = 1; i < 4; i++) {
        boolean isUnique = true;
        for (int j = 0; j < numRotations; j++) {
            if (isMatrixEqual(rotations[i], rotations[j])) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            if (numRotations != i) {
                copyMatrix(rotations[i], &rotations[numRotations]);
            }
            numRotations++;
        }
    }

    // all possibilities
    int count = 0;
    for (int i = 0; i <= ROW_EFF(board) - 2; i++) {
        for (int j = 0; j <= COL_EFF(board) - 2; j++) {
            boolean canPlaceHere = false;
            for (int r = 0; r < numRotations; r++) {
                boolean canPlace = true;
                for (int x = 0; x < 2 && canPlace; x++) {
                    for (int y = 0; y < 2; y++) {
                        if (ELMT(rotations[r], x, y) >= ELMT(board, i + x, j + y)) {
                            canPlace = false;
                            break;
                        }
                    }
                }
                if (canPlace) {
                    canPlaceHere = true;
                    break;
                }
            }
            if (canPlaceHere) {
                count++;
            }
        }
    }


    printf("%d\n", count);
    return 0;
}
