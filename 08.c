/*
START
    DECLARE arr1[2][2], arr2[2][2], sum_arr[2][2]

    PRINT "첫 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 1 
        FOR j FROM 0 TO 1
            READ
        END FOR
    END FOR

    PRINT "두 번째 2x2 행렬 입력:"
    FOR i FROM 0 TO 1 
        FOR j FROM 0 TO 1
            READ 
        END FOR
    END FOR

    FOR i FROM 0 TO 1 
        FOR j FROM 0 TO 1 
            result
        END FOR
    END FOR

    PRINT "행렬 덧셈 결과:"
    FOR i FROM 0 TO 1 
        FOR j FROM 0 TO 1 
            PRINT
        END FOR
        PRINT
    END FOR
END
*/

#include <stdio.h>

int main() {
    int arr1[2][2], arr2[2][2], sum_arr[2][2];

    printf("첫 번째 2x2 행렬 입력:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("두 번째 2x2 행렬 입력:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            sum_arr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("행렬 덧셈 결과:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", sum_arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}