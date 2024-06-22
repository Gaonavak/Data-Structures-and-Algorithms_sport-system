#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void put_event(List_project event)
{
    List_project temp = event;
    temp = temp->next;
    printf("%-28s%-25s%s\n", "时间", "项目", "地点");
    while (temp != NULL) {
        printf("%-26s%-25s%s\n", temp->data.time, temp->data.name, temp->data.place);
        temp = temp->next;
    }
}
void ListInsert_event(List_project *event, List_grade *mark)
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
    // 输入新项目数据
    printf("请输入项目名：");
    scanf(" %99[^\n]", newEventNode->data.name); // 注意加上空格，以消耗掉之前的换行符

    printf("请输入举办时间：");
    scanf(" %99[^\n]", newEventNode->data.time); // 注意加上空格，以消耗掉之前的换行符

    printf("请输入举办场所：");
    scanf(" %99[^\n]", newEventNode->data.place); // 注意加上空格，以消耗掉之前的换行符

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
    if ((*mark)->next == NULL) {
        // 如果成绩链表为空，新节点就是链表的首元结点
        (*mark)->next = newGradeNode;
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
void ListDelete_event(List_project *event, List_grade *mark)
{
     if ((*event)->next == NULL) {
        printf("项目列表为空\n");
        return;
    }
    List_project h=*event;
    h=h->next;//跳过当前的头结点
    int i=1;
    while(h!=NULL){
        printf("%d. %s\n",i++,h->data.name);
        h=h->next;
    }
    printf("请您输入要删除的项目编号:");
    int n, k = 1; // 项目编号从1开始
    scanf("%d", &n);
    if (n < 1) {
        printf("编号必须大于等于1。\n");
        return;
    }
    List_project p = *event; // 使用event指向的头指针开始
    List_project q = NULL;   // 用于保存要删除的节点
    List_grade p1 = *mark;
    List_grade q1 = NULL;
    while (p->next != NULL && k < n - 1) {
        p = p->next;
        p1 = p1->next;
        k++;
    }
    // 检查是否存在要删除的节点
    if (p->next == NULL) {
        printf("没有该编号的项目。\n");
        return;
    }
    // 删除节点
    q = p->next; // q指向要删除的节点
    q1 = p1->next;
    p->next = q->next; // 将q的下一个节点链接到p上
    p1->next = q1->next;
    free(q); // 释放q节点的内存
    free(q1);
    printf("删除成功\n");
    return;
}
void ListInsert_human(List_people *human)
{
    // 创建新节点
    List_people newEventNode = (List_people)malloc(sizeof(List_Node1));
    if (newEventNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // 输入用户数据
    printf("请输入学院：");
    scanf(" %99[^\n]", newEventNode->data.colleges); // 注意加上空格，以消耗掉之前的换行符

    printf("请输入姓名：");
    scanf(" %99[^\n]", newEventNode->data.name); // 注意加上空格，以消耗掉之前的换行符

    printf("请输入性别(男为1,女为0):");
    scanf("%d", &(newEventNode->data.sex)); // 使用 & 来获取整数字段的地址
    getchar();                              // 读取并丢弃换行符

    printf("请输入学号:");
    scanf("%d", &(newEventNode->data.ID)); // 使用 & 来获取整数字段的地址
    getchar();                             // 读取并丢弃换行符

    printf("请输入打算注册比赛的数目(限3个):");
    scanf("%d", &(newEventNode->data.joined)); // 使用 & 来获取整数字段的地址
    getchar();                                 // 读取并丢弃换行符

    printf("请输入参加的项目:");
    int num = 1;
    while (num <= newEventNode->data.joined) {
        scanf(" %99s", newEventNode->data.projects[num].sp); // 注意加上空格，以消耗掉之前的换行符
        num++;
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
    return;
}
void put_human(List_people human)
{
    List_people temp = human;
    temp = temp->next;
    if (temp == NULL) {
        printf("当前无参赛人员\n");
        return;
    }
    printf("学院         学号        姓名        性别(男为1,女为0)        参加的项目             \n");
    while (temp != NULL) {
        printf("%-12s%-15d%-20s%-15d", temp->data.colleges, temp->data.ID, temp->data.name, temp->data.sex);
        int n = 1;
        while (n <= temp->data.joined) {
            printf("%s ", temp->data.projects[n].sp);
            n++;
        }
        printf("\n");
        temp = temp->next;
    }
    return;
}
void ListDelete_human(List_people *human)
{
    if ((*human)->next == NULL) {
        printf("参赛人员为空\n");
        return;
    }
    printf("请您输入要删除的运动员学号:");
    int n; // 项目编号从1开始
    scanf("%d", &n);
    List_people p = *human; // 使用event指向的头指针开始
    List_people q = NULL;   // 用于保存要删除的节点
    while (p->next != NULL && p->next->data.ID != n) {
        p = p->next;
    }
    // 检查是否存在要删除的节点
    if (p->next == NULL) {
        printf("没有该学号的运动员。n");
        return;
    }
    // 删除节点
    q = p->next;       // q指向要删除的节点
    p->next = q->next; // 将q的下一个节点链接到p上
    free(q);           // 释放q节点的内存
    printf("删除成功\n");
    return;
}
void search_human(List_people human)
{
    List_people temp = human;
    temp = temp->next; // 跳过头节点
    if (temp == NULL) {
        printf("当前无参赛人员\n");
        return;
    }
    printf("请输入您的学号:");
    int n;
    scanf("%d", &n);
    while (temp != NULL && temp->data.ID != n) {
        temp = temp->next;
    }
    if (temp == NULL) { // 检查是否存在该运动员
        printf("没有该学号的运动员。\n");
        return;
    }
    printf("学院               学号               姓名               性别(男为1,女为0)                参加的项目\n");
    printf("%-15s%-15d%-15s%-15d", temp->data.colleges, temp->data.ID, temp->data.name, temp->data.sex);
    int k = 1;
    while (k <= temp->data.joined) {
        printf("%s ", temp->data.projects[k].sp);
        k++;
    }
    printf("\n");
    return;
}
void input_grade(List_people *human, List_grade *mark)
{
    List_people temp = *human;
    temp = temp->next; // 跳过头节点
    if (temp == NULL) {
        printf("当前无参赛人员\n");
        return;
    }
    printf("请输入你要登记的运动员学号:");
    int n;
    scanf("%d", &n);
    while (temp != NULL && temp->data.ID != n) {
        temp = temp->next;
    }
    if (temp == NULL) { // 检查是否存在该运动员
        printf("没有该学号的运动员。n");
        return;
    }
    int k = 1;
    temp->data.sum = 0;
    while (k <= temp->data.joined) {
        printf("请输入运动员在%s项目的分数:", temp->data.projects[k].sp);
        int score;
        scanf("%d", &score);
        temp->data.score[k] = score; // 存储分数到运动员信息中
        temp->data.sum += score;
        // 在mark链表中找到对应的项目，并添加成绩
        List_grade current_mark = *mark;
        current_mark = current_mark->next; // 跳过头节点
        while (current_mark != NULL) {
            if (strcmp(current_mark->event_name, temp->data.projects[k].sp) == 0) {
                // 找到对应项目，添加成绩
                grade *new_grade = (grade *)malloc(sizeof(grade));
                if (new_grade == NULL) {
                    printf("内存分配失败。n");
                    return;
                }
                new_grade->entry.ID = n;
                new_grade->entry.score = score;
                // 将新成绩节点插入到对应项目的成绩链表头部
                new_grade->next = current_mark->head;
                current_mark->head = new_grade;
                break; // 添加完成绩后退出循环
            }
            current_mark = current_mark->next;
        }
        k++;
    }
    printf("录入成功\n");
    return;
}
void swap(Project_grade *a, Project_grade *b)
{
    Project_grade temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void sort(grade *head)
{
    int swapped;
    grade *current;
    grade *last = NULL;
    if (head == NULL) {
        return; // 链表为空，直接返回
    }
    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->entry.score < current->next->entry.score) {
                swap(&(current->entry), &(current->next->entry)); // 交换成绩
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    return;
}
void print_grades(grade *head)
{
    while (head != NULL) {
        printf("学号：%d, 分数：%d\n", head->entry.ID, head->entry.score);
        head = head->next;
    }
    return;
}
void Result_event(List_grade *mark)
{
    List_grade p = *mark;
    if(p->next==NULL){
        printf("当前的项目为空。\n");
        return;
    }
    p=p->next;//跳过当前的头节点
    int i=1;
    while(p!=NULL){
        printf("%d.%s\n",i++,p->event_name);
        p=p->next;
    }
    printf("请选择你要查询的项目排名：");
    char str[100];
    scanf(" %99s", str); // 防止输入过长的字符串

    // 在mark链表中找到对应的项目
    List_grade current_mark = *mark;
    while (current_mark != NULL && strcmp(current_mark->event_name, str) != 0) {
        current_mark = current_mark->next;
    }

    if (current_mark) {
        // 找到项目, 对该项目的成绩链表进行排序
        sort(current_mark->head);

        // 打印排序后的成绩
        printf("项目：%s 的排名结果如下:\n", str);
        print_grades(current_mark->head);
    } else {
        printf("没有找到项目：%s。\n", str);
    }
    return;
}
int find_college_index(CollegeScore colleges[], const char *name, int count)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(colleges[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
void Result_college(List_people *human)
{
    CollegeScore colleges[100]; // 假设最多有100个学院
    int collegeCount = 0;
    // 遍历链表，累加个人总分到相应的学院中
    List_people temp = *human;
    temp = temp->next; // 跳过头结点
    if (temp == NULL) {
        printf("当前没有单位进行比赛。\n");
        return;
    }
    while (temp != NULL) {
        int index = find_college_index(colleges, temp->data.colleges, collegeCount);
        if (index == -1) {
            // 新学院，添加到数组中
            strcpy(colleges[collegeCount].name, temp->data.colleges);
            colleges[collegeCount].totalScore = temp->data.sum;
            collegeCount++;
        } else {
            // 已有学院，累加总得分
            colleges[index].totalScore += temp->data.sum;
        }
        temp = temp->next;
    }

    // 使用冒泡排序对学院总得分进行排序
    for (int i = 0; i < collegeCount - 1; i++) {
        for (int j = 0; j < collegeCount - i - 1; j++) {
            if (colleges[j].totalScore < colleges[j + 1].totalScore) {
                // 交换位置
                CollegeScore temp = colleges[j];
                colleges[j] = colleges[j + 1];
                colleges[j + 1] = temp;
            }
        }
    }

    // 输出学院排名和总得分
    for (int i = 0; i < collegeCount; i++) {
        printf("排名%d: 学院：%s,总分:%d\n", i + 1, colleges[i].name, colleges[i].totalScore);
    }
    return;
}