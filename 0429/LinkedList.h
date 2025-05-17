#pragma once

typedef int elementType; //노드에 저장할 데이터는 정수

typedef struct ListNode { //연결리스트의 노드 타입 정의
    elementType data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode * head;
} linkedList_h;

extern insertFirstNode(linkedList_h* L, elementType)
