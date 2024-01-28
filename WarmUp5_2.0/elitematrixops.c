#include <stdio.h>

#define ROWS sizeof(matrix1) / sizeof(matrix1[0])
#define COLS sizeof(matrix1[0]) / sizeof(matrix1[0][0])
#define ROWSB sizeof(matrix2) / sizeof(matrix2[0])
#define COLSB sizeof(matrix2[0]) / sizeof(matrix2[0][0])

void addMatrices(int a[ROWS][COLS], int b[ROWSB][COLSB], int sum[ROWS][COLS]) {
    if (ROWS != ROWSB || COLS != COLSB) {
        printf("Matrices cannot be added\n");
    } else {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
    }
}

void multiplyMatrices(int a[ROWS][COLS], int b[ROWSB][COLSB], int product[ROWS][COLSB]) {
    if (COLS != ROWSB) {
        printf("Matrices cannot be multiplied\n");
    } else {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLSB; j++) {
                product[i][j] = 0;
                for (int k = 0; k < COLS; k++) {
                    product[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *((matrix + i * cols) + j));
        }
        printf("\n");
    }
}

int main() {
    int matrix1[][2] = {{1, 2}, {3, 4}};
    int matrix2[][3] = {{5, 6, 7}, {7, 8, 9}};
    int sum[ROWS][COLS];
    int product[ROWS][COLSB];

    addMatrices(matrix1, matrix2, sum);
    if (ROWS == ROWSB && COLS == COLSB) {
        printf("Matrix Addition:\n");
        printMatrix((int *)sum, ROWS, COLS);
    }

    multiplyMatrices(matrix1, matrix2, product);
    if (COLS == ROWSB) {
        printf("Matrix Multiplication:\n");
        printMatrix((int *)product, ROWS, COLSB);
    }

    return 0;
}
