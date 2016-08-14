#pragma once
#ifndef LIST
#define LIST
#include"string.h"


#ifdef T
#undef T
#endif // T
#define T string


struct node
{
	T data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;


typedef node * list_iterator;
typedef const node * list_const_iterator;
typedef T value_type;
typedef size_t size_type;
typedef ptrdiff_t difference_type;

struct list
{
	PRIVATE_MEMBER
	node *head;

	PUBLIC_MEMBER
	
	void(*constructor)(struct list *pthis);

	node * (*create_node)(struct list *pthis,const T *value);
 
	void(*destroy_node)(struct list *pthis,node *p);
	//TODO
	list_iterator (*begin)(struct list *pthis);
	list_iterator (*end)(struct list *pthis);
	list_const_iterator(*cbegin)(struct list *pthis);
	list_const_iterator(*cend)(struct list *pthis);

	size_type (*max_size)(struct list *pthis);
	T * (*front)(struct list *pthis);
	T * (*back)(struct list *pthis);

	void(*insert)(struct list *pthis,size_type n,const T *value);
	void(*push_front)(const T* value);
	void(*push_back)(const T* value);

	void (*pop_front)();
	void (*pop_back)();
};
typedef struct list list;



#endif // !LIST
