#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList.h"

// 다항식 문자열 파싱 함수
listType* parsePolynomial(char* input) {
    listType* poly = createList(100);
    char* ptr = input;
    int coef, expo;
    char sign = '+';

    while (*ptr) {
        while (*ptr == ' ') ptr++;

        if (*ptr == '+' || *ptr == '-') {
            sign = *ptr;
            ptr++;
        }

        coef = 0;
        while (isdigit(*ptr)) {
            coef = coef * 10 + (*ptr - '0');
            ptr++;
        }

        if (coef == 0 && *ptr == 'x') coef = 1;
        if (sign == '-') coef *= -1;

        if (*ptr == 'x') {
            ptr++;
            if (*ptr == '^') {
                ptr++;
                expo = 0;
                while (isdigit(*ptr)) {
                    expo = expo * 10 + (*ptr - '0');
                    ptr++;
                }
            } else {
                expo = 1;
            }
        } else {
            expo = 0;
        }

        ordered_insertItem(poly, (elementType){coef, expo});
        sign = '+';
    }

    return poly;
}

// 다항식 곱셈 함수 (최적 크기 적용)
listType* polymul(listType* f, listType* s) {
    int resultSize = (f->last + 1) * (s->last + 1);  // ✅ 실제 필요한 크기 계산
    listType* result = createList(resultSize);
    initList(result);

    for (int i = 0; i <= f->last; i++) {
        for (int j = 0; j <= s->last; j++) {
            elementType a = readItem(f, i);
            elementType b = readItem(s, j);
            elementType product = { a.coef * b.coef, a.expo + b.expo };

            int found = 0;
            for (int k = 0; k <= result->last; k++) {
                if (result->array[k].expo == product.expo) {
                    result->array[k].coef += product.coef;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                ordered_insertItem(result, product);
            }
        }
    }

    return result;
}

// 포맷 출력 함수
void printFormatted(listType* list) {
    printf("List: size = %d, last = %d, move = %d\n", list->size, list->last, list->move);
    printf("Items: P(x) = ");
    for (int i = list->last; i >= 0; i--) {
        int coef = list->array[i].coef;
        int expo = list->array[i].expo;

        if (i != list->last && coef > 0) printf("+");

        printf("%d", coef);
        if (expo > 1) printf("X^%d", expo);
        else if (expo == 1) printf("X");
    }
    printf("\n");
}

int main() {
    char buf1[256], buf2[256];

    printf("첫 번째 다항식을 입력하세요 (예: 3x^2+4x+1):\n");
    fgets(buf1, sizeof(buf1), stdin);
    buf1[strcspn(buf1, "\n")] = 0;

    printf("두 번째 다항식을 입력하세요 (예: 2x^2+5x+3):\n");
    fgets(buf2, sizeof(buf2), stdin);
    buf2[strcspn(buf2, "\n")] = 0;

    listType* poly1 = parsePolynomial(buf1);
    listType* poly2 = parsePolynomial(buf2);

    listType* result = polymul(poly1, poly2);

    printf("\n[곱셈 결과]\n");
    printFormatted(result);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(result);

    return 0;
}
