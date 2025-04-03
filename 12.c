#include <stdio.h>

int fibonacci1(int n) {
    
    if (n == 0) 
        return 0;
    else if (n == 1) 
        return 1;
    else return fibonacci1(n - 1) + fibonacci1(n - 2);
}

int fibonacci2(int n) {
    int a = 0, b = 1, temp;

    if (n == 0) return a;
    if (n == 1) return b;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int method, n;

    while (1) {
        printf("\n피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
        scanf("%d", &method);

        if (method == 0) {
            printf("프로그램이 종료되었습니다.");
            break;
        }

        printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
        scanf("%d", &n);

        if (n == 0) {
            printf("프로그램이 종료되었습니다.");
            break;
        }

        if (method == 1) {
            printf("F(%d) = %d (재귀적 방법)", n, fibonacci1(n));
        } else if (method == 2) {
            printf("F(%d) = %d (순환적 방법)", n, fibonacci2(n));
        } else {
            printf("error");
        }
    }

    return 0;
}