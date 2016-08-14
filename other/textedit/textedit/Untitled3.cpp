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
 char string[80];//存储每一行的元素
 struct text *next;//指向后一个节点的指针
 struct text *pre;//指向前一个节点的指针
 int num;//每一行元素的长度
 int flat;//确定此行是否被删除的标志
}text;
FILE *fp,*out;//fp是执行被打开的文件，out指向被写入的文件
text *head;//链表的头指针
int sum,delnum,xiugai=0,page=0;
//file://修改用来指示文件是否被修改过，如果修改过才回存盘。page用来计算显示的
//file://页数.delnum用来存储被删除的字节数，sum存储一页的总字节数

void byebye()//没有具体用处，只是写着玩的，在屏幕上显示一个bye
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


void HELP()//帮助函数，显示一些命令的格式
{
 printf("\n\t**********************************************************\n");
 printf("\t**  打开文件：  o<行号><文件名><回车>  **\n");
 printf("\t**  行插入格式： i<行号><回车><文本><回车> **\n");
 printf("\t**  行删除格式： d<行号1>[<空格><行号2>]<回车> **\n");
 printf("\t**  活区切换格式： n<回车>    **\n");
 printf("\t**  活区显示格式： p<回车>    **\n");
 printf("\t**  注意：在执行所有命令前必须先用o命令打开文件，并 **\n");
 printf("\t**  用p命令显示出来！！！    **\n");
 printf("\t**********************************************************\n");
 system("pause");
 printf("\n\n\n");
 
}

 

void ABOUT()//也是写着玩的
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

void Createlist()//建立一个十个节点的链表，是文本中的一页
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

void freemem()//释放链表所占的内存
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


int Openfiles()//打开文件的函数
{
	char name[30], outname[30];
	puts("请输入要打开的文件名：");
	scanf("%s", name);
	if ((fp = fopen(name, "r+")) == NULL)
	{
		printf("打不开原文件！ \n");
		exit(0);
	}
	puts("请输入要写入的文件名：");
	scanf("%s", outname);
	if ((out = fopen(outname, "w+")) == NULL)
	{
		printf("打不开目标文件！\n");
		exit(0);
	}
	return 0;
}


int display()//从文件中读入到链表中，并显示出来
{
	int i;
	char conti = 'y';
	text *p;
	while ((!feof(fp)) && (conti == 'y' || conti == 'Y'))
	{
		page++;
		printf("\t\t第%d页\n", page);
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
			puts("\n文件已经结束!");
			return 0;
		}
	}
	return 0;
}


int saveanddisplay(int hang)//命令n执行的函数，用来将活区的内容显示并读入下一页内容
{
	int i, endflat = 0;
	char conti = 'y';
	text *p = NULL;
	page++;
	for (i = 0, p = head; i<hang&&p!=NULL; i++, p = p->next) //file://将活区写入文件//---------!-----------
		if (p->flat == 1)
		{

			fputs(p->string, out);
			p->flat = 0;
		}
	if (!feof(fp))
		printf("\t\t第%d页\n", page);
	for (i = 0, p = head, sum = 0; (i<10) && (!feof(fp)); i++, p = p->next)//从文件读入活区
		if (fgets(p->string, sizeof(p->string), fp))
		{
			puts(p->string);
			p->flat = 1;
			p->num = strlen(p->string);
			sum = sum + p->num;
		}
	if (feof(fp))
		printf("文件已经结束！");
	return 0;
}

int saveall()//退出编辑函数后执行的函数，将所有的内容存盘
{
	int i, endflat = 0;
	char conti = 'y';
	text *p;
	for (i = 0, p = head; i<10; i++, p = p->next) //file://将活区写入文件
		if (p->flat == 1)
		{
			fputs(p->string, out);
			p->flat = 0;
		}
	while (!feof(fp))//将其余的内容写入文件
		fputc(fgetc(fp), out);
	return 0;
}

int del()//删除d命令对应的函数，用来删min－max中的行，用结构体中的flat表示是否被删除
{
	text *p1, *p2, *p3;
	int min, max, i;
	xiugai = 1;
	printf("请输入要删除第几行到第几行\n");
	scanf("%d %d", &min, &max);
	if (head == NULL)
	{
		printf("\nlist null!\n");
		return 0;
	}
	p1 = p2 = head;
	for (i = 0; i<min - 1; i++)/*找到要删除的第一行*/
		p1 = p1->next;
	for (i = 0; i<max; i++)/*找到要删除的最后一行*/
		p2 = p2->next;
	for (delnum = 0; p1 != p2; p1 = p1->next)/*删除中间的节点，将flat赋值0*/
	{
		p1->flat = 0;
		delnum = delnum + p1->num;
	}
	for (i = 0, p3 = head; i<10; i++, p3 = p3->next)//显示删除后的结果
		if (p3->flat == 1)
			puts(p3->string);
	saveanddisplay(10);//将删除后的结果存盘并显示下一页内容（十行）
	xiugai = 1;
	return 0;
}
 
int insert()//插入i命令对应的函数，在i行后插入文本
{
	int hang, i, increhang = 1, number = 1;
	text *p, *p1, *p2;
	xiugai = 1;
	printf("请输入在第几行插入：\n");
	scanf("%d", &hang);
	p = p1 = NULL;
	for (i = 0, p1 = head; i<hang - 1; i++, p1 = p1->next);//找到要插入行的前一列
	p = (text *)malloc(sizeof(text));//为插入行分配空间
	p->flat = 1;
	p->next = p1->next;//从此行向下四行将插入行插入到链表中
	p->pre = p1;
	p1->next->pre = p;
	p1->next = p;
	p->string[0] = getchar();
	p->string[0] = getchar();
	for (i = 1; (i<80) && (p->string[i - 1] != '^'); i++)
	{
		p->string[i] = getchar();
		if ((i + 1 == 80) && (p->string[i] != '^'))//如果插入的内容超过一行
		{        //file://的容量，则分配下一行空间
			p1 = p;      //file://并将其连入链表
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
	puts("修改后的链表：");
	for (p2 = head; p2 != NULL; p2 = p2->next)//显示出修改后的链表
		puts(p2->string);
	saveanddisplay(10 + increhang);//将修改后的链表存盘并显示下一页内容
	xiugai = 1;
	return 0;
}
int EDIT()//编辑函数，用来接受处理编辑命令
{

	char cmd;
	Createlist();
	system("cls");
	do
	{
		printf("\n请输入命令(按E键退出)：");
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
		default:printf("\n\n\n!!!输入错误!!!");
		}
		cmd = getchar();
	} while (cmd != 'e'&&cmd != 'E');
	
	return 0;
}


int main()//主函数，用来接受命令
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
        printf("\n\n请选择1，2，3，4:");
        cmd=getche();
        switch(cmd)
        {
            case '4' : system("cls"); byebye(); break;
            case '2' : system("cls"); HELP();  cmd=0; break;
            case '3' : system("cls"); ABOUT(); cmd=0; break;
            case '1' : EDIT();  cmd=0; break;
            default : printf("\n\n\n!!!输入错误!!!\n");
        } 
   }while(cmd!='4');
   return 0;
}


