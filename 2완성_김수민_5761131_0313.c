#include <stdio.h>

void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    float num;
    printf("실수를 입력하세요: ");
    scanf("%f", &num);

    unsigned int *p = (unsigned int *)&num;

    unsigned int sign = (*p >> 31) & 1;            
    unsigned int jisu = (*p >> 23) & 0xFF;    
    unsigned int gasu = (*p) & 0x7FFFFF;      

    printf("부호 (1비트) : %u\n", sign);
    printf("지수 (8비트) : ");
    printBinary(jisu, 8);
    printf("\n가수 (23비트) : ");
    printBinary(gasu, 23);
    printf("\n");

    return 0;
}