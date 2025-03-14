#include <stdio.h>

// 주어진 정수를 지정된 비트 수만큼 이진수로 출력하는 함수
void printBinary(unsigned int num, int bits) {
    // 가장 높은 비트부터 차례로 확인하여 출력
    for (int i = bits - 1; i >= 0; i--) {
        // 비트 이동과 AND 연산을 통해 해당 비트가 1인지 0인지 판단하여 출력
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    float num; // 사용자가 입력할 실수 변수
    printf("실수를 입력하세요: ");
    scanf("%f", &num); 

    // float형 변수 num의 메모리 주소를 unsigned int 포인터로 변환하여 가리킴
    unsigned int *p = (unsigned int *)&num;

    // 부호 비트 추출: 31번째 비트를 오른쪽으로 이동시키고 AND 연산으로 값 추출
    unsigned int sign = (*p >> 31) & 1;
    
    // 지수부 추출: 23~30번째 비트를 오른쪽으로 23만큼 이동시키고 8비트만 추출
    unsigned int jisu = (*p >> 23) & 0xFF;
    
    // 가수부 추출: 0~22번째 비트만 사용하므로 해당 비트들만 추출
    unsigned int gasu = (*p) & 0x7FFFFF;

    // 추출된 부호 비트 출력
    printf("부호 (1비트) : %u\n", sign);
    
    // 추출된 지수 비트들을 이진수로 출력
    printf("지수 (8비트) : ");
    printBinary(jisu, 8);
    
    // 추출된 가수 비트들을 이진수로 출력
    printf("\n가수 (23비트) : ");
    printBinary(gasu, 23);
    printf("\n");

    return 0;
}
