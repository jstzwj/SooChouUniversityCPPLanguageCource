//socket err
#define UNKNOWNHOST -2
#define NOSOCK      -1
#define SOCKCONNECTFAIL -3
#include<WinSock2.h>
#include<cstdio>

//����һ��http tcp ���ӵĸ�������
int htconnect(char *domain, int port)
{
	int white_sock;
	struct hostent *site;
	struct sockaddr_in me;

	//��÷����������ƣ�ʹ��DNS��������
	site = gethostbyname(domain);
	if (NULL == site)
	{
		printf("%s", domain);
		printf("is unknown");
		return UNKNOWNHOST;
	}
	//�����׽���
	white_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (white_sock < 0)
	{
		printf("white_sock<0");
		return NOSOCK;
	}
	//��ʼ��Ϊ0
	memset(&me, 0, sizeof(struct sockaddr_in));
	memcpy(&me.sin_addr, site->h_addr_list[0], site->h_length);
	//inet_addr(me.sin_addr);
	me.sin_family = AF_INET;
	me.sin_port = htons(port);

	//��������
	int err = connect(white_sock, (struct sockaddr*)&me, sizeof(struct sockaddr));
	//printf("err=%d\n",err);
	if (err<0)
	{
		//printf("%s\n",domain);
		//printf("black_sock's errno: %d\n",errno);
		printf("socket connect failed\n");
		return SOCKCONNECTFAIL;
	}
	return  white_sock;
}

//ͨ��url��ȡhost��port
void getHostPath(char* url, char *host, char* path, int* port)
{
	//printf("getHostPath before\n");
	if (!url)
	{
		return;
	}
	memset(host, 0, strlen(host));
	char* start = 0;
	char* end = 0;
	char* middle = 0;
	if (strstr(url, "https"))
	{
		start = url + 8;
	}
	else if (strstr(url, "http"))
	{
		start = url + 7;
	}
	else
	{
		start = url;
	}
	//�ж��Ƿ���path
	if (end = strchr(start, '/'))
	{
		if ((end - url) == (strlen(url) - 1))
		{
			//printf("��б�ܽ�β��url��%s",url);
			strcpy(path, "/");
			memcpy(host, start, strlen(url) - (start - url) - 1);
			*port = 80;
			return;
		}
		else
		{
			memcpy(path, end, strlen(url) - (end - url));
		}
	}//of
	else
	{
		strcpy(path, "/");
		end = url + strlen(url);
	} //else
	  //�Ƿ��ж˿�
	if (middle = strchr(start, ':'))
	{
		memcpy(host, start, middle - start);
		middle++;
		char portstr[10];
		memcpy(portstr, middle, end - middle);
		*port = atoi(portstr);
	}
	else
	{
		*port = -1;
		memcpy(host, start, end - start);
	}
	if (!(*path))
	{
		strcpy(path, "/");
	}
	if (*port == -1)
	{
		*port = 80;
	}
	return;
}

//��װ����
void packURLRequest(char* ques, char*host, char*path)
{
	memset(ques, 0, strlen(ques));
	strcat(ques, "GET ");
	strcat(ques, path);//PATH
	strcat(ques, " HTTP/1.1\r\n");
	strcat(ques, "Host:");
	strcat(ques, host);
	strcat(ques, "\r\n");
	strcat(ques, "Accept: *


		if (fd == NULL)
		{
			printf("url save direction not exist!");
		}
	char buf[1000];
	while (1)
	{
		while ((recv(black_sock, buf, 1000, MSG_WAITALL))>0)
		{

			fwrite(buf, strlen(buf), 1, fd);
		}
		break;
	}
	//printf("Finish reading;\n");
	fclose(fd);
	close(black_sock);
	return 1;

}