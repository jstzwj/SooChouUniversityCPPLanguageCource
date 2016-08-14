#include"string.h"
static void constructor_default(string *pthis)
{
	//bind pointer with their own functions
	pthis->constructor_default = constructor_default;
	pthis->constructor_char = constructor_char;
	pthis->constructor_copy = constructor_copy;
	pthis->size = size;
	pthis->length = length;
	pthis->capacity = capacity;
	pthis->c_str = c_str;
	pthis->begin = begin;
	pthis->cbegin = cbegin;
	pthis->end = end;
	pthis->cend = cend;
	pthis->copy = copy;

	//pointers move to their position
	pthis->start = (char *)malloc(sizeof(char) * 1);
	if (pthis->start == NULL)
	{
		printf("Fail to assign memory in heap.");
		exit(0);
	}
	pthis->finish = pthis->start;
	pthis->end_of_storage = pthis->finish;
	//assign value
	*(pthis->start) = '\0';
}


static void constructor_char(string *pthis, char *str)
{
	pthis->start = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	if (pthis->start == NULL)
	{
		printf("Fail to assign memory in heap.");
		exit(0);
	}
	pthis->finish = pthis->start + strlen(str) + 1;
	pthis->end_of_storage = pthis->start + strlen(str) * 2 + 1;
	//assign value
	strcpy(pthis->start, str);
}
static void constructor_copy(string *pthis, string *other)
{
	pthis->start = (char *)malloc(sizeof(char)*(strlen(other->start) + 1));
	if (pthis->start == NULL)
	{
		printf("Fail to assign memory in heap.");
		exit(0);
	}
	pthis->finish = pthis->start + strlen(other->start) + 1;
	pthis->end_of_storage = pthis->start + strlen(other->start) * 2 + 1;
	//assign value
	strcpy(pthis->start, other->start);
}
static void deconstructor(struct string *pthis)
{
	free(pthis->start);
}

static size_type length(const struct string *pthis)
{
	return pthis->finish - pthis->start;
}
static size_type size(const struct string *pthis)
{
	return pthis->finish - pthis->start;
}
static size_type capacity(const struct string *pthis)
{
	return pthis->end_of_storage - pthis->start;
}
static const char *c_str(const struct string *pthis)
{
	return pthis->start;
}
static string_iterator begin(struct string *pthis)
{
	return pthis->start;
}
static string_iterator end(struct string *pthis)
{
	return pthis->finish;

}
static string_const_iterator cbegin(const struct string *pthis)
{
	return pthis->start;
}
static string_const_iterator cend(const struct string *pthis)
{
	return pthis->finish;
}
STRUCT_STATIC static void copy(struct string *lhs, const struct string*rhs)
{
	char *temp = lhs->start;
	if (lhs->size(lhs)<rhs->size(rhs))
	{
		lhs->start = (char *)malloc(sizeof(char)*(strlen(rhs->start) + 1));
		if (lhs->start == NULL)
		{
			printf("Fail to assign memory in heap.");
			exit(0);
		}
		lhs->finish = lhs->start + strlen(rhs->start) + 1;
		lhs->end_of_storage = lhs->start + strlen(rhs->start) * 2 + 1;
		//assign value
		strcpy(lhs->start, rhs->start);
		free(temp);
	}
	else
	{
		//assign value
		strcpy(lhs->start, rhs->start);
	}
}