#define NULL 0
#define OK 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
typedef struct text
{
 char string[80];//�洢ÿһ�е�Ԫ��
 struct text *next;//ָ���һ���ڵ��ָ��
 struct text *pre;//ָ��ǰһ���ڵ��ָ��
 int num;//ÿһ��Ԫ�صĳ���
 int flat;//ȷ�������Ƿ�ɾ���ı�־
}text;
FILE *fp,*out;//fp��ִ�б��򿪵��ļ���outָ��д����ļ�
text *head;//�����ͷָ��
int sum,delnum,xiugai=0,page=0;
//file://�޸�����ָʾ�ļ��Ƿ��޸Ĺ�������޸Ĺ��Żش��̡�page����������ʾ��
//file://ҳ��.delnum�����洢��ɾ�����ֽ�����sum�洢һҳ�����ֽ���

void byebye()//û�о����ô���ֻ��д����ģ�����Ļ����ʾһ��bye
{
 puts("\t\t\t********    *       *   ********");
 puts("\t\t\t*       *    *     *    *  ");
 puts("\t\t\t*       *     *   *     *  ");
 puts("\t\t\t*      *       * *      *  ");
 puts("\t\t\t********        *       ********");
 puts("\t\t\t*      *        *       *  ");
 puts("\t\t\t*       *       *       *  ");
 puts("\t\t\t*       *       *       *  ");
 puts("\t\t\t********        *       ********");

}


void HELP()//������������ʾһЩ����ĸ�ʽ
{
 printf("\n\t**********************************************************\n");
 printf("\t**  ���ļ���  o<�к�><�ļ���><�س�>  **\n");
 printf("\t**  �в����ʽ�� i<�к�><�س�><�ı�><�س�> **\n");
 printf("\t**  ��ɾ����ʽ�� d<�к�1>[<�ո�><�к�2>]<�س�> **\n");
 printf("\t**  �����л���ʽ�� n<�س�>    **\n");
 printf("\t**  ������ʾ��ʽ�� p<�س�>    **\n");
 printf("\t**  ע�⣺��ִ����������ǰ��������o������ļ����� **\n");
 printf("\t**  ��p������ʾ����������    **\n");
 printf("\t**********************************************************\n");
 system("pause");
 printf("\n\n\n");
 
}

 

void ABOUT()//Ҳ��д�����
{
 printf("\n\t\t*****************************************\n");
 printf("\t\t** welcome to the program                **\n");
 printf("\t\t** all work and no play make jack adull boy **\n");
 printf("\t\t** enjoy your work                         **\n");
 printf("\t\t*****************************************\n");
 system("pause");
 system("cls");
 printf("\n\n\n");
}

void Createlist()//����һ��ʮ���ڵ���������ı��е�һҳ
{
	text *p1, *p2;
	int n = 0;

	p1 = p2 = (text *)malloc(sizeof(text));
	p1->string[0] = '\0';
	head = NULL;
	while (n<10)
	{
		if (n == 0)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
			p1->pre = p2;
			p1->flat = 0;
		}
		p2 = p1;
		p1 = (text *)malloc(sizeof(text));
		p1->string[0] = '\0';
		++n;
	}
	p2->next = NULL;
}

void freemem()//�ͷ�������ռ���ڴ�
{
	text *p;
	text * temp;
	for (p = head; head != NULL;)
	{
		head = p->next;
		free(p);
		p = head;
	}
	
}


int Openfiles()//���ļ��ĺ���
{
	char name[30], outname[30];
	puts("������Ҫ�򿪵��ļ�����");
	scanf("%s", name);
	if ((fp = fopen(name, "r+")) == NULL)
	{
		printf("�򲻿�ԭ�ļ��� \n");
		exit(0);
	}
	puts("������Ҫд����ļ�����");
	scanf("%s", outname);
	if ((out = fopen(outname, "w+")) == NULL)
	{
		printf("�򲻿�Ŀ���ļ���\n");
		exit(0);
	}
	return 0;
}


int display()//���ļ��ж��뵽�����У�����ʾ����
{
	int i;
	char conti = 'y';
	text *p;
	while ((!feof(fp)) && (conti == 'y' || conti == 'Y'))
	{
		page++;
		printf("\t\t��%dҳ\n", page);
		for (i = 0, p = head, sum = 0; (i<10) && (!feof(fp)); i++, p = p->next)
		{
			fgets(p->string, sizeof(p->string), fp);
			puts(p->string);
			p->flat = 1;
			p->num = strlen(p->string);
			sum = sum + p->num;
		}
		puts("Continue?(Y/N):");
		conti = getche();
		if (feof(fp))
		{
			puts("\n�ļ��Ѿ�����!");
			return 0;
		}
	}
	return 0;
}


int saveanddisplay(int hang)//����nִ�еĺ�����������������������ʾ��������һҳ����
{
	int i, endflat = 0;
	char conti = 'y';
	text *p = NULL;
	page++;
	for (i = 0, p = head; i<hang&&p!=NULL; i++, p = p->next) //file://������д���ļ�//---------!-----------
		if (p->flat == 1)
		{

			fputs(p->string, out);
			p->flat = 0;
		}
	if (!feof(fp))
		printf("\t\t��%dҳ\n", page);
	for (i = 0, p = head, sum = 0; (i<10) && (!feof(fp)); i++, p = p->next)//���ļ��������
		if (fgets(p->string, sizeof(p->string), fp))
		{
			puts(p->string);
			p->flat = 1;
			p->num = strlen(p->string);
			sum = sum + p->num;
		}
	if (feof(fp))
		printf("�ļ��Ѿ�������");
	return 0;
}

int saveall()//�˳��༭������ִ�еĺ����������е����ݴ���
{
	int i, endflat = 0;
	char conti = 'y';
	text *p;
	for (i = 0, p = head; i<10; i++, p = p->next) //file://������д���ļ�
		if (p->flat == 1)
		{
			fputs(p->string, out);
			p->flat = 0;
		}
	while (!feof(fp))//�����������д���ļ�
		fputc(fgetc(fp), out);
	return 0;
}

int del()//ɾ��d�����Ӧ�ĺ���������ɾmin��max�е��У��ýṹ���е�flat��ʾ�Ƿ�ɾ��
{
	text *p1, *p2, *p3;
	int min, max, i;
	xiugai = 1;
	printf("������Ҫɾ���ڼ��е��ڼ���\n");
	scanf("%d %d", &min, &max);
	if (head == NULL)
	{
		printf("\nlist null!\n");
		return 0;
	}
	p1 = p2 = head;
	for (i = 0; i<min - 1; i++)/*�ҵ�Ҫɾ���ĵ�һ��*/
		p1 = p1->next;
	for (i = 0; i<max; i++)/*�ҵ�Ҫɾ�������һ��*/
		p2 = p2->next;
	for (delnum = 0; p1 != p2; p1 = p1->next)/*ɾ���м�Ľڵ㣬��flat��ֵ0*/
	{
		p1->flat = 0;
		delnum = delnum + p1->num;
	}
	for (i = 0, p3 = head; i<10; i++, p3 = p3->next)//��ʾɾ����Ľ��
		if (p3->flat == 1)
			puts(p3->string);
	saveanddisplay(10);//��ɾ����Ľ�����̲���ʾ��һҳ���ݣ�ʮ�У�
	xiugai = 1;
	return 0;
}
 
int insert()//����i�����Ӧ�ĺ�������i�к�����ı�
{
	int hang, i, increhang = 1, number = 1;
	text *p, *p1, *p2;
	xiugai = 1;
	printf("�������ڵڼ��в��룺\n");
	scanf("%d", &hang);
	p = p1 = NULL;
	for (i = 0, p1 = head; i<hang - 1; i++, p1 = p1->next);//�ҵ�Ҫ�����е�ǰһ��
	p = (text *)malloc(sizeof(text));//Ϊ�����з���ռ�
	p->flat = 1;
	p->next = p1->next;//�Ӵ����������н������в��뵽������
	p->pre = p1;
	p1->next->pre = p;
	p1->next = p;
	p->string[0] = getchar();
	p->string[0] = getchar();
	for (i = 1; (i<80) && (p->string[i - 1] != '^'); i++)
	{
		p->string[i] = getchar();
		if ((i + 1 == 80) && (p->string[i] != '^'))//�����������ݳ���һ��
		{        //file://���������������һ�пռ�
			p1 = p;      //file://��������������
			p = (text *)malloc(sizeof(text));
			p->flat = 1;
			p->next = p1->next;
			p->pre = p1;
			p1->next->pre = p;
			p1->next = p;
			i = 0;
			increhang++;
		}
		p->num = i;
	}
	p->string[i - 1] = '\n';
	p->string[i] = '\0';
	puts("�޸ĺ������");
	for (p2 = head; p2 != NULL; p2 = p2->next)//��ʾ���޸ĺ������
		puts(p2->string);
	saveanddisplay(10 + increhang);//���޸ĺ��������̲���ʾ��һҳ����
	xiugai = 1;
	return 0;
}
int EDIT()//�༭�������������ܴ���༭����
{

	char cmd;
	Createlist();
	system("cls");
	do
	{
		printf("\n����������(��E���˳�)��");
		cmd = getchar();
		switch (cmd)
		{
		case 'e':
		case 'E':
			if (xiugai == 1)
				saveall();
			freemem();
			if (fp) fclose(fp);
			if (out) fclose(out);
			system("cls");
			return 0;
		case 'o':
		case 'O':
			Openfiles();
			break;
		case 'p':
		case 'P':
			//Createlist();
			display();
			break;
		case 'n':
		case 'N':
			saveanddisplay(10);
			break;
		case 'd':
		case 'D':
			del();
			break;
		case 'i':
		case 'I':
			insert();
			break;
		default:printf("\n\n\n!!!�������!!!");
		}
		cmd = getchar();
	} while (cmd != 'e'&&cmd != 'E');
	
	return 0;
}


int main()//��������������������
{
    char cmd;
    do
    {
        printf("\n\t\t****************************\n");
        printf("\t\t**      1   EDIT   **\n");
        printf("\t\t**      2   HELP   **\n");
        printf("\t\t**      3   ABOUT   **\n");
        printf("\t\t**      4   EXIT   **\n");
        printf("\t\t****************************\n");
        printf("\n\n��ѡ��1��2��3��4:");
        cmd=getche();
        switch(cmd)
        {
            case '4' : system("cls"); byebye(); break;
            case '2' : system("cls"); HELP();  cmd=0; break;
            case '3' : system("cls"); ABOUT(); cmd=0; break;
            case '1' : EDIT();  cmd=0; break;
            default : printf("\n\n\n!!!�������!!!\n");
        } 
   }while(cmd!='4');
   return 0;
}


