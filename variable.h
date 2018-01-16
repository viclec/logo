#ifndef __VARIABLE__
#define __VARIABLE__

class Variable {	//TODO check class templates
protected:
	char* word;
	double number;
	bool boolean;
	std::vector<Variable> list;
	std::string type;
public:
	Variable() {};
	Variable(char* word) : word(word) {};
	Variable(double number) : number(number) {};
	Variable(int number) : number(number) {};
	Variable(bool boolean) : boolean(boolean) {};

	bool operator==(char* string) {
		return (strcmp(this->word, string) == 0 && this->word != NULL);
	}

	bool operator==(int integer) {
		return (this->number == integer && this->number != NULL);
	}

	bool operator==(double dbl) {
		return (this->number == dbl && this->number != NULL);
	}

	bool operator==(Variable rhs) {
		return (this->number == rhs.number && number != NULL);
	}

	bool operator<=(int number) {
		return (number <= this->number && number != NULL);
	}

	bool operator<=(double number) {
		return (number <= this->number && number != NULL);
	}

	bool operator<=(bool boolean) {
		return (boolean <= this->boolean && boolean != NULL);
	}

	bool operator<=(char* word) {
		return (strcmp(word, this->word) <= 0 && word != NULL);
	}

	bool operator>=(int number) {
		return (number >= this->number && number != NULL);
	}

	bool operator>=(double number) {
		return (number >= this->number && number != NULL);
	}

	bool operator>=(bool boolean) {
		return (boolean >= this->boolean && boolean != NULL);
	}

	bool operator>=(char* word) {
		return (strcmp(word, this->word) >= 0 && word != NULL);
	}

	bool operator<(int number) {
		return (number < this->number && number != NULL);
	}

	bool operator<(double number) {
		return (number < this->number && number != NULL);
	}

	bool operator<(bool boolean) {
		return (boolean < this->boolean && boolean != NULL);
	}

	bool operator<(char* word) {
		return (strcmp(word, this->word) < 0 && word != NULL);
	}

	bool operator>(int number) {
		return (number > this->number && number != NULL);
	}

	bool operator>(double number) {
		return (number > this->number && number != NULL);
	}

	bool operator>(bool boolean) {
		return (boolean > this->boolean && boolean != NULL);
	}

	bool operator>(char* word) {
		return (strcmp(word, this->word) > 0 && word != NULL);
	}

	Variable& Variable::operator = (Variable &v) {
		return v;
	}

	//Variable& Variable::operator = (List &l) {
	//	this->list = l;
	//}

	Variable& Variable::operator = (char* a) {
		this->word = a;
		this->type = "word";
		return *this;
	}

	Variable& Variable::operator = (int a) {
		this->number = a;
		this->type = "number";
		return *this;
	}

	Variable& Variable::operator = (double a) {
		this->number = a;
		this->type = "number";
		return *this;
	}

	double getNumber() {
		return number;
	}

	char* getWord() {
		return word;
	}

	bool getBoolean() {
		return boolean;
	}

	std::vector<Variable> getList() {
		return list;
	}

	Variable& operator, (Variable& item) {
		this->list.push_back(item);
		return *this;
	}

	Variable& operator[](Variable& v) {
		this -> list = v.getList();
		this->list.insert(this ->list.begin(), v);
		return *this;
	}
};

bool operator==(int number, Variable rhs) {
	return (number == rhs.getNumber() && number != NULL);
}

bool operator==(double number, Variable rhs) {
	return (number == rhs.getNumber() && number != NULL);
}

bool operator==(bool boolean, Variable rhs) {
	return (boolean == rhs.getBoolean() && boolean != NULL);
}

bool operator==(char* word, Variable rhs) {
	return (strcmp(word, rhs.getWord())==0 && word != NULL);
}

bool operator<=(int number, Variable rhs) {
	return (number <= rhs.getNumber() && number != NULL);
}

bool operator<=(double number, Variable rhs) {
	return (number <= rhs.getNumber() && number != NULL);
}

bool operator<=(bool boolean, Variable rhs) {
	return (boolean <= rhs.getBoolean() && boolean != NULL);
}

bool operator<=(char* word, Variable rhs) {
	return (strcmp(word, rhs.getWord()) <= 0 && word != NULL);
}

bool operator>=(int number, Variable rhs) {
	return (number >= rhs.getNumber() && number != NULL);
}

bool operator>=(double number, Variable rhs) {
	return (number >= rhs.getNumber() && number != NULL);
}

bool operator>=(bool boolean, Variable rhs) {
	return (boolean >= rhs.getBoolean() && boolean != NULL);
}

bool operator>=(char* word, Variable rhs) {
	return (strcmp(word, rhs.getWord()) >= 0 && word != NULL);
}

bool operator<(int number, Variable rhs) {
	return (number < rhs.getNumber() && number != NULL);
}

bool operator<(double number, Variable rhs) {
	return (number < rhs.getNumber() && number != NULL);
}

bool operator<(bool boolean, Variable rhs) {
	return (boolean < rhs.getBoolean() && boolean != NULL);
}

bool operator<(char* word, Variable rhs) {
	return (strcmp(word, rhs.getWord()) < 0 && word != NULL);
}

bool operator>(int number, Variable rhs) {
	return (number > rhs.getNumber() && number != NULL);
}

bool operator>(double number, Variable rhs) {
	return (number > rhs.getNumber() && number != NULL);
}

bool operator>(bool boolean, Variable rhs) {
	return (boolean > rhs.getBoolean() && boolean != NULL);
}

bool operator>(char* word, Variable rhs) {
	return (strcmp(word, rhs.getWord()) > 0 && word != NULL);
}
#endif  __VARIABLE__
