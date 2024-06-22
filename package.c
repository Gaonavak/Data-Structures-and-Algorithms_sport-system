#include "package.h"
#include "Backstage_Settings.h"
#include "athletes.h"
#include "backup.h"
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void ShowMenu(int x, List_people *human, List_project *event, List_grade *mark,int flag)
{
    if (x == 0) {
        system("pause");
        system("cls");
        Show_athletes(human, event, mark);
        return;
    }
    if (x == 1) {
        system("pause");
        system("cls");
        Show_setings(human, event, mark);
        return;
    }
    if (x == 2) {
        system("pause");
        system("cls");
        Show_Results(human, event, mark);
        return;
    }
    if (x == 3) {
        system("pause");
        system("cls");
        printf("已成功退出系统！\n");
    }
    if (x == 8) {
        printf("你现在进行备份\n");
        writeEvent2Bak(*event);
        writeAthlete2Bak(*human);
        printf("备份完成\n");
        system("pause");
        system("cls");
        return;
    }
    if (x == 9) {
        if(flag==1){
            ListInsert_event_auto(event, mark);
            ListInsert_huamn_auto(human);
            system("pause");
            system("cls");
            return;
        }else{
            printf("当前已经进入了测试模式\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("你输入的是错误数字，请你重新输入一遍\n");
    system("pause");
    system("cls");
    return;
}