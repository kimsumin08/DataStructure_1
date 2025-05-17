#include <stdio.h>
#include <stdlib.h>
#include "Linked List.h"

int main() {
    linkedList_h* list = createCLinkedList();
    int menu, val, ref;

    while (1) {
        printf("\n======= Linked_List Menu =======\n");
        printf("1) insertFirst   (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast    (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle  (특정 값 뒤에 삽입)\n");
        printf("4) insertNthNode (N번째 위치 삽입)\n");
        printf("6) deleteNode    (특정 값 삭제)\n");
        printf("7) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu ▶ ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("삽입할 값: ");
                scanf("%d", &val);
                insertFirstNode(list, val);
                printList(list);
                break;
            case 2:
                printf("삽입할 값: ");
                scanf("%d", &val);
                insertLastNode(list, val);
                printList(list);
                break;
            case 3:
                printf("(key) 어떤 값 뒤에? ");
                scanf("%d", &ref);
                printf("삽입할 값: ");
                scanf("%d", &val);
                insertMiddleByValue(list, ref, val);
                printList(list);
                break;
            case 4:
                printf("삽입할 위치: ");
                scanf("%d", &ref);
                printf("삽입할 값: ");
                scanf("%d", &val);
                insertNthNode(list, ref, val);
                printList(list);
                break;
            case 6:
                printf("삭제할 값: ");
                scanf("%d", &val);
                deleteNodeByValue(list, val);
                printList(list);
                break;
            case 7:
                if (list->head == NULL) {
                    printf("Head/Tail ▶ 리스트가 비어 있습니다.\n");
                } else {
                    printHeadTail(list);
                }
                break;
            case 0:
                printf("프로그램 종료\n");
                destroyLinkedList(list);
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}
