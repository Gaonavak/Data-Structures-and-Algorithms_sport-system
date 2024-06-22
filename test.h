#ifndef TEST_C
#define TEST_C
#include "List.h"

typedef struct events {
    char name[100];  // 项目名
    char time[100];  // 举办时间
    char place[100]; // 出场地方
} Events;

typedef struct humans {
    char name[100];             // 姓名
    int ID;                     // 学号
    int sex;                    // 1为男生，0为女生
    int joined;                 // 注册比赛的数目
    Project_people projects[4]; // 参加的项目
    char colleges[100];         // 学院
} Humans;


void ListInsert_event_auto(List_project *event, List_grade *mark);
void ListInsert_huamn_auto(List_people *human);
void ListInsert_event_auto_backend(List_project *event, List_grade *mark, Events testData);
void ListInsert_human_auto_backend(List_people *human, Humans testData);

#endif