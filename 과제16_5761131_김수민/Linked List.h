#pragma once

typedef int elementType;

typedef struct ListNode {
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {
	int follow;
	listNode* head;
	listNode* tail;  
} linkedList_h;

extern linkedList_h* createLinkedList(void);
extern linkedList_h* createCLinkedList(void);
extern void destroyLinkedList(linkedList_h* L);
extern void destroyCLinkedList(linkedList_h* L);

extern int printList(linkedList_h* L);
extern int printCList(linkedList_h* L);
extern void printHeadTail(linkedList_h* L);

extern int insertFirstNode(linkedList_h* L, elementType item);           // 수정: void → int
extern int insertFirstCNode(linkedList_h* L, elementType item);          // 수정: void → int
extern void insertLastNode(linkedList_h* L, elementType item);  
extern void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);
extern void insertMiddleByValue(linkedList_h* L, elementType target, elementType item);
extern void insertNthNode(linkedList_h* L, int loc, elementType item);
extern void ordered_insertNode(linkedList_h* L, elementType item);

extern void deleteNode(linkedList_h* L, listNode* p);
extern void deleteCNode(linkedList_h* L, listNode* p);
extern void deleteNodeByValue(linkedList_h* L, elementType target);
