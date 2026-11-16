#include <stdio.h>
#include "matrixfunc.h"

int main(void)
{
    int row = 0, colum = 0, m[1000];
    char k;
    int k1 = 0;
    while(1){
        printf("a. Задать размер матрицы (строки, столбцы): \n");
        printf("b. Заполнить матрицу: \n");
        printf("c. Представление матрицы (значения, адреса элементов): \n");
        printf("d. Поиск индексов(строка и столбец) максимального элемента матрицы: \n");
        printf("e. Вычисление суммы элементов, значения которых ниже заданного k: \n");
        printf("f. Вычисление суммы элементов главной диагонали матрицы: \n");
        printf("g. Выход: \n");

        int err = scanf(" %c", &k);
            if (err ==  EOF){
                return 0;
            }
            if (err != 1){
                while(getchar() != '\n');
                continue;
            }
            while(getchar() != '\n');
            switch(k){

        case 'a':
            scanf("%d %d", &row, &colum);
            if (row <= 0 || colum <= 0 || row > 100 || colum > 100){
                printf("Ошибка размера масива\n");
                row = 0; colum = 0;
            } else {break;}

        case 'b':
        if (row == 0 || colum == 0 ){
            printf("Error\n");
        } 
        else { 
            printf("Значение введите: \n");
            for(int i = 0; i < row; i++){
                for(int j = 0; j < colum; j++){
                    while (scanf("%d", (m + i*colum + j)) != 1){
                        printf("Ошибка, не число\n");
                        while (getchar() != '\n');
                    }
                }
            }
        }
        break;

        case 'c':
        for (int i = 0; i < row ; i++){
            for (int j = 0; j < colum ; j++){
                printf("Значения: %d Адреса элементов: %p\n",*(m + i*colum +j),(void*)(m + i*colum +j));
        }
    }
        break;

        case 'd':{
            int mrow, mcolum;
            int res = findmax(m, row, colum, &mrow, &mcolum);
            break;
        }
        case 'e':{
            printf("Введите значение k: \n");
            scanf("%d",&k1);
            int sum = sumin(m, row, colum, k1);
            printf("Сумма элементов меньше %d: %d\n", k1, sum);
            break;
        }
        case 'f':
            printf("Сумма элементов главной диагонали матрицы: \n");
            diag(m, row, colum);
            printf("\n");
            break;

        case 'g':
            return 0;

        default:
            printf("Ошибка\n");
            continue;

    }
}
}
