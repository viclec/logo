#include <string>

class Function {
private:
	std::string name;
	std::vector<Variable> args;
	static std::vector<Function> stack;
public:
	static void getStack() {

	}
	Function() { }
	Function(char* name) : name(name) { stack.push_back(Function()); }
	~Function() {}

	
};
