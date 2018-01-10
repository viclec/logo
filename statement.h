#include <string>

class Statement{
private:
	std::string type;
	int repcount;
	int id;
	static int count;
public:
	Statement(std::string type) : type(type), id(++count){
		type.compare("repeat") == 0 ? repcount = 0 : repcount = -1 ;
	}
	~Statement(){}
};

int Statement::count = 0;
