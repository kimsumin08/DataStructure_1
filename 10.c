#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int rows = 2, cols = 2;

 
    int *matrix1 = (int *)malloc(sizeof(int) * rows * cols);
    int *matrix2 = (int *)malloc(sizeof(int) * rows * cols);
    int *result = (int *)malloc(sizeof(int) * rows * cols);


    printf("첫 번째 2x2 행렬 입력:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", (matrix1 + i * cols + j));
        }
    }

    printf("두 번째 2x2 행렬 입력:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", (matrix2 + i * cols + j));
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }

    printf("행렬 덧셈 결과:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(result + i * cols + j));
        }
        printf("\n");
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}