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
		if (this->type.std::string::compare("number") == 0) {
			this -> number = v.getNumber();
		}
		else if (this->type.std::string::compare("word") == 0) {
			this->word = v.getWord();
		}
		else {
			assert(1);
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

	char* getSentenceAsString() {	//TODO return string 
		/*
		char* result;
		int i, j;
		for (i = 0, result = (char*)calloc(1, strlen(sentence[i])); i < sentence.size(); i++, result = (char*)realloc(result, strlen(sentence[i]))) {
			for (j = 0; j < strlen(sentence[i]); j++) {	
				result[j+i*j] = sentence[i][j];
			}
		}

		std::cout << result;

		return result;

		char* result;
		int i = getSentence().size();
		while (i != 0) {
			strcat(result, getSentence()[--i]);
		}
		return result;
		*/
		return "FAEFA";
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
		/*for (int i = 2; (i < this -> list.size()); i++) {
			this->list[i].list.clear();
		}*/
		
		return *this;
	}
	// TA STRING EINAI LATHOS
	bool operator== (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this -> number == v.getNumber());
		}
		assert(1);
	}

	bool operator!= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number != v.getNumber());
		}
		assert(1);
	}

	bool operator> (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number > v.getNumber());
		}
		assert(1);
	}
	bool operator< (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number < v.getNumber());
		}
		assert(1);
	}
	bool operator>= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number >= v.getNumber());
		}
		assert(1);
	}
	bool operator<= (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number <= v.getNumber());
		}
		assert(1);
	}

	bool operator&& (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number && v.getNumber());
		}
		assert(1);
	}
	bool operator|| (Variable v) {
		if ((this->type.std::string::compare(v.getType()) == 0) && (this->type.std::string::compare("number") == 0)) {
			return (this->number || v.getNumber());
		}
		assert(1);
	}
	bool operator! () {
		if ((this->type.std::string::compare("number") == 0)) {
			if (number == 0) {
				return true;
			}
			return false;
		}
		assert(1);

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
	return os;
}
#endif  __VARIABLE__
