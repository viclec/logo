#include <string>

class Variable{
private:
	std::string word;
	double number;
	bool boolean;
public:
	Variable(std::string word) : word(word){}
	Variable(double number) : number(number){}
	Variable(bool boolean) : boolean(boolean){}
}
