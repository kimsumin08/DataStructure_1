#include <stdio.h> // 표준 입출력 함수를 사용하기 위한 헤더 파일

// 주어진 정수의 32비트 이진 표현을 출력하는 함수
void printBits(unsigned int num) {
    // 31번째 비트(최상위 비트)부터 0번째 비트까지 반복
    for (int i = 31; i >= 0; i--) {
        // 해당 비트가 1인지 0인지 판단하여 출력
        // (num >> i)는 num을 i비트만큼 오른쪽으로 이동하여 해당 비트를 최하위 비트로 이동
        // & 1을 통해 해당 비트가 1인지 0인지 확인
        printf("%d", (num >> i) & 1);
    }
    printf("\n"); // 줄바꿈
}

int main() {
    int num; // 사용자로부터 입력받을 정수 변수

    // 사용자로부터 정수를 입력받음
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    // 입력된 정수의 32비트 이진 표현 출력
    printf("입력된 정수의 32비트 표현: ");
    printBits((unsigned int)num); // 정수를 unsigned int로 변환하여 부호에 관계없이 출력

    return 0; // 프로그램 정상 종료
}
