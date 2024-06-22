#include "test.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListInsert_event_auto(List_project *event, List_grade *mark)
{
    Events events[] = {
        {"篮球", "8:00~9:30", "篮球场"},
        {"100m跑步", "10:00~11:30", "足球场"},
        {"排球", "14:00~15:30", "室内排球场"},
        {"跳高", "14:00~15:30", "室内体育馆"},
        {"跳远", "16:00~17:00", "沙地"},
        {"足球", "16:00~18:30", "足球场"},
    };

    int len = sizeof(events) / sizeof(events[0]);
    for (int i = 0; i < len; i++) {
        ListInsert_event_auto_backend(event, mark, events[i]);
    }
}

void ListInsert_event_auto_backend(List_project *event, List_grade *mark, Events testData)
{
    // 创建项目新的节点
    List_project newEventNode = (List_project)malloc(sizeof(List_Node2));
    if (newEventNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // 创建新的成绩链表节点
    List_grade newGradeNode = (List_grade)malloc(sizeof(List_Node3));
    if (newGradeNode == NULL) {
        printf("Memory allocation failedn");
        return;
    }
    strncpy(newEventNode->data.name, testData.name, sizeof(newEventNode->data.name) - 1);
    newEventNode->data.name[sizeof(newEventNode->data.name) - 1] = '\0';

    strncpy(newEventNode->data.time, testData.time, sizeof(newEventNode->data.time) - 1);
    newEventNode->data.time[sizeof(newEventNode->data.time) - 1] = '\0';

    strncpy(newEventNode->data.place, testData.place, sizeof(newEventNode->data.place) - 1);
    newEventNode->data.place[sizeof(newEventNode->data.place) - 1] = '\0';

    newEventNode->data.joined = 0;
    newEventNode->next = NULL;

    // 寻找链表尾部并插入新节点
    if ((*event)->next == NULL) {
        // 如果链表为空，新节点就是链表的首元结点
        (*event)->next = newEventNode;
    } else {
        // 如果链表非空，遍历到链表尾部
        List_project temp = *event;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // 将新节点添加到链表尾部
        temp->next = newEventNode;
    }

    // 将新项目的名称复制到成绩链表节点
    strncpy(newGradeNode->event_name, newEventNode->data.name, sizeof(newGradeNode->event_name) - 1);
    newGradeNode->event_name[sizeof(newGradeNode->event_name) - 1] = '\0'; // 确保字符串以空字符结尾
    newGradeNode->head = NULL;                                             // 初始化成绩链表头节点为NULL
    newGradeNode->next = NULL;

    // 寻找成绩链表尾部并插入新节点
    if (*mark == NULL) {
        // 如果成绩链表为空，新节点就是链表的首元结点
        *mark = newGradeNode;
    } else {
        // 如果成绩链表非空，遍历到链表尾部
        List_grade tempGrade = *mark;
        while (tempGrade->next != NULL) {
            tempGrade = tempGrade->next;
        }
        tempGrade->next = newGradeNode; // 将新节点添加到链表尾部
    }
    return;
}

void ListInsert_huamn_auto(List_people *human)
{
    Humans humans[] = {
        {"李明", 202301, 1, 2, {{"篮球"}, {"排球"}}, "工学院"},
        {"王丽", 202302, 0, 1, {{"100m跑步"}}, "理学院"},
        {"张强", 202303, 1, 3, {{"篮球"}, {"跳高"}, {"跳远"}}, "文学院"},
        {"张心", 202304, 0, 2, {{"篮球"}, {"100m跑步"}}, "文学院"},
        {"王五", 202305, 1, 1, {{"排球"}}, "工学院"},
        {"周文", 202306, 0, 3, {{"100m跑步"}, {"足球"}, {"跳远"}}, "理学院"},
        {"赵云", 202307, 1, 3, {{"排球"}, {"跳高"}, {"跳远"}}, "工学院"},
    };

    int len = sizeof(humans) / sizeof(humans[0]);
    for (int i = 0; i < len; i++) {
        ListInsert_human_auto_backend(human, humans[i]);
    }
}

void ListInsert_human_auto_backend(List_people *human, Humans testData)
{
    // 创建新节点
    List_people newEventNode = (List_people)malloc(sizeof(List_Node1));
    if (newEventNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // 名字
    strncpy(newEventNode->data.name, testData.name, sizeof(newEventNode->data.name) - 1);
    newEventNode->data.name[sizeof(newEventNode->data.name) - 1] = '\0';

    // 学号
    newEventNode->data.ID = testData.ID;

    // 性别
    newEventNode->data.sex = testData.sex;

    // 学院
    strncpy(newEventNode->data.colleges, testData.colleges, sizeof(newEventNode->data.colleges) - 1);
    newEventNode->data.colleges[sizeof(newEventNode->data.colleges) - 1] = '\0';

    // 注册的比赛数目
    newEventNode->data.joined = testData.joined;

    // 比赛的默认成绩
    for (int i = 1; i <= newEventNode->data.joined; i++) {
        newEventNode->data.score[i] = 0;
    }

    newEventNode->data.sum = 0;

    // 参加的项目
    for (int i = 0; i < newEventNode->data.joined; i++) {
        strncpy(newEventNode->data.projects[i + 1].sp, testData.projects[i].sp, sizeof(newEventNode->data.projects[i].sp) - 1);
        newEventNode->data.projects[i + 1].sp[sizeof(newEventNode->data.projects[i].sp) - 1] = '\0';
    }

    newEventNode->next = NULL;

    // 寻找链表尾部并插入新节点
    if ((*human)->next == NULL) {
        // 如果链表为空，新节点就是链表的首元结点
        (*human)->next = newEventNode;
    } else {
        // 如果链表非空，遍历到链表尾部
        List_people temp = *human;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // 将新节点添加到链表尾部
        temp->next = newEventNode;
    }
}