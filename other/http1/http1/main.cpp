//socket err
#define UNKNOWNHOST -2
#define NOSOCK      -1
#define SOCKCONNECTFAIL -3
#include<WinSock2.h>
#include<cstdio>

//建立一个http tcp 连接的辅助函数
int htconnect(char *domain, int port)
{
	int white_sock;
	struct hostent *site;
	struct sockaddr_in me;

	//获得服务器的名称，使用DNS解析域名
	site = gethostbyname(domain);
	if (NULL == site)
	{
		printf("%s", domain);
		printf("is unknown");
		return UNKNOWNHOST;
	}
	//建立套接字
	white_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (white_sock < 0)
	{
		printf("white_sock<0");
		return NOSOCK;
	}
	//初始化为0
	memset(&me, 0, sizeof(struct sockaddr_in));
	memcpy(&me.sin_addr, site->h_addr_list[0], site->h_length);
	//inet_addr(me.sin_addr);
	me.sin_family = AF_INET;
	me.sin_port = htons(port);

	//建立连接
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

//通过url提取host、port
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
	//判断是否有path
	if (end = strchr(start, '/'))
	{
		if ((end - url) == (strlen(url) - 1))
		{
			//printf("以斜杠结尾的url：%s",url);
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
	  //是否有端口
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

//封装请求
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