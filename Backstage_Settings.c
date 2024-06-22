#include<stdio.h>
#include<stdlib.h>
#include "Backstage_Settings.h"



void  Show_setings(List_people* human,List_project* event,List_grade* mark){
    printf("#######################\n");
    printf("1.添加项目\n");
    printf("2.删除项目\n");
    printf("3.查看所有运动员的信息\n");
    printf("4.删除运动员信息\n");
    printf("5.登记运动员成绩\n");
    printf("6.退出当前界面\n");
    printf("#######################\n");
    printf("请输入你的选择：");
    char n; scanf("%s",&n);
    if(n=='6'){
        system("cls");  
        return;
        }
    Select_setings(n, human, event ,mark);
    system("cls");  
    return ;
}

void  Select_setings(char x,List_people* human,List_project* event,List_grade* mark){
    if(x=='1'){
        system("pause");
        system("cls");
        printf("#######################\n");
        ListInsert_event(event,mark);
        printf("录入成功\n");
        system("pause");
        system("cls");
        Show_setings(human,event,mark);
        return;
    }
    if(x=='2'){
        system("pause");        
        system("cls");
        printf("#######################\n");
        ListDelete_event(event,mark);
        system("pause");
        system("cls");        
        Show_setings(human,event,mark);    
        return;
    }
    if(x=='3'){
        system("pause");        
        system("cls");
        printf("#####################################################################\n");
        printf("                             参赛者名单\n");
        put_human(*human);
        printf("#####################################################################\n");
        system("pause");
        system("cls");
        Show_setings(human,event,mark); 
        return;
    }
    if(x=='4'){
        system("pause");        
        system("cls");
        printf("#######################\n");
        ListDelete_human(human);
        system("pause");
        system("cls");        
        Show_setings(human,event,mark);
        return;
    }
    if(x=='5'){
        system("pause");
        system("cls");
        printf("#######################\n");
        input_grade(human,mark);      
        system("pause");
        system("cls");        
        Show_setings(human,event,mark);
        return;
    }
    if(x=='6'){
        return;
    }
    printf("你输入的为错误的数字,请再输一遍:\n");
    system("pause");        
    system("cls");
    Show_setings(human,event,mark);
    return;
}