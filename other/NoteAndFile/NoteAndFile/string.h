#pragma once
#ifndef STRING
#define STRING

#include"version.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
This struct is used to dynamic assign memory in heap for strings.
If the length of the string is n,
it will ask for 2n bits in the memory.
*/
typedef char * string_iterator;
typedef const char * string_const_iterator;
typedef size_t size_type;
typedef ptrdiff_t difference_type;

struct string
{
	PRIVATE_MEMBER
	char * start;
	char * finish;
	char * end_of_storage;

	PUBLIC_MEMBER
	void(*constructor_default)(struct string *);
	void(*constructor_char)(struct string * ,char *);
	void(*constructor_copy)(struct string *,const struct string *);
	void(*deconstructor)(struct string *);

	size_type(*size)(const struct string *);
	size_type(*length)(const struct string *);
	size_type(*capacity)(const struct string *);
	const char * (*c_str)(const struct string *);
	string_iterator(*begin)(struct string *);
	string_iterator(*end)(struct string *);
	string_const_iterator(*cbegin)(const struct string *);
	string_const_iterator(*cend)(const struct string *);

	void (*copy)(struct string *lhs,const struct string*rhs);
	//TODO
	void(*push_back)(struct string *pthis, char c);
	char * (*at)(struct string *pthis, size_type n);
	int(*max_size)(struct string *pthis);
	bool (*empty)(struct string *pthis);
	void(*resize)(struct string *pthis,size_type n);
	void(*assign_string)(struct string *pthis, const struct string * other);
	void(*assign_string_int_int)(struct string *pthis, const struct string * other, int start, size_type n);
	void(*assign_string_int)(struct string *pthis,const struct string *other,size_type size);
	void(*assign_pchar)(struct string *pthis, char *str);
	void(*assign_pchar_int)(struct string *pthis, char *str, size_type size);
	void(*assign_int_char)(struct string *pthis, char c, int num);
	void(*assign_pchar_pchar)(struct string *pthis, char *begin, char *end);
};
typedef struct string string;


#endif // !STRING
