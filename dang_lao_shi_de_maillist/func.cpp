#include "maillist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int save[100] = { 0 };
int IncCapacity(MailList *ml)//mlָ�����ͨѶ¼��ͨѶ¼������Ϣ
{
	
	//��ͨѶ¼���ڴ�
	assert(ml != NULL);
	Student *temp = NULL;//����һ����Ϣ

	ml->capacity = ml->capacity + MAX;
	temp = (Student*)realloc(ml->data, sizeof(Student)*ml->capacity);
	/*data����Ϣ��ָ��
	��һ��Student�Ľṹ�壬���ǵ�ͨѶ¼ָ��dataָ������ṹ�壬һ��Student�ṹ�����ڴ���
	��ռ�Ŀռ���ȷ���ģ����ԾͿ�����ȡƫ�����ķ�ʽ���з��ʣ����ı�data��ָ��*/
	if (temp != NULL)
	{
		ml->data = temp;
		return 0;
	}
	return 1;
}
void LoadData(MailList *ml)
{
	//������Ϣ
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
	memset(ml->data, 0, MAX * sizeof(Student));//mi.data��һ�� ָ��
	LoadData(ml);

}

void AddInfo(MailList *ml)
{
	assert(ml != NULL);
	/*if (ml->size >= MAX)
	{
		printf("ͨѶ¼�������ܲ���\n");
		return;
	}*/
	if (ml->size >= ml->capacity && IncCapacity(ml))
	{
		//����ط��жϵ����ȼ������߼��룬�����������Ƕ�·��ֵ����
		//��һ����0��ڶ������ʽ�Ͳ����㣬���Բ���ÿ�ζ����ٿռ� 
		//ֻ�е�ǰ����1��ʱ��ŻῪ�ٿռ�
		printf("ͨѶ¼�������ܲ���\n");
		return;
	}
	printf("���������� �Ա� ���� סַ �绰\n");
	scanf("%s", ml->data[ml->size].name);//��һ�����飬���־��ǵ�ַ
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);
	scanf("%s", ml->data[ml->size].tel);
	scanf("%s", ml->data[ml->size].addr);

	++ml->size;
}
void ShowInfo(MailList *ml)
{
	assert(ml != NULL);
	printf("%3s %9s %11s %10s %9s %14s", "���","����", "�Ա�", "����", "�绰", "סַ\n");
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
			if (strcmp(ml->data[j].name, ml->data[j + 1].name) > 0)//strcmp�ĶԱȷ�ʽ�������ĵ�һ���ַ���ʼ�Ա�
				//ֱ���ҵ���ͬ����ַ�����
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
	//data��ָ��student�ṹ���ָ�밡����

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
		printf("���ҵ�%d����Ϣ\n", save[0]);
		printf("%3s %10s %9s %5s %10s %12s", "���","����", "�Ա�", "����", "�绰", "סַ\n");
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
		printf("�ҵ�0����Ϣ\n");
	}

}
void SearchInfo(MailList* ml,char* find)
{
	
	char *ret;
	char age[4] = "0";
	//sprintf(age,"%d",g_allMsg[i].age)������ֵ��strlen()
	//scanf()���÷�
	//sprintf()��ctrcpy��ʲô����
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
			sprintf(age, "%d", ml->data[i].age);//������ת�����ַ�����
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
		} while (0);//goto�Ľ������do while(0)
		if (flag)
		{
			/*printf("%15s %5s %3s %10s %12s", "����", "�Ա�", "����", "�绰", "סַ\n");
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
		printf("�ҵ�0����Ϣ\n");
	}*/

	showsearchdata(ml);
	
}
 
void DelInfo(MailList* ml)
{
	int i = 0;
	char del[25] = "0";
	int bianhao = 0;
	printf("������Ҫɾ������Ϣ\n");
	scanf("%s", &del);
	SearchInfo(ml, del);

	printf("��ѡ��ɾ������ϵ�˱��\n");
	scanf("%d", &bianhao);
    for (i=bianhao;i<ml->size;++i)
    {
    	ml->data[i] = ml->data[i+1];
    }
	ml->size--;
	printf("ɾ���ɹ�\n");
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
	printf("��ѡ��Ҫ�޸ĵ���Ϣ��Ӧ�ı��\n");
	scanf("%d", &bianhao);
	printf("������Ҫ�޸ĵ���Ϣ����\n");
	printf("1.���� 2.�绰 3.סַ\n");
	scanf("%d", &leixing);
	printf("������Ҫ���µ���Ϣ\n");
	scanf("%s", &del);
	/*printf("������\n");
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
printf("�޸ĳɹ�\n");
}