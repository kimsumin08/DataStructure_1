/*
함수 is_prime(num):
    만약 num < 2이면
        return 0
    for i = 2부터 i * i <= num까지:
        만약 num % i == 0이면
            return 0
    return 1

main 함수:
    정수 N 선언
    N 입력 받기

    "N 이하의 소수: " 출력

    for i = 2부터 i <= N까지:
        만약 is_prime(i)가 참이면
            i 출력

전체 시간 복잡도: O(N√N)
- 외부 반복문 (2부터 N까지): O(N)
- 내부에서 `is_prime(i)` 호출: O(√N) 
- 따라서 전체 시간 복잡도는 **O(N√N)**
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
