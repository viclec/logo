#ifndef __VARIABLE__
#define __VARIABLE__

class Variable {	//TODO check class templates
protected:
	char* word;
	double number;
	bool boolean;
	std::vector<char*> sentence;
	std::vector<Variable> list;
	std::string type;
public:
	bool isValid = 1;
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

	Variable& Variable::operator= (Variable &v) {
		return v;
	}

	Variable& Variable::operator= (Variable* v) {
		int iterator = 0;
		Variable* tmp = &v[iterator];
		while (tmp->isValid) {
			this->list.push_back(*tmp);
			tmp = &v[++iterator];
		}
		return *this;
	}
	
	Variable& operator= (std::vector<Variable> array) {
	
	}

	//Variable& Variable::operator= (List &l) {
	//	this->list = l;
	//}

	Variable& Variable::operator= (char* a) {
		this->word = a;
		this->type = "word";
		return *this;
	}

	Variable& Variable::operator= (int a) {
		this->number = a;
		this->type = "number";
		return *this;
	}

	Variable& Variable::operator= (double a) {
		this->number = a;
		this->type = "number";
		return *this;
	}

	Variable& Variable::operator+ (Variable v) {
		assert(this->type == "number" && v.getType() == "number");
		this->number += v.getNumber();
		return *this;
	}
	
	Variable& Variable::operator- (Variable v) {
		assert(this->type == "number" && v.getType() == "number");
		this->number -= v.getNumber();
		return *this;
	}
	Variable& Variable::operator* (Variable v) {
		assert(this->type == "number" && v.getType() == "number");
		this->number *= v.getNumber();
		return *this;
	}
	Variable& Variable::operator* (double v) {
		assert(this->type == "number");
		this->number *= v;

		return *this;
	}
	Variable& Variable::operator/ (Variable v) {
		assert(this->type == "number" && v.getType() == "number");
		assert(v.getNumber() != 0);
		this->number /= v.getNumber();
		return *this;
	}
	Variable& Variable::operator% (Variable v) {
		assert(this->type == "number" && v.getType() == "number");
		assert(v.getNumber() != 0);
		this ->number = (int)this->number % (int)v.getNumber();
		return *this;
	}


	Variable& Variable::operator<< (Variable v) {
		assert(this->type == "word" && v.getType() == "word");
		this->sentence = v.getSentence();
		this->sentence.push_back(word);
		return *this;
	}

	double getNumber() {
		return number;
	}

	std::string getType() {
		return type;
	}


	std::vector<char*> getSentence() {
		return sentence;
	}

	char* getWord() {
		return word;
	}

	bool hasType() {
		return type != "";
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
	
		// to ka8arizoume gt pername by reference k meta menoun sto list skoupidia an exei 8ema to vgazoume
		for (int i = 2; i < this -> list.size(); i++) {
			this->list[i].list.clear();
		}
		
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
