#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return (IdxType) ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m) {
    return (IdxType) COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

    for (i = 0; i <= getLastIdxRow(mIn); i++)
    {
        for (j = 0; j <= getLastIdxCol(mIn); j++)
        {
            ELMT(*mOut,i,j) = ELMT(mIn,i,j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    IdxType i, j;

    createMatrix(nRow, nCol, m);
    
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m1),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }

    return mnew;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m1),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }

    return mnew;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mnew);
    IdxType i, j, k;
    int jumlah = 0;
    for (i = 0; i <= ROW_EFF(m1); i++)
    {
        for (j = 0; j <= COL_EFF(m2); j++)
        {
            for (k = 0; k <= ROW_EFF(m2); k++)
            {
                jumlah = jumlah + ELMT(m1,i,k)*ELMT(m2,k,j);
            }
            ELMT(mnew,i,j) = jumlah;
            jumlah = 0; 
        }
    }
    return mnew;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mnew);
    IdxType i, j, k;
    int jumlah = 0;
    for (i = 0; i <= ROW_EFF(m1); i++)
    {
        for (j = 0; j <= COL_EFF(m2); j++)
        {
            for (k = 0; k <= ROW_EFF(m2); k++)
            {
                jumlah = jumlah + ELMT(m1,i,k)*ELMT(m2,k,j);
            }
            ELMT(mnew,i,j) = jumlah%mod;
            jumlah = 0; 
        }
    }
    return mnew;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m), COL_EFF(m),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m,i,j) * x;
        }
    }

    return mnew;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    IdxType i, j;

    for (i = 0; i <=  getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            ELMT(*m,i,j) = ELMT(*m,i,j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    IdxType i,j;
    boolean hasil;

    hasil = true;
    
    if (((getLastIdxRow(m1) != getLastIdxRow(m2)) || (getLastIdxCol(m1) != getLastIdxCol(m2))))
    {
        hasil = false;
    }
    else
    {
        i = 0;
        while ((i <= getLastIdxRow(m1)) && hasil)
        {
            j = 0;
            while ((j <= getLastIdxCol(m1)) && hasil)
            {
                if (ELMT(m1,i,j) != ELMT(m2,i,j))
                {
                    hasil = false;
                }
                j++;
            }
            i++;
        }
    }
    return hasil;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    IdxType i, j;
    boolean hasil;

    hasil = true;
    int count = 0;
    if (((getLastIdxRow(m1) != getLastIdxRow(m2)) || (getLastIdxCol(m1) != getLastIdxCol(m2))))
    {
        return true;
    }
    else
    {
        i = 0;
        while(i <= getLastIdxRow(m1))
        {
            j = 0;
            while(j <= getLastIdxCol(m1))
            {
                if (ELMT(m1,i,j) == ELMT(m2,i,j))
                {
                    count++;
                }
                j++;
            }
            i++;
        }
    }
    if (count == countElmt(m1))
    {
        hasil = false;
    }
    return hasil;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return ((getLastIdxRow(m1) == getLastIdxRow(m2)) && (getLastIdxCol(m1) == getLastIdxCol(m2)));
}

int countElmt(Matrix m) {
    return (ROW_EFF(m)*COL_EFF(m));
}

boolean isSquare(Matrix m) {
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
    IdxType i, j;
    if (isSquare(m))
    {
        for (i = 0; i <= getLastIdxRow(m); i++)
        {
            for (j = 0; j <= getLastIdxCol(m); j++)
            {
                if (ELMT(m,i,j) != ELMT(m,j,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

boolean isIdentity(Matrix m) {
    IdxType i,j;
    boolean hasil;

    hasil = true;

    if (!isSquare(m))
    {
        hasil = false;
    }
    else{
        i = 0;
        while (i < getLastIdxRow(m) && hasil)
        {
            j = 0;
            while (j < getLastIdxCol(m) && hasil)
            {
                hasil = ((i != j) && (ELMT(m,i,j) == 0) || (i==j)&&(ELMT(m,i,j) == 1));
                j++;
            }
            i++;
        }
    }
    return hasil;
}

boolean isSparse(Matrix m) {
    float max = (ROW_EFF(m) * COL_EFF(m)) * 0.05;
    max = (int)max;
    int countNotZero = 0;
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                countNotZero++;
            }
        }
    }
    return (countNotZero <= max);
}

Matrix negation(Matrix m) {
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m), COL_EFF(m),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m,i,j) * (-1);
        }
    }

    return mnew;
}

void pNegation(Matrix *m) {
    IdxType i, j;

    for (i = 0; i <=  getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            ELMT(*m,i,j) = ELMT(*m,i,j) * (-1);
        }
    }
}

float cofactor(Matrix m, IdxType a, IdxType b) {
    IdxType i, j, iHasil, jHasil;
    Matrix mHasil;
    float hasil;

    hasil = 0;
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mHasil);

    iHasil = 0;
    for (i = 0; i <= getLastIdxRow(m); i++) {
        jHasil = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (i == a) {
                iHasil = i - 1;
            } else if (j == b) {
                jHasil = j - 1;
            } else {
                ELMT(mHasil, iHasil, jHasil) = ELMT(m, i, j);
            }
            jHasil++;
        }
        iHasil++;
    }

    if ((a + b) % 2 == 0) {
        hasil = determinant(mHasil);
    } else {
        hasil = -1 * determinant(mHasil);
    }

    return hasil;
}

float determinant(Matrix m) {
    IdxType i, j;
    float hasil;

    hasil = 0;

    if (countElmt(m) == 1) {
        hasil = (float) ELMT(m, 0, 0);
    } else {
        i = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            hasil += ((float) ELMT(m, i, j)) * cofactor(m, i, j);
        }
    }

    return hasil;
}

Matrix transpose(Matrix m) {
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(m, i, j);
        }
    }

    return mhasil;
}

void pTranspose(Matrix *m) {
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mhasil);

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(*m, i, j);
        }
    }
    *m = mhasil;
}