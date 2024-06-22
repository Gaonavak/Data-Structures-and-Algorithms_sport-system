#include<stdio.h>
#include<stdlib.h>
#include "Results.h"

void  Show_Results(List_people *human,List_project *event,List_grade *mark){
    printf("#######################\n");
    printf("1.查询项目排名\n");
    printf("2.查询学院总排名\n");
    printf("3.退出当前界面\n");
    printf("#######################\n");
    printf("请输入你的选择：");
    char n;scanf("%s",&n);
    if(n=='3'){
        system("cls");  
        return;
    }
    Select_Results(n, human, event ,mark);
    system("cls");  
    return ;
}
void Select_Results(char x,List_people* human,List_project* event,List_grade* mark){
    if(x=='1'){
        system("pause");
        system("cls");
        printf("#######################\n");
        Result_event(mark);
        system("pause");
        system("cls");
        Show_Results(human,event,mark);
        return;
    }
    if(x=='2'){
        system("pause");
        system("cls");
        printf("#######################\n");
        Result_college(human);
        system("pause");
        system("cls");
        Show_Results(human,event,mark);
        return;
    }
    if(x=='3'){
        return;
    }
    printf("你输入的为错误的数字,请再输一遍。\n");
    system("pause");        
    system("cls");
    Show_Results(human,event,mark);
    return;
}