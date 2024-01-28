#include <stdio.h>

void addMatrices(int a[][COLS], int b[][COLSB], int sum[][COLS], int rowsA, int colsA, int rowsB, int colsB) {
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices cannot be added\n");
    } else {
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsA; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
    }
}

void multiplyMatrices(int a[][COLS], int b[][COLSB], int product[][COLSB], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        printf("Matrices cannot be multiplied\n");
    } else {
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                product[i][j] = 0;
                for (int k = 0; k < colsA; k++) {
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
    int rowsA = sizeof(matrix1) / sizeof(matrix1[0]);
    int colsA = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);
    int rowsB = sizeof(matrix2) / sizeof(matrix2[0]);
    int colsB = sizeof(matrix2[0]) / sizeof(matrix2[0][0]);

    int sum[rowsA][colsA];
    int product[rowsA][colsB];

    addMatrices(matrix1, matrix2, sum, rowsA, colsA, rowsB, colsB);
    if (rowsA == rowsB && colsA == colsB) {
        printf("Matrix Addition:\n");
        printMatrix((int *)sum, rowsA, colsA);
    }

    multiplyMatrices(matrix1, matrix2, product, rowsA, colsA, rowsB, colsB);
    if (colsA == rowsB) {
        printf("Matrix Multiplication:\n");
        printMatrix((int *)product, rowsA, colsB);
    }

    return 0;
}
