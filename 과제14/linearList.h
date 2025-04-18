#pragma once

// 다항식 항 하나를 나타내는 구조체 (계수와 차수)
#define NULL_ITEM (elementType){0, 0}

typedef struct ElementType {
    int coef;  // 계수
    int expo;  // 차수
} elementType;

// 선형 리스트 구조체
typedef struct ListType {
    int size;           // 전체 배열 크기
    int last;           // 마지막 요소 인덱스
    int move;           // 이동 횟수 (정렬 삽입 시 사용)
    elementType* array; // 항 저장 배열
} listType;

// 함수 선언부
listType* createList(int size);
int destroyList(listType* list);

elementType readItem(listType* list, int index);
elementType deleteItem(listType* list, int index);

int insertItem(listType* list, int index, elementType item);
int ordered_insertItem(listType* list, elementType item);

int printList(listType* list);
int initList(listType* list);