#ifndef __VARIABLE__
#define __VARIABLE__

class Variable {
protected:
	char* word;
	double number;
	bool boolean;
	std::vector<char*> sentence;
	std::vector<Variable> list;
	std::vector<Variable> array;
	std::string type;
	std::string state;
	int arraySize;
public:
	bool isValid = 1;
	Variable() {};
	Variable(char* type) : type(std::string(type)) {};
	Variable(double number) : number(number), type("number") {};
	Variable(int number) : number(number), type("number") {};
	Variable(bool boolean) : boolean(boolean), type("number") {};



	double getNumber() {
		return number;
	}

	std::string getState() {
		return state;
	}

	std::string getType() {
		return type;
	}

	std::vector<Variable> getArray() {
		return array;
	}

	std::vector<char*> getSentence() {
		return sentence;
	}

	char* getSentenceAsString() {
		int i;
		char result[1024];	//TODO malloc + realloc 

		strcpy_s(result, sentence[sentence.size() - 1]);

		for (i = sentence.size() - 2; i >= 0; i--) {
			strcat_s(result, sentence[i]);
		}

		return result;
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

	void setList(std::vector<Variable> newList) {
		list = newList;
	}

	std::vector<Variable>::iterator begin() {
		if (type == "array") {
			return array.begin();
		}
		if (type == "list") {
			return list.begin();
		}
	}

	std::vector<Variable>::iterator end() {
		if (type == "array") {
			return array.end();
		}
		if (type == "list") {
			return list.end();
		}
	}

	bool operator==(char* string) {
		return (strcmp(this->word, string) == 0 && this->word != NULL);
	}

	bool operator==(int integer) {
		return (this->number == integer && this->number != NULL);
	}

	bool operator==(double dbl) {
		return (this->number == dbl && this->number != NULL);
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
		if (v.getType().std::string::compare("number") == 0) {
			this -> number = v.getNumber();
			this->type = v.getType();
		}
		else if (v.getType().std::string::compare("word") == 0) {
			this->word = v.getWord();
			this->type = v.getType();
		}
		else if (v.getType().std::string::compare("list") == 0) {
			this->list = v.getList();
			this->type = v.getType();
		}
		else {
			assert(0);
		}
		return *this;
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
		return *this;
	}

	Variable& Variable::operator= (char* a) {
		this->word = a;
		this->type = "word";
		return *this;
	}

	Variable& Variable::operator= (int a) {
		if (type == "array")
			this->arraySize = a;
		else {
			this->number = a;
			this->type = "number";
		}
		return *this;
	}

	template <typename T>
	Variable& operator=(std::initializer_list<T> l) {
		arraySize = l.size();

		array.insert(array.end(), l.begin(), l.end());

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

	Variable& operator, (Variable& item) {
		if (type == "list" && state == "insertedList") {
			list.clear();
		}
		state = "insertedItem";
		this->list.push_back(item);
		return *this;
	}

	Variable& operator[](Variable& v) {
		this->list = v.getList();
		this -> state = "insertedList";
		this->list.insert(this ->list.begin(), v);
		
		return *this;
	}
	// TA STRING EINAI LATHOS
	bool operator== (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this -> number == v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word == v.getWord());
		}
		assert(0);
	}

	bool operator!= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number != v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word != v.getWord());
		}
		assert(0);
		return false;
	}

	bool operator> (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number > v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word > v.getWord());
		}
		assert(0);
	}
	bool operator< (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number < v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word < v.getWord());
		}
		assert(0);
	}
	bool operator>= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number >= v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word >= v.getWord());
		}
		assert(0);
	}
	bool operator<= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number <= v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return (this->word <= v.getWord());
		}
		assert(0);
	}

	bool operator&& (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number && v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return this->word && v.getWord();
		}
		assert(0);
	}
	bool operator|| (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number || v.getNumber());
		} else if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("word") == 0)) {
			return this->word || v.getWord();
		}
		assert(0);
	}
	bool operator! () {
		if ((this->type.std::string::compare("number") == 0)) {
			return !this->number;
		} else if ((this->type.std::string::compare("word") == 0)) {
			return !this->word;
		}
		assert(0);

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


std::ostream& operator<<(std::ostream& os, Variable v){
	if (v.getSentence().size() > 0) {
		int i = v.getSentence().size();
		while (i != 0) {
			os << v.getSentence()[--i];
		}
	}
	else if(v.getType() == "word") {
		os << v.getWord();
	}
	else if (v.getType() == "number") {
		os << v.getNumber();
	}
	else if (v.getType() == "list") {
		for (unsigned int i = 0; i < v.getList().size(); i++)
			os << v.getList()[i] << ' ';
	}
	else if (v.getType() == "array") {
		for (unsigned int i = 0; i < v.getArray().size(); i++)
			os << v.getArray()[i] << ' ';
	}
	return os;
}
#endif  __VARIABLE__
