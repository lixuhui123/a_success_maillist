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
	Student *data;//��ͨ��¼�ｨ��һ��ָ��һ����Ϣ�Ľṹ��ָ��
	int capacity;//��ǰ������������Ƕ��پ͸�ֵ����
	int size;//��dataָ����е�ַƫ��
}MailList;//ָ������ָ����->,ָ�����ñ�����.
int IncCapacity(MailList *ml);//��ָ��
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
