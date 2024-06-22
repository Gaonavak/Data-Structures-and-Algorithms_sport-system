#include<stdio.h>
#include<stdlib.h>
#include "athletes.h"



void Show_athletes( List_people* human, List_project* event,List_grade* mark){
    printf("#######################\n");
    printf("1.添加个人信息\n");
    printf("2.查看个人信息\n");
    printf("3.退出当前界面\n");
    printf("#######################\n");
    printf("请输入你的选择：");
    char n;scanf("%s",&n);
    if(n=='3'){
        system("cls");  
        return;
    }
    Select_athletes(n, human, event ,mark);
    system("cls");  
    return ;
}

void  Select_athletes(char x,List_people* human,List_project* event,List_grade* mark){
    if(x=='1'){
        system("pause");
        system("cls");
        printf("#######################\n");
        ListInsert_human(human);
        printf("录入成功\n");
        system("pause");
        system("cls");
        Show_athletes(human,event,mark);
        return;
    }
    if(x=='2'){
        system("pause");        
        system("cls");
        printf("#####################################################################\n");
        search_human(*human);
        printf("#####################################################################\n");
        system("pause");
        system("cls");
        Show_athletes(human,event,mark);            
        return;
    }
    if(x=='3'){
        return;
    }
    printf("你输入的为错误的数字,请再输一遍.\n");
    system("pause");        
    system("cls");
    Show_athletes(human,event,mark);
    return;
}