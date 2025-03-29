/*
1. 정수 N을 입력받는다.  // O(1)

2. 2부터 N까지 반복하면서 각 수를 검사한다.  // O(N)
   2.1 현재 숫자가 소수인지 판별하기 위해 is_prime 함수 호출  // O(√N)
       - 만약 숫자가 2보다 작으면 소수가 아니다.  // O(1)
       - 2부터 해당 숫자의 제곱근까지 반복하면서 나눠본다.  // O(√N)
       - 하나라도 나누어 떨어지는 수가 있으면 소수가 아니다.  // O(1)
       - 나누어 떨어지는 수가 없으면 소수로 판별한다.  // O(1)
   2.2 소수로 판별되면 출력한다.  // O(1)

3. 모든 소수를 출력한 후 프로그램 종료.  // O(1)

### 전체 시간 복잡도: O(N√N)
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
