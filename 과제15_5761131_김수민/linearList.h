#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#define MAX_NAME 20
#define MAX_PHONE 20

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} elementType;

typedef struct {
    elementType* array;
    int size; 
    int last;
    int move;
} listType;

#define NULL_ITEM (elementType){"", ""}

listType* createList(int size);
int destroyList(listType* list);
elementType readItem(listType* list, int index);
int compare_item(elementType item1, elementType item2);
int ordered_insertItem(listType* list, elementType item);
int deleteByName(listType* list, const char* name);
int searchByName(listType* list, const char* name);
void printList(listType* list);
int initList(listType* list);

#endif