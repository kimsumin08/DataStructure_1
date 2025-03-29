/*
START
    FOR 
     FOR
      IF arr[j] > arr[j+1]
       END IF
      END FOR
    END FOR

    PRINT "정수의 개수를 입력하세요: "
    READ 

    PRINT "5개의 정수를 입력하세요: "
    FOR i FROM 0 TO n-1
        READ
    END FOR

    FOR i FROM 0 TO n-2 
        FOR j FROM 0 TO n-i-2 
            IF arr[j] > arr[j+1]
            END IF
        END FOR
    END FOR

    PRINT "오름차순으로 정렬된 정수들: "
    FOR i FROM 0 TO n-1 
        PRINT
    END FOR
    PRINT
END

*/

#include <stdio.h>
#include <stdlib.h>

void Sort(int *arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("정수의 개수를 입력하세요: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("5개의 정수를 입력하세요:\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Sort(arr, n);

    printf("오름차순으로 정렬된 정수들:\n ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}