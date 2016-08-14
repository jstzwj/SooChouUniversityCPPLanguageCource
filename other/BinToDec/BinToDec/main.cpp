#pragma once
#ifndef CINT
#define CINT


#include<cstddef>
typedef long long llong;
const long long LMT = 10e9;
class cint
{
public:
	cint();
	cint(llong num);
	cint(cint &from);
	cint operator=(cint &from);
	~cint();

	typedef llong value_type;                            
	typedef value_type* pointer;                    
	typedef const value_type* const_pointer;

	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef value_type& reference;                  
	typedef const value_type& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;       
	//½Ó¿Ú
	iterator begin() { return start; }
	iterator end() { return finish; }
	const_iterator cbegin() const{ return start; }
	const_iterator cend() const{ return finish; }
	
	size_type capacity() const { return size_type(end_of_storage - cbegin()); }
	bool empty() const { return cbegin() == cend(); }
	reference operator[](size_type n) { return *(begin() + n); }
	const_reference operator[](size_type n) const { return *(cbegin() + n); }
	size_type size() const { return size_type(cend() - cbegin()); }
	void push_back(llong a)
	{
		if (finish < end_of_storage) 
		{
			llong *temp = new llong[end_of_storage-start+1];
			delete[]start;
			finish = temp + (finish - start);
			end_of_storage = temp + (end_of_storage - start);
			start = temp;
			
		}
		else
		{
			*finish = a;
			finish++;
		}
	}
	//ÔËËã
	cint operator+(const cint &rhs)
	{
		llong temp;
		const cint *greater;
		const cint *lesser;
		if (rhs.size()>this->size())
		{
			greater = &rhs;
			lesser = this;
		}
		else
		{
			greater = this;
			lesser = &rhs;
		}

	}
protected:

private:
	llong * start;
	llong * finish;
	llong * end_of_storage;

};
cint::cint()
{
	start = new llong[1];
	finish = start + 1;
	end_of_storage = finish;
}

cint::cint(llong num)
{
	start = new llong[1];
	finish = start + 1;
	end_of_storage = finish;
	start[0] = num;
}

cint::cint(cint & from)
{
	llong * i;
	llong * j;
	start = new llong[from.end_of_storage - from.start];
	for (i=start,j = from.start; i < from.end_of_storage;i++,j++)
	{
		*i=*j;
	}
}

cint cint::operator=(cint & from)
{
	delete[]start;
	llong * i;
	llong * j;
	start = new llong[from.end_of_storage - from.start];
	for (i = start, j = from.start; i < from.end_of_storage; i++, j++)
	{
		*i = *j;
	}
	return *this;
}

cint::~cint()
{
	delete[]start;
}


int main()
{

	return 0;
}



#endif // !CINT

