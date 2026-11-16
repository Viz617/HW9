#include <stdio.h>
#include "matrixfunc.h"

int findmax(int *m, int row, int colum, int *mrow, int *mcolum)
{
    int max = *(m + 0*colum + 0);
    *mrow = 0;
    *mcolum = 0;


    if (!(row > 0 && colum > 0)){
        printf("Ошибка, неверное значение\n");
        return -1;
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < colum; j++){
            if (*(m + i*colum + j) > max){
                max = *(m + i*colum + j);
                *mrow = i;
                *mcolum = j;
            }
        }
    }
    printf("[%d][%d] MAX: %d\n", *mrow, *mcolum, max);
    return 0;
}

int sumin(int *m, int row, int colum, int k)
{
    if (!(row > 0 && colum > 0)){
        printf("Ошибка, нулевые значения\n");
        return 0;
    }

int res = 0;

for (int i = 0; i < row; i++){
    for (int j = 0; j < colum; j++){
        if ((*(m + i*colum + j)) < k){
            res += *(m + i*colum + j);
        }
    }
}
return res;
}

void diag(int *m, int row, int colum)
{
    if (!(row > 0 && colum > 0)){
        printf("Ошибка, нулевые значения\n");
        return;
    }

int res = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < colum; j++){
            if (i == j){
                res += *(m + i*colum + j);
            }
        }
    }
    printf("%d\n",res);
}