#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearList.h"

listType* createList(int size) {
    listType* lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
}

int destroyList(listType* list) {
    free(list->array);
    free(list);
    return 1;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in readItem\n", index);
        return NULL_ITEM;
    }
    return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
    return strcmp(item1.name, item2.name);
}

int ordered_insertItem(listType* list, elementType item) {
    int i, j;
    for (i = 0; i <= list->last; i++) {
        if (compare_item(list->array[i], item) > 0) break;
    }
    for (j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }
    list->array[i] = item;
    list->last++;
    return 1;
}

int deleteByName(listType* list, const char* name) {
    for (int i = 0; i <= list->last; i++) {
        if (strcmp(list->array[i].name, name) == 0) {
            for (int j = i; j < list->last; j++) {
                list->array[j] = list->array[j + 1];
                list->move++;
            }
            list->last--;
            return 1;
        }
    }
    return 0;
}

int searchByName(listType* list, const char* name) {
    for (int i = 0; i <= list->last; i++) {
        if (strcmp(list->array[i].name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", list->array[i].name, list->array[i].phone);
            return 1;
        }
    }
    return 0;
}

void printList(listType* list) {
    printf("\n전체 연락처\n");
    for (int i = 0; i <= list->last; i++) {
        printf("[%d] 이름: %s, 전화번호: %s\n", i + 1, list->array[i].name, list->array[i].phone);
    }
}

int initList(listType* list) {
    list->last = -1;
    list->move = 0;
    return 1;
}