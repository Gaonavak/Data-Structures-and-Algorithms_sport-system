#include "backup.h"
#include "List.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_ATHLETES 500
void writeEvent2Bak(List_project p)
{
    FILE *file = fopen("events.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    p = p->next; // 跳过头结点
    fprintf(file, "name-time-place-joined\n");
    int len = getEventLen(p);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%s-%s-%s-%d\n", p->data.name, p->data.time, p->data.place, p->data.joined);
        p = p->next;
    }
    fclose(file);
}

List_project restoreEvent()
{
    FILE *file = fopen("events.txt", "r");
    if (file == NULL) {
        // 处理文件打开失败
        return NULL;
    }

    List_project vhead = (List_project)malloc(sizeof(List_Node2));
    if (vhead == NULL) {
        // 处理内存分配失败
        fclose(file);
        return NULL;
    }

    vhead->next = NULL;
    List_project p = vhead;
    char buf[1024], tmp[1024];
    int i = 1;

    fgets(buf, sizeof(buf), file); // 跳过第一行
    while (fgets(buf, sizeof(buf), file) && i < MAX_EVENTS) {
        char *token = strtok(buf, "-");
        // 如果获取的行内容为空，跳过这一行，继续下一次循环
        if (token == NULL) {
            continue;
        }

        List_project newNode = (List_project)malloc(sizeof(List_Node2));
        if (newNode == NULL) {
            // 处理内存分配失败
            continue;
        }

        strcpy(newNode->data.name, token);

        token = strtok(NULL, "-");
        strcpy(newNode->data.time, token);

        token = strtok(NULL, "-");
        strcpy(newNode->data.place, token);

        token = strtok(NULL, "n");
        strcpy(tmp, token);
        newNode->data.joined = atoi(tmp);

        newNode->next = NULL;
        p->next = newNode; // 将新节点链接到链表
        p = newNode;       // 移动指针到新节点

        i++;
    }
    fclose(file);
    return vhead;
}

void writeAthlete2Bak(List_people p)
{
    FILE *file = fopen("athletes.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    p = p->next; // 跳过头结点
    fprintf(file, "name-sex-id-institute-joined-project1,project2-score1,score2-sumScore\n");
    int len = getAthleteLen(p);
    for (int i = 1; i <= len; i++) {
        fprintf(file, "%s-%d-%d-%s-%d-", p->data.name, p->data.sex, p->data.ID, p->data.colleges, p->data.joined);
        for (int j = 1; j <= p->data.joined; j++) {
            if (j == p->data.joined)
                fprintf(file, "%s-", p->data.projects[j].sp);
            else
                fprintf(file, "%s,", p->data.projects[j].sp);
        }
        for (int j = 1; j <= p->data.joined; j++) {
            if (j == p->data.joined)
                fprintf(file, "%d-", p->data.score[j]);
            else
                fprintf(file, "%d,", p->data.score[j]);
        }
        fprintf(file, "%d\n", p->data.sum);

        p = p->next;
    }
    fclose(file);
}

List_people restoreAthlete()
{
    FILE *file = fopen("athletes.txt", "r");
    if (file == NULL) {
        // 处理文件打开失败
        return NULL;
    }

    List_people vhead = (List_people)malloc(sizeof(List_Node1));
    if (vhead == NULL) {
        // 处理内存分配失败
        fclose(file);
        return NULL;
    }

    vhead->next = NULL;
    List_people p = vhead;
    char buf[1024], tmp[1024];
    int i = 1;

    // name-sex-id-institute-joined-project1,project2-score1,score2-sumScore
    fgets(buf, sizeof(buf), file); // 跳过第一行
    while (fgets(buf, sizeof(buf), file) && i < MAX_ATHLETES) {
        char *token = strtok(buf, "-");
        // 如果获取的行内容为空，跳过这一行，继续下一次循环
        if (token == NULL) {
            continue;
        }

        List_people newNode = (List_people)malloc(sizeof(List_Node1));
        if (newNode == NULL) {
            // 处理内存分配失败
            continue;
        }
        strcpy(newNode->data.name, token);

        token = strtok(NULL, "-");
        strcpy(tmp, token);
        newNode->data.sex = atoi(tmp);

        token = strtok(NULL, "-");
        strcpy(tmp, token);
        newNode->data.ID = atoi(tmp);

        token = strtok(NULL, "-");
        strcpy(newNode->data.colleges, token);

        token = strtok(NULL, "-");
        strcpy(tmp, token);
        newNode->data.joined = atoi(tmp);

        // 开始读取项目
        for (int j = 1; j <= newNode->data.joined; j++) {
            if (j == newNode->data.joined) {
                token = strtok(NULL, "-");
            } else {
                token = strtok(NULL, ",");
            }
            strcpy(newNode->data.projects[j].sp, token);
        }

        // 开始读取分数
        for (int j = 1; j <= newNode->data.joined; j++) {
            if (j == newNode->data.joined) {
                token = strtok(NULL, "-");
            } else {
                token = strtok(NULL, ",");
            }
            strcpy(tmp, token);
            newNode->data.score[j] = atoi(tmp);
        }

        token = strtok(NULL, "\n");
        strcpy(tmp, token);
        newNode->data.sum = atoi(tmp);

        newNode->next = NULL;
        p->next = newNode; // 将新节点链接到链表
        p = newNode;       // 移动指针到新节点

        i++;
    }

    fclose(file);
    return vhead;
}

bool hasEventBaK()
{
    FILE *file = fopen("events.txt", "r");
    if (file == NULL) {
        fclose(file);
        return false;
    }
    char buf[1024];
    int lines = 0;
    while (fgets(buf, sizeof(buf), file)) {
        lines++;
    }
    fclose(file);
    if (lines == 1) {
        return false;
    }
    return true;
}

bool hasAthleteBak()
{
    FILE *file = fopen("athletes.txt", "r");
    if (file == NULL) {
        fclose(file);
        return false;
    }
    char buf[1024];
    int lines = 0;
    while (fgets(buf, sizeof(buf), file)) {
        lines++;
    }
    fclose(file);
    if (lines == 1) {
        return false;
    }
    return true;
}

int getEventLen(List_project p)
{
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

int getAthleteLen(List_people p)
{
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

bool hasBak()
{
    if (hasEventBaK() || hasAthleteBak()) {
        printf("检测到备份...\n");
        printf("输入 y 进行恢复备份，任意键退出\n");
        return true;
    }
    return false;
}

void restoreGrade(List_people human, List_grade *mark, List_project event) {
    event=event->next;//跳过头节点
    while (event != NULL) {
        // 创建新的成绩链表节点
        List_grade newGradeNode = (List_grade)malloc(sizeof(List_Node3));
        if (newGradeNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        strncpy(newGradeNode->event_name, event->data.name, sizeof(newGradeNode->event_name) - 1);
        newGradeNode->event_name[sizeof(newGradeNode->event_name) - 1] = '\0'; // 确保字符串以空字符结尾
        newGradeNode->next = NULL;
        newGradeNode->head = NULL;

        // 寻找成绩链表尾部并插入新节点
        if ((*mark) == NULL) {
            // 如果成绩链表为空，新节点就是链表的首元结点
            (*mark) = newGradeNode;
        } else {
            // 如果成绩链表非空，遍历到链表尾部
            List_grade tempGrade = *mark;
            while (tempGrade->next != NULL) {
                tempGrade = tempGrade->next;
            }
            tempGrade->next = newGradeNode; // 将新节点添加到链表尾部
        }

        event = event->next;
    }
    human=human->next;//跳过头节点
    while (human != NULL) {

        for (int k = 1; k <=human->data.joined; k++) {
            // 在mark链表中找到对应的项目，并添加成绩
            List_grade current_mark = *mark;
            while (current_mark != NULL) {
                if (strcmp(current_mark->event_name, human->data.projects[k].sp) == 0) {
                    // 找到对应项目，添加成绩
                    grade *new_grade = (grade *)malloc(sizeof(grade));
                    if (new_grade == NULL) {
                        printf("Memory allocation failed\n");
                        return;
                    }
                    new_grade->entry.ID = human->data.ID;
                    new_grade->entry.score = human->data.score[k];
                    // 将新成绩节点插入到对应项目的成绩链表头部
                    new_grade->next = current_mark->head;
                    current_mark->head = new_grade;
                    break; // 添加完成绩后退出循环
                }
                current_mark = current_mark->next;
            }
        }

        human = human->next;
    }
    return;
}
