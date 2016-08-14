#include<iostream>
#include<string>
#include<vector>

class scanner
{
private:
	typedef std::vector<std::pair<std::string, std::string> > tokentype;
	typedef std::vector<std::string> cuttype;
	const std::string * source;
	const cuttype *tokentable;
	const tokentype *table;
public:
	scanner();
	scanner(const std::string & src,const std::vector<std::string> &keytable);
	void setSource(const std::string & src);
	void setTokenTable(const std::vector<std::string> &keytable);
	void setTable(const std::vector<std::string> &keytable);
	std::vector<std::pair<std::string,std::string> > scan();
};