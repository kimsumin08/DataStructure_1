#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int insertFirstNode(LinkedList_h* L, elementType item) {
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->list = L->head;
    L->head = newnode;

    return 0;
}
