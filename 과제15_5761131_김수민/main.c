#include <stdio.h>
#include <string.h>
#include "linearList.h"

int main() {
    listType* phonebook = createList(100);
    int choice;
    elementType newEntry;
    char searchName[MAX_NAME];

    while (1) {
        printf("\n===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("이름을 입력하세요: ");
                fgets(newEntry.name, MAX_NAME, stdin);
                newEntry.name[strcspn(newEntry.name, "\n")] = '\0'; 
                printf("전화번호를 입력하세요: ");
                fgets(newEntry.phone, MAX_PHONE, stdin);
                newEntry.phone[strcspn(newEntry.phone, "\n")] = '\0';
                ordered_insertItem(phonebook, newEntry);
                printf("연락처가 추가되었습니다.\n");
                break;
            case 2:
                printf("삭제할 이름을 입력하세요: ");
                fgets(searchName, MAX_NAME, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';
                if (deleteByName(phonebook, searchName))
                    printf("삭제되었습니다.\n");
                else
                    printf("해당 이름을 찾을 수 없습니다.\n");
                break;
            case 3:
                printf("검색할 이름을 입력하세요: ");
                fgets(searchName, MAX_NAME, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';
                if (!searchByName(phonebook, searchName))
                    printf("해당 이름을 찾을 수 없습니다.\n");
                break;
            case 4:
                printList(phonebook);
                break;
            case 0:
                destroyList(phonebook);
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }
}
