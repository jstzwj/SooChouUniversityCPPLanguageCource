#include "fib.h"

void * safe_malloc(int size)
{
	void *ptr;
	ptr = malloc(size);
	if (ptr==NULL)
	{
		printf("Fail to assign memory in heap!");
		exit(0);
	}
	return ptr;
}

void safe_gets(char * str,int limit)
{
	int i=0;
	char c;
	while(c!='\n'&&i!=limit-1)
	{
		str[i] = getchar();
		i++;
	}
	str[++i] = '\0';
}

void * sort_ptr_array(void * ptr)
{

	return NULL;
}
