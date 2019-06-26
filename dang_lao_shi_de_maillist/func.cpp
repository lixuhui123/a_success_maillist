#include "maillist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int save[100] = { 0 };
int IncCapacity(MailList *ml)//ml指向的是通讯录，通讯录里有消息
{
	
	//给通讯录开内存
	assert(ml != NULL);
	Student *temp = NULL;//这是一条信息

	ml->capacity = ml->capacity + MAX;
	temp = (Student*)realloc(ml->data, sizeof(Student)*ml->capacity);
	/*data是消息的指针
	有一个Student的结构体，我们的通讯录指针data指向这个结构体，一个Student结构体在内存中
	所占的空间是确定的，所以就可以用取偏移量的方式进行访问，来改变data的指向*/
	if (temp != NULL)
	{
		ml->data = temp;
		return 0;
	}
	return 1;
}
void LoadData(MailList *ml)
{
	//加载信息
	//int i = 0;
	FILE *rp = fopen("F:\\bite learn\\MailList.txt", "rb");

	while (fread(&ml->data[ml->size], sizeof(Student), 1, rp))
	{
		ml->size++;
		if (ml->size >= ml->capacity)
		{
			IncCapacity(ml);
		}

	}
	fclose(rp);
	rp = NULL;
}
void InitMailList(MailList *ml)
{
	assert(ml != NULL);
	ml->capacity = MAX;
	ml->size = 0;
	ml->data = (Student*)malloc(sizeof(Student)*ml->capacity);
	memset(ml->data, 0, MAX * sizeof(Student));//mi.data是一个 指针
	LoadData(ml);

}

void AddInfo(MailList *ml)
{
	assert(ml != NULL);
	/*if (ml->size >= MAX)
	{
		printf("通讯录已满不能插入\n");
		return;
	}*/
	if (ml->size >= ml->capacity && IncCapacity(ml))
	{
		//这个地方判断的优先级高于逻辑与，而且与运算是短路求值问题
		//第一个是0后第二个表达式就不计算，所以不会每次都开辟空间 
		//只有当前面是1的时候才会开辟空间
		printf("通讯录已满不能插入\n");
		return;
	}
	printf("请输入姓名 性别 年龄 住址 电话\n");
	scanf("%s", ml->data[ml->size].name);//是一个数组，名字就是地址
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].tel);
	scanf("%s", ml->data[ml->size].addr);

	++ml->size;
}
void ShowInfo(MailList *ml)
{
	assert(ml != NULL);
	printf("%3s %9s %11s %10s %9s %14s", "编号","姓名", "性别", "年龄", "电话", "住址\n");
	int i = 0;
	for (i = 0; i < ml->size; ++i)
	{
		printf("%d ", i);
	     printf("%12s", ml->data[i].name);
	     printf("%12s", ml->data[i].sex);
	     printf("%9d", ml->data[i].age);
	     printf("%12s", ml->data[i].tel);
	     printf("%12s\n", ml->data[i].addr);
	}
}
void SortInfo(MailList *ml)
{
	assert(ml != NULL);

	int i = 0;
	int j = 0;
	Student tmp;
	for (i = 0; i < ml->size; ++i)
	{
		for (j = 0; j < ml->size - i - 1; ++j)
		{
			if (strcmp(ml->data[j].name, ml->data[j + 1].name) > 0)//strcmp的对比方式是两个的第一个字符开始对比
				//直到找到不同大的字符返回
			{
				tmp = ml->data[j];
				ml->data[j] = ml->data[j + 1];
				ml->data[j + 1] = tmp;
			}
		}
	}
}
void SaveMailList(MailList *ml)
{
	int i = 0;
	FILE *fp = fopen("F:\\bite learn\\MailList.txt", "wb");
	for (i = 0; i < ml->size; ++i)
	{
		fwrite(&ml->data[i], sizeof(Student), 1, fp);
	}
	//data是指向student结构体的指针啊哈哈

	fclose(fp);
	fp = NULL;
}
void DestoryMaillist(MailList *ml)
{
	assert(ml != NULL);
	SaveMailList(ml);
	free(ml->data);
	ml->data = NULL;
	ml->capacity = ml->size = NULL;

}
void showsearchdata(MailList* ml)
{
	if (save[0])
	{
		printf("共找到%d条信息\n", save[0]);
		printf("%3s %10s %9s %5s %10s %12s", "编号","姓名", "性别", "年龄", "电话", "住址\n");
		int i = 0;
		for (i = 1; i <= save[0]; ++i)
		{
			printf("%d ", save[i]);
			printf("%15s", ml->data[save[i]].name);
			printf("%5s", ml->data[save[i]].sex);
			printf("%7d", ml->data[save[i]].age);
			printf("%10s", ml->data[save[i]].tel);
			printf("%12s\n", ml->data[save[i]].addr);
		}
	}
	else
	{
		printf("找到0条信息\n");
	}

}
void SearchInfo(MailList* ml,char* find)
{
	
	char *ret;
	char age[4] = "0";
	//sprintf(age,"%d",g_allMsg[i].age)；返回值是strlen()
	//scanf()的用法
	//sprintf()和ctrcpy有什么区别？
	int i=0;
	int j = 1;
	int flag = 0;
	int count = 0;
	/*for (;j<100;++j)
	{
		save[j] = 0;
	}*/
	for (i = 0; i < ml->size; ++i)
	{
		/*printf("%d", ml->size);
		printf("%s", find);*/
		flag = 1;
		do
		{
			ret = strstr(ml->data[i].name, find);
			if (ret)
			{
				++count;
				break;
			}
			ret = strstr(ml->data[i].addr, find);
			if (ret)
			{
				++count;
				break;
			}
			ret = strstr(ml->data[i].sex, find);
			if (ret)
			{
				++count;
				break;
			}
			sprintf(age, "%d", ml->data[i].age);//把数字转化成字符串了
			ret = strstr(age, find);
			if (ret)
			{
				++count;
				break;
			}
			ret = strstr(ml->data[i].tel, find);
			if (ret)
			{ 
				++count;
				break;
			}
			flag = 0;
		} while (0);//goto的解决方案do while(0)
		if (flag)
		{
			/*printf("%15s %5s %3s %10s %12s", "姓名", "性别", "年龄", "电话", "住址\n");
			printf("%15s", ml->data[i].name);
			printf("%5s", ml->data[i].sex);
			printf("%3d", ml->data[i].age);
			printf("%10s", ml->data[i].tel);
			printf("%12s\n", ml->data[i].addr);*/
			/*FILE *fp = fopen("F:\\bite learn\\SavaSearchData.txt", "wb");
			fwrite(&ml->data[i], sizeof(Student), 1, fp);
			FILE *rp = fopen("F:\\bite learn\\SavaSearchData.txt", "rb");
			fread(save, sizeof(Student), 1, rp);
			fclose(fp);
			fp = NULL;*/
			save[j] = i;
			++j;
		}
	}
	if (count)
	{
		 
		save[0] = count;
	}
	/*else
	{
		printf("找到0条信息\n");
	}*/

	showsearchdata(ml);
	
}
 
void DelInfo(MailList* ml)
{
	int i = 0;
	char del[25] = "0";
	int bianhao = 0;
	printf("请输入要删除的信息\n");
	scanf("%s", &del);
	SearchInfo(ml, del);

	printf("请选择删除的联系人编号\n");
	scanf("%d", &bianhao);
    for (i=bianhao;i<ml->size;++i)
    {
    	ml->data[i] = ml->data[i+1];
    }
	ml->size--;
	printf("删除成功\n");
}
//void ModifyoneInfo(MailList* ml, int bianhao, int leixing)
//{
//
//}
void ModifyInfo(MailList* ml)
{
	int leixing = 0;
	char del[25] = "0";
	int bianhao = 0;
	ShowInfo(ml);
	printf("请选择要修改的信息对应的编号\n");
	scanf("%d", &bianhao);
	printf("请输入要修改的信息类型\n");
	printf("1.姓名 2.电话 3.住址\n");
	scanf("%d", &leixing);
	printf("请输入要更新的信息\n");
	scanf("%s", &del);
	/*printf("请输入\n");
	scanf("%s", &del);*/
	//SearchInfo(ml, del);
	
if (1==leixing)
{
	strcpy(ml->data[bianhao].name, del);
} 
else if(2== leixing)
{
	strcpy(ml->data[bianhao].tel, del);
}
else if(3== leixing)
{
	strcpy(ml->data[bianhao].addr, del);
}
printf("修改成功\n");
}