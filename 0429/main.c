#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int printList(linkedList h* L) {
    listNode *iptr = L->head;

    while(iptr->link != (listNode *)NULL )
        printf("[%d]", iptr->data);
        iptr = iptr->link;
    printf("[%d] \n", iptr->data);
}

main() {
    linkedList_h mylist;

    mylist.head = (listNode*)NULL;
    insertFirstNode(&mylist, 1);
    insertFirstNode(&mylist, 2);
    insertFirstNode(&mylist, 3);
    insertFirstNode(&mylist, 4);
    insertFirstNode(&mylist, 5);

    printList(&mylist);

}