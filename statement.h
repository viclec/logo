#include <string>

class Statement{
private:
	std::string type;
	int repcount;
	int lineNumber;
	int id;
	static int count;
public:
	Statement(std::string type, int lineNumber) : type(type), lineNumber(lineNumber), id(++count){
		type.compare("repeat") == 0 ? repcount = 0 : repcount = -1 ;
	}
	~Statement(){}
	
	int getRepCount(void){
		return repcount;
	}
	
	int getLineNumber(void){
		return lineNumber;
	}

	void incrementRepCount(void){
		repcount++;
	}
};

int Statement::count = 0;
