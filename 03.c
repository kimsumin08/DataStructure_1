#include <stdio.h>

// 문자열의 대소문자를 서로 변환하는 함수
void convert_case(char *str) {
    while (*str) {
        // 대문자일 경우 소문자로 변환
        if (*str >= 'A' && *str <= 'Z') {
            *str += ('a' - 'A');
        }
        // 소문자일 경우 대문자로 변환
        else if (*str >= 'a' && *str <= 'z') {
            *str -= ('a' - 'A');
        }
        str++; // 다음 문자로 이동
    }
}

// 문자열의 길이를 구하는 함수
int get_length(const char *str) {
    int length = 0;
    while (*str++) { // 널 문자를 만날 때까지 반복
        length++;
    }
    return length;
}

int main() {
    char str[100]; // 입력 받을 문자열 배열

    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin); // 문자열 입력

    int length = get_length(str) - 1; // 개행 문자 제외한 길이 계산

    printf("문자열의 길이: %d\n", length);

    convert_case(str); // 대소문자 변환

    printf("변환된 문자열: %s", str); // 변환된 문자열 출력

    return 0;
}
