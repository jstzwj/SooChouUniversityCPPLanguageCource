#pragma once
#ifndef FIB
#define FIB
#include<stdlib.h>
#include<stdio.h>
//Just like the function strcpy_s,scanf_s,gets_s in vc or operator new in c++.
void *safe_malloc(int size);
void safe_gets(char *str,int limit);
//Common algorithm
void *sort_ptr_array(void *ptr);


#endif // !FIB
