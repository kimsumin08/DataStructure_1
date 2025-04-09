#include <stdio.h> // 함수를 사용하기 위한 헤더 파일

int printBits(unsigned int num) { // 주어진 정수의 비트 패턴 표현을 출력하는 함수
   
    for (int i = 31; i >= 0; i--) {
        
        // 해당 비트가 1인지 0인지 판단하여 출력
        printf("%d", (num >> i) & 1);  // (num >> i)은 num을 i비트만큼 오른쪽으로 이동하여 해당 비트를 최하위 비트로 이동, & 1을 통하여 해당 비트가 1인지 0인지 확인
    }
    printf("\n");

    return 0;
}

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    printf("입력된 정수의 32비트 표현: ");
    printBits((unsigned int)num); // 정수 부호에 관계없이 출력

    return 0; 
}
