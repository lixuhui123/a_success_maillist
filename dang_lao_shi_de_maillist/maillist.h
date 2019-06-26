#pragma once
enum menu
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	SORT,
	EMPTY,
	SHOW
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 100
#define TEL_SIZE 20
#define MAX 3
typedef struct student
{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char addr[ADDR_SIZE];
	char tel[TEL_SIZE];
}Student;
typedef struct MailList
{
	//Student data[MAX];
	Student *data;//在通信录里建立一个指向一条信息的结构体指针
	int capacity;//当前最大容量决定是多少就赋值多少
	int size;//对data指针进行地址偏移
}MailList;//指针引用指针是->,指针引用变量是.
int IncCapacity(MailList *ml);//传指针
void LoadData(MailList *ml);
void InitMailList(MailList *ml);
void AddInfo(MailList *ml);
void ShowInfo(MailList *ml);
void SortInfo(MailList *ml);
void SaveMailList(MailList *ml);
void DestoryMaillist(MailList *ml);
void SearchInfo(MailList *ml, char* find);
void SearchInfo(MailList* ml, char* find);
void DelInfo(MailList* ml);
void ModifyInfo(MailList* ml);
void showsearchdata(MailList* ml);
