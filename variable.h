class Variable{	//TODO check class templates
private:
	char* word;
	double number;
	bool boolean;
	//LIST
public:
	Variable() {};
	Variable(char* word) : word(word){};
	Variable(double number) : number(number){};
	Variable(int number) : number(number) {};
	Variable(bool boolean) : boolean(boolean){};

	bool operator==(char* string) {
		return (strcmp(word, string) == 0 && word != NULL);
	}

	bool operator==(int integer) {
		return (number == integer && number != NULL);
	}

	bool operator==(double dbl) {
		return (number == dbl && number != NULL);
	}

	bool operator==(Variable rhs) {
		return (number == rhs.number && number != NULL);
	}

	Variable& Variable::operator = (Variable &v) {
		return v;
	}

	Variable& Variable::operator = (char* a) {
		return Variable(a);
	}

	Variable& Variable::operator = (int a) {
		return Variable(a);
	}

	Variable& Variable::operator = (double a) {
		return Variable(a);
	}

	/*
	Variable Variable::operator [](int i) const {
		return list[i];
	}

	Variable & Variable::operator [](int i) {
		return list[i];
	}
	*/

	double getNumber() {
		return number;
	}

	char* getWord() {
		return word;
	}

	bool getBoolean() {
		return boolean;
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

