#include "variable.h"
#include <iostream>

class Sentence : protected Variable {
public:
	Sentence() {
		Variable::Variable();
	}
	Sentence(char* word) {
		Variable::Variable(word);
	}
	Sentence(double number) {
		Variable::Variable(number);
	}
	Sentence(int number) {
		Variable::Variable(number);
	}
	Sentence(bool boolean) {
		Variable::Variable(boolean);
	}

	Variable& operator, (Variable& item) {
		this->list.push_back(item);
		return *this;
	}
	
	Variable& operator()(Variable& v) {
		this->list = v.getList();
		this->list.insert(this->list.begin(), v);
		return *this;
	}
	
};
