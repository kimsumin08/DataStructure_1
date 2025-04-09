#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

int readMatrix(Term mat[]) {
    int count = 0;
    while (1) {
        int r, c, v;
        scanf("%d", &r);
        if (r == -1) break;
        scanf("%d %d", &c, &v);
        mat[count].row = r;
        mat[count].col = c;
        mat[count].value = v;
        count++;
    }
    return count;
}

int compare(Term a, Term b) {
    if (a.row != b.row) return a.row - b.row;
    return a.col - b.col;
}

void sortMatrix(Term mat[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compare(mat[i], mat[j]) > 0) {
                Term temp = mat[i];
                mat[i] = mat[j];
                mat[j] = temp;
            }
        }
    }
}

int addMatrix(Term a[], int aSize, Term b[], int bSize, Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < aSize && j < bSize) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            result[k] = a[i];
            result[k].value += b[j].value;
            k++; i++; j++;
        } else if (compare(a[i], b[j]) < 0) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
    while (i < aSize) result[k++] = a[i++];
    while (j < bSize) result[k++] = b[j++];

    return k;
}

void printMatrix(Term mat[], int size) {
    printf("두 행렬의 합\n");
    printf("List: size = %d, last = %d\n", size * 5, size - 1);
    printf("Items:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] %d, %d, %d\n", i, mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    Term mat1[MAX_SIZE], mat2[MAX_SIZE], result[MAX_SIZE * 2];
    int size1, size2, resultSize;

    printf("행렬을 입력하세요? (-1입력 시 행렬의 입력이 종료됨)\n");
    size1 = readMatrix(mat1);

    printf("행렬을 입력하세요? (-1입력 시 행렬의 입력이 종료됨)\n");
    size2 = readMatrix(mat2);

    sortMatrix(mat1, size1);
    sortMatrix(mat2, size2);
    resultSize = addMatrix(mat1, size1, mat2, size2, result);

    sortMatrix(result, resultSize); 
    printMatrix(result, resultSize);

    return 0;
}
