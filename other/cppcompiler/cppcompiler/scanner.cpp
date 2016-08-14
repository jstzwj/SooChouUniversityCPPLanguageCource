#include"scanner.h"
scanner::scanner():source(nullptr),table(nullptr){}
scanner::scanner(const std::string & src,const std::vector<std::string> &keytable)
{
	source=&src;
	tokentable=&keytable;
}
void scanner::setSource(const std::string & src)
{
	source=&src;
}
void scanner::setTokenTable(const std::vector<std::string>& keytable)
{
	tokentable=&keytable;
}
void scanner::setTable(const std::vector<std::string>& keytable)
{
	table = &keytable;
}
std::vector<std::pair<std::string,std::string> > scanner::scan()
{
	for(int i=0;i<source->length();++i)
	{


	}

}