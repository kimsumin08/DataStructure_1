#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
1. `IntegerADT` 구조체를 정의하여 정수를 저장하고 연산 함수를 제공.
2. `add`, `subtract`, `multiply`, `divide` 함수로 사칙연산을 수행.
3. 사용자에게 두 개의 정수를 입력받고 연산 수행.
4. 문자열로 수식을 입력받아 연산 처리.
5. 결과 출력 후 종료.
*/

typedef struct {
    int value;
} IntegerADT;

IntegerADT add(IntegerADT a, IntegerADT b) {
    IntegerADT result;
    result.value = a.value + b.value;
    return result;
}

IntegerADT subtract(IntegerADT a, IntegerADT b) {
    IntegerADT result;
    result.value = a.value - b.value;
    return result;
}

IntegerADT multiply(IntegerADT a, IntegerADT b) {
    IntegerADT result;
    result.value = a.value * b.value;
    return result;
}

IntegerADT divide(IntegerADT a, IntegerADT b) {
    IntegerADT result;
    if (b.value == 0) {
        printf("오류: 0으로 나눌 수 없습니다.\n");
        result.value = 0;
    } else {
        result.value = a.value / b.value;
    }
    return result;
}

double evaluateExpression(const char *expression) {
    double result = 0;
    char op = '+';
    double num = 0;
    int i = 0;

    while (expression[i] != '\0') {
        if (isdigit(expression[i]) || expression[i] == '.') {
            num = strtod(&expression[i], NULL);
            while (isdigit(expression[i]) || expression[i] == '.') i++;
        }

        if (expression[i] == ' ' || expression[i] == '\0') {
            if (op == '+') result += num;
            else if (op == '-') result -= num;
            else if (op == '*') result *= num;
            else if (op == '/') {
                if (num == 0) {
                    printf("오류: 0으로 나눌 수 없습니다.\n");
                    return 0;
                }
                result /= num;
            }
            if (expression[i] == '\0') break;
            op = expression[i++];
        }
    }
    return result;
}

int main() {
    IntegerADT num1, num2;
    char expression[100];


    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf("%d", &num1.value);
    
    printf("두 번째 양의 정수를 입력하세요: ");
    scanf("%d", &num2.value);

    IntegerADT sum = add(num1, num2);
    IntegerADT diff = subtract(num1, num2);
    IntegerADT prod = multiply(num1, num2);
    IntegerADT quot = divide(num1, num2);

    printf("덧셈: %d\n", sum.value);
    printf("뺄셈: %d\n", diff.value);
    printf("곱셈: %d\n", prod.value);
    printf("나눗셈: %d\n", quot.value);

    printf("계산할 수식을 입력하세요 (예: 50/90 - 50 * 0.5 + 9): ");
    getchar();
    fgets(expression, sizeof(expression), stdin);

    double result = evaluateExpression(expression);
    printf("결과: %.6f\n", result);

    return 0;
}
