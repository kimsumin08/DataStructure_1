#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name; 
    int id;
    int score;
} Student;

int main() {
    int count;
    printf("몇명의 학생 정보를 입력하시나요? ");
    scanf("%d", &count);

    Student *students = (Student *)malloc(sizeof(Student) * count);

    for (int i = 0; i < count; i++) {
        (*(students + i)).name = (char *)malloc(sizeof(char) * 100); 

        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i + 1);
        scanf("%s %d %d", (*(students + i)).name, &((*(students + i)).id), &((*(students + i)).score));
    }

    while (1) {
        int search_id;
        printf("학번을 입력하세요(0이면 종료)? ");
        scanf("%d", &search_id);

        if (search_id == 0)
            break;

        int found = 0;
        for (int i = 0; i < count; i++) {
            if ((*(students + i)).id == search_id) {
                printf("%s %d %d\n", (*(students + i)).name, (*(students + i)).id, (*(students + i)).score);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("해당 학번의 학생이 없습니다.\n");
    }

    for (int i = 0; i < count; i++) {
        free((*(students + i)).name);
    }

    free(students);
    return 0;
}