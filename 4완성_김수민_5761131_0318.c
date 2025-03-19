/*
1. 정수 N을 입력받는다.
2. 2부터 N까지의 수를 하나씩 검사한다.
3. 각 수가 소수인지 판별하기 위해 2부터 자기 자신의 제곱근까지 나눠본다.
4. 나누어 떨어지는 수가 없으면 소수로 판별하고 출력한다.
*/

#include <stdio.h>


int is_prime(int num) {
    if (num < 2) return 0;  
    for (int i = 2; i * i <= num; i++) {  
        if (num % i == 0) return 0;  
    }
    return 1;  
}

int main() {
    int N;

    printf("정수 n을 입력하세요: ");
    scanf("%d", &N);

    printf("%d 이하의 소수: ", N);
    
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {  
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
