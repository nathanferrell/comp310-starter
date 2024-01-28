#include <stdio.h>

#define ROWS 2
#define COLS 2
#define ROWSB 2
#define COLSB 3

void addMatrices(int a[ROWS][COLS], int b[ROWSB][COLSB], int sum[ROWS][COLS]) {
    if(ROWS!=ROWSB||COLS!=COLSB){
        printf("Matrices cannot be added\n");
    }else{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}
}
void multiplyMatrices(int a[ROWS][COLS], int b[ROWSB][COLSB], int product[ROWS][COLSB]) {
if(COLS!=ROWSB){
    printf("Matrices cannot be multiplied");
}else{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLSB; j++) {
            product[i][j] = 0;
            for (int k = 0; k < COLSB; k++) { // Assuming square matrices for simplicity
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
}
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2}, {3, 4}};
    int matrix2[ROWSB][COLSB] = {{5, 6, 7}, {7, 8, 9}};

    int sum[ROWS][COLS];
    int product[ROWS][COLSB];

    addMatrices(matrix1, matrix2, sum);
    multiplyMatrices(matrix1, matrix2, product);

    printf("Matrix Addition:\n");
    printMatrix(sum);
    printf("Matrix Multiplication:\n");
    printMatrix(product);

    return 0;
}
