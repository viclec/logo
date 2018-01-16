#include "variable.h"
#include <iostream>

class Sentence : protected Variable {
private:
	unsigned size = 0;
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

	// giati ayto trwei enw to array de trwei de katalavainw
	/*Variable& operator, (Variable& item) {
		this->list.push_back(item);
		return *this;
	}*/

	// opws k edw gt trwei to sentence k de trwei to array
	/*
	Variable& operator()(Variable& v) {
		this->list = v.getList();
		this->list.insert(this->list.begin(), v);
		return *this;
	}
	*/
};
