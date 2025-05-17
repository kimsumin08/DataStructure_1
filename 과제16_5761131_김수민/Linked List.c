#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

linkedList_h* createLinkedList(void) {
    linkedList_h* lptr;
    lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
    lptr->head = NULL;
    lptr->tail = NULL;  
    lptr->follow = 0;
    return lptr;
}

linkedList_h* createCLinkedList(void) {
    return createLinkedList();
}

void destroyLinkedList(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
    free(L);
}

void destroyCLinkedList(linkedList_h* L) {
    if (!L || !L->head) return;
    listNode* cur = L->head;
    listNode* next;
    do {
        next = cur->link;
        free(cur);
        cur = next;
    } while (cur != L->head);
    free(L);
}

int printList(linkedList_h* L) {
    listNode* lptr = L->head;
    printf("Linked List(%d): ", L->follow);
    if (lptr == NULL) {
        printf("비어 있음\n");
        return 0;
    }
    listNode* start = lptr;
    do {
        printf("[%d]", lptr->data);
        lptr = lptr->link;
    } while (lptr != start);
    printf("\n");
    return 0;
}

int printCList(linkedList_h* L) {
    listNode* lptr = L->head;
    printf("Circular Linked List(%d): ", L->follow);
    if (lptr == NULL) {
        printf("\n");
        return 0;
    }
    listNode* start = lptr;
    do {
        printf("[%d]", lptr->data);
        lptr = lptr->link;
    } while (lptr != start);
    printf("\n");
    return 0;
}

int insertFirstNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head == NULL) {
        newNode->link = newNode;
        L->head = L->tail = newNode;
    } else {
        newNode->link = L->head;
        L->tail->link = newNode;  
        L->head = newNode;
    }

    L->follow++;
    return 0;
}

int insertFirstCNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head != NULL) {
        newNode->link = L->head;
        L->tail->link = newNode;  
        L->head = newNode;
    } else {
        newNode->link = newNode;
        L->head = L->tail = newNode;
    }

    L->follow++;
    return 0;
}

void insertLastNode(linkedList_h* L, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head == NULL) {
        newNode->link = newNode;
        L->head = L->tail = newNode;
    } else {
        newNode->link = L->head;
        L->tail->link = newNode;
        L->tail = newNode;
    }
    L->follow++;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head == NULL || pre == NULL) {
        newNode->link = newNode;
        L->head = L->tail = newNode;
    } else {
        newNode->link = pre->link;
        pre->link = newNode;
        if (pre == L->tail) L->tail = newNode;
    }
    L->tail->link = L->head;  
    L->follow++;
}

void insertNthNode(linkedList_h* L, int loc, elementType item) {
    if (L->head == NULL) {
        if (loc == 0) insertFirstNode(L, item);
        else fprintf(stderr, "[insertNthNode: list empty and loc not 0]\n");
        return;
    } else {
        if (loc == 0) insertFirstNode(L, item);
        else {
            int i = loc;
            listNode* pre = L->head;
            while (i > 1 && pre->link != L->head) {
                i--;
                pre = pre->link;
            }
            if (i == 1) insertMiddleNode(L, pre, item);
            else fprintf(stderr, "[insertNthNode: location error]\n");
        }
    }
}

int compare_item(elementType first, elementType second) {
    return first - second;
}

void ordered_insertNode(linkedList_h* L, elementType item) {
    if (L->head == NULL || compare_item(L->head->data, item) > 0) {
        insertFirstNode(L, item);
        return;
    }

    listNode* pre = L->head;
    while (pre->link != L->head && compare_item(pre->link->data, item) < 0) {
        pre = pre->link;
    }
    insertMiddleNode(L, pre, item);
}

void deleteNode(linkedList_h* L, listNode* p) {
    if (L->head == NULL || p == NULL) return;

    if (L->head == p) {
        if (L->head == L->tail) {
            free(p);
            L->head = L->tail = NULL;
        } else {
            L->head = p->link;
            L->tail->link = L->head;
            free(p);
        }
        return;
    }

    listNode* pre = L->head;
    while (pre->link != p && pre->link != L->head) {
        pre = pre->link;
    }

    if (pre->link == p) {
        pre->link = p->link;
        if (p == L->tail) L->tail = pre;
        free(p);
    } else {
        fprintf(stderr, "deleteNode: item not found\n");
    }
}

void deleteCNode(linkedList_h* L, listNode* p) {
    if (L->head == NULL || p == NULL) return;

    listNode* cur = L->head;
    listNode* pre = NULL;

    do {
        pre = cur;
        cur = cur->link;
    } while (cur != p && cur != L->head);

    if (cur == p) {
        if (p == L->head && p == L->tail) {
            L->head = L->tail = NULL;
        } else {
            if (p == L->head) L->head = p->link;
            if (p == L->tail) L->tail = pre;
            pre->link = p->link;
        }
        free(p);
    } else {
        fprintf(stderr, "deleteCNode: item not found\n");
    }
}

void insertMiddleByValue(linkedList_h* L, elementType target, elementType item) {
    listNode* cur = L->head;
    if (cur == NULL) return;

    do {
        if (cur->data == target) {
            insertMiddleNode(L, cur, item);
            return;
        }
        cur = cur->link;
    } while (cur != L->head);

    fprintf(stderr, "insertMiddleByValue: target %d not found\n", target);
}

void deleteNodeByValue(linkedList_h* L, elementType target) {
    listNode* cur = L->head;
    listNode* pre = L->tail;

    if (cur == NULL) return;

    do {
        if (cur->data == target) {
            if (cur == L->head && cur == L->tail) {
                free(cur);
                L->head = L->tail = NULL;
            } else if (cur == L->head) {
                L->head = cur->link;
                L->tail->link = L->head;
                free(cur);
            } else {
                pre->link = cur->link;
                if (cur == L->tail) L->tail = pre;
                free(cur);
            }
            return;
        }
        pre = cur;
        cur = cur->link;
    } while (cur != L->head);

    fprintf(stderr, "deleteNodeByValue: item not found\n");
}

void printHeadTail(linkedList_h* L) {
    if (L->head == NULL) {
        printf("Head/Tail ▶ 리스트가 비어 있습니다.\n");
    } else {
        printf("Head: %d, Tail: %d\n", L->head->data, L->tail->data);
    }
}
