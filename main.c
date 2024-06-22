#include "Backstage_Settings.h"
#include "List.h"
#include "athletes.h"
#include "backup.h"
#include "package.h"
#include "test.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

// 数据变量
int a;              // 用于选择对应的功能界面
List_people human;  // 定义参赛人员
List_project event; // 定义项目
List_grade mark;    // 定义成绩
int flag=1;

int main()
{
    SetConsoleOutputCP(65001);
    printf("hello");
    printf("你好啊");
    human = (List_people)malloc(sizeof(List_Node1));
    event = (List_project)malloc(sizeof(List_Node2));
    mark = (List_grade)malloc(sizeof(List_Node3));
    human->next = NULL;
    event->next = NULL;
    mark->next = NULL;

    if (hasBak()) {
        char ch;
        scanf("%c", &ch);
        if (ch == 'y') {
            human = restoreAthlete();
            event = restoreEvent();
            restoreGrade(human,&mark,event);
        } else {
            system("cls");
        }
    }

    // 正式启用前，注意注释掉
    // printf("当前为测试模式\n");
    // ListInsert_event_auto(&event, &mark);
    // ListInsert_huamn_auto(&human);
    // 正式启用前，注意注释掉

    while (1) {
        printf("             !!欢迎使用校园运动管理系统!!\n");
        // 获取当前时间
        time_t current_time;
        time(&current_time);
        // 转换为本地时间格式并打印
        struct tm *time_info;
        time_info = localtime(&current_time);

        printf("           当前时间: %s", asctime(time_info));
        printf("#####################################################\n");
        if (event->next == NULL) {
            printf("##                      布告栏                     ##\n");
            printf("##                                                 ##\n");
        } else {
            put_event(event); // 当链表非空的时候将存在的项目输出
        }
        printf("#####################################################\n");
        printf("##            参赛报名0        后台设置1           ##\n");
        printf("##            成绩查询2        退出系统3           ##\n");
        printf("##            数据备份8        测试模式9           ##\n");
        printf("#####################################################\n");
        scanf("%d", &a);
        if (a == 3) {
            break;
        }
        ShowMenu(a, &human, &event, &mark,flag); // 调用 ShowMenu 函数
        if(a==9){flag=0;}
    }
    printf("已成功退出系统！\n");
    system("pause");
    return 0;
}
