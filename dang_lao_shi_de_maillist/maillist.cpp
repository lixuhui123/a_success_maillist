#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "maillist.h"
//func.c
void menu()
{
	printf("******************************\n");
	printf("**** 1.add      2.del     ****\n");
	printf("**** 3.modify   4.search  ****\n");
	printf("**** 5.sort     6.empty   ****\n");
	printf("**** 7.show     0.exit    ****\n");
	printf("******************************\n");

}


void Test()

{
	int input = 0;
	MailList ml;//����һ��ͨѶ¼
	char find[20]="0";
	InitMailList(&ml);//����ַ������ֱ�ӽ��в���
	while (1)
	{
		menu();
		printf("������Ҫʵ�ֵĹ���\n");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			DestoryMaillist(&ml);
			printf("�˳���\n");
			return;
		case ADD:
			AddInfo(&ml);
			break;
		case DEL:
			DelInfo(&ml);
			//ɾ��
			break;
		case MODIFY:
			ModifyInfo(&ml);
			//�޸�
			break;
		case SEARCH:
			printf("������Ҫ���ҵ��ַ��������ַ���\n");
			scanf("%s", &find);
			SearchInfo(&ml,find);
			break;
		case SORT:
			SortInfo(&ml);
			break;
		case EMPTY:
			//EmptyInfo(&ml);
			break;
		case SHOW:
			ShowInfo(&ml);
			break;
		default:
			printf("�����֧������,����������\n");
		}
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}