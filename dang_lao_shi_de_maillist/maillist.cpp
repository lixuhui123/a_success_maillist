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
	MailList ml;//定义一个通讯录
	char find[20]="0";
	InitMailList(&ml);//传地址，对它直接进行操作
	while (1)
	{
		menu();
		printf("请输入要实现的功能\n");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			DestoryMaillist(&ml);
			printf("退出！\n");
			return;
		case ADD:
			AddInfo(&ml);
			break;
		case DEL:
			DelInfo(&ml);
			//删除
			break;
		case MODIFY:
			ModifyInfo(&ml);
			//修改
			break;
		case SEARCH:
			printf("请输入要查找的字符串或者字符串\n");
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
			printf("输入分支不存在,请重新输入\n");
		}
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}