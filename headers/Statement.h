#include <string>

class Statement{
private:
	std::string type;
	unsigned int repcount;
	int lineNumber;
	int id;
	static int count;
	Variable list;
public:
	Statement(std::string type, int lineNumber) : type(type), lineNumber(lineNumber), id(++count){
		type.compare("repeat") == 0 || type.compare("foreach") == 0 ? repcount = 0 : repcount = -1 ;
	}
	~Statement(){}
	
	int getRepCount(void){
		return repcount;
	}

	std::string getType(void) {
		return type;
	}

	Variable getCurrentElement(void) {
		assert(repcount <= list.getList().size());
		return list.getList()[repcount];
	}

	void initRepCount(void) {
		repcount = 0;
	}
	
	int getLineNumber(void){
		return lineNumber;
	}

	void incrementRepCount(void){
		repcount++;
	}
};

int Statement::count = 0;
