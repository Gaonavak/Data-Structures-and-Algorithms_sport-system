#ifndef List_H
#define List_H


//定义运动员的信息以及形成对应的链表
typedef struct {
    char sp[100];
}Project_people;
typedef struct {
    char name[100];//姓名
    int ID;//学号
    int sex;//1为男生，0为女生
    int joined;//注册比赛的数目
    Project_people projects[4]; // 参加的项目
    int score[4];//个人得分
    int sum;//个人总得分
    char colleges[100];//学院
}people;
typedef struct node1
{
   people data;
   struct node1* next;
}List_Node1;
typedef List_Node1 *List_people;

//定义项目的信息以及形成对应的链表
typedef struct{
    char name[100];   // 项目名
    char time[100];   // 举办时间
    char place[100];  // 出场地方
    int joined;      // 已参加的人数
}Project_event;
typedef struct node2{
    Project_event data;
    struct node2* next;
}List_Node2;
typedef List_Node2 *List_project;

// 定义单个成绩条目,定义一个项目的成绩链表
typedef struct {
    int ID;          // 学号
    int score;       // 分数
}Project_grade;
typedef struct node{
    Project_grade entry; // 成绩条目
    struct node* next; // 指向下一个节点
} grade;
typedef struct node3{
    char event_name[100]; // 比赛项目名称
    grade* head;     // 指向成绩链表的头节点
    struct node3 *next;  // 指向下一个比赛项目的指针
} List_Node3;
typedef List_Node3 *List_grade;


//定义学院的结构体
typedef struct {
    char name[100]; // 学院名
    int totalScore; // 该学院的总分
} CollegeScore;


//后台设置
void put_event(List_project event);//查看所有的项目
void ListInsert_event(List_project* event,List_grade* mark);//添加项目
void ListDelete_event(List_project* event,List_grade* mark);//在删除第i位置的项目
void ListDelete_human(List_people *human);//在删除第i位置的人物
void put_human(List_people human);//输出所有人物的信息;
void input_grade(List_people *human,List_grade *mark);//登记人物的成绩

//参赛报名
void ListInsert_human(List_people *human);//添加人物
void search_human(List_people human);//查看自己的个人信息

//成绩查询
void Result_event(List_grade *mark);//查询项目排名
void Result_college(List_people *human);//查询学院排名
void swap(Project_grade *a, Project_grade *b);// 定义一个用于交换两个成绩节点的函数 
void sort(grade *head);// 定义一个对成绩链表进行排序的函数（冒泡排序）
void print_grades(grade* head);// 定义一个用于打印成绩链表的函数
int find_college_index(CollegeScore colleges[], const char *name, int count);
//在给定的CollegesScore数组中查找特定名称的大学，并返回其索引

#endif 
