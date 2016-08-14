#include"list.h"
static node * constructor(list *pthis)
{
	
}

list_iterator begin(struct list *pthis)
{
	return (pthis->head)->next;
}
list_iterator end(struct list *pthis)
{
	return pthis->head;
}
list_const_iterator cbegin(struct list *pthis)
{
	return (pthis->head)->next;
}
list_const_iterator cend(struct list *pthis)
{
	return pthis->head;
}
size_type max_size(struct list *pthis)
{
	return -1;
}
T * front(struct list *pthis)
{
	return pthis->head->next;
}
T * back(struct list *pthis)
{
	return pthis->head->prev;
}