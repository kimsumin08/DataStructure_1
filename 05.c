#include <stdio.h>

// 사칙연산을 위한 추상 자료형 정의
typedef struct {
    int num1;
    int num2;
} Numbers;

// 덧셈 함수 선언
int add(Numbers nums);

// 뺄셈 함수 선언
int subtract(Numbers nums);

// 곱셈 함수 선언
int multiply(Numbers nums);

// 나눗셈 함수 선언
float divide(Numbers nums);

int main() {
    Numbers nums;

    // 사용자로부터 양의 정수 입력받기
    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf("%d", &nums.num1);

    printf("두 번째 양의 정수를 입력하세요: ");
    scanf("%d", &nums.num2);

    // 사칙연산 결과 출력
    printf("덧셈: %d\n", add(nums));
    printf("뺄셈: %d\n", subtract(nums));
    printf("곱셈: %d\n", multiply(nums));
    printf("나눗셈: %.2f\n", divide(nums));

    return 0;
}

// 덧셈 함수 구현
int add(Numbers nums) {
    return nums.num1 + nums.num2;
}

// 뺄셈 함수 구현
int subtract(Numbers nums) {
    return nums.num1 - nums.num2;
}

// 곱셈 함수 구현
int multiply(Numbers nums) {
    return nums.num1 * nums.num2;
}

// 나눗셈 함수 구현
float divide(Numbers nums) {
    if (nums.num2 == 0) {
        printf("0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return (float)nums.num1 / nums.num2;
}