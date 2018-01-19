#include "variable.h"
#include <iostream>
class Array : protected Variable {
private:
	unsigned size = 0;
	std::vector<Variable> array;
public:
	Array() {
		Variable::Variable();
	}
	Array(char* word){
		Variable::Variable(word);
	}
	Array(double number) {
		Variable::Variable(number);
	}
	Array(int number) {
		Variable::Variable(number);
	}
	Array(bool boolean){
		Variable::Variable(boolean);
	}

	Array& operator=(Variable v) {
		this->size = v.getNumber();
		return *this;
	}
	
	Array& operator=(int number) {
		this->size = number;
		return *this;
	}

	Array& operator=(Variable* v) {
		return *this;
	}

	template <typename T>
	Array& operator=(initializer_list<T> l) {
		size = l.size();

		array.insert(array.end(), l.begin(), l.end());

		return *this;
	}

	std::vector<Variable> getArray() {
		return array;
	}
	
	/* 8elei argument enw de 8elw na tou valw pi8ano na valoyme argument k na exei periptwsh p einai adeio. */
	/*Variable& operator[]() {
		this -> size = 30;
		return *this;
	}*/

	/*Variable& operator[](Variable& v) {
		if (size != 0) {
			std::cout << "poulo";
			return *this;
		}
		this->list = v.getList();
		this->list.insert(this->list.begin(), v);
		size = this->list.size();

		return *this;
	}

	/*
	Variable& operator, (Variable& item) {
		this->list.push_back(item);
		return *this;
	}
	*/
};

Variable& Variable::operator= (Variable& v1, Array v2) {
	v1.setList(v2.getArray());
	return v1;
}
