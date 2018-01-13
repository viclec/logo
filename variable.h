class Variable{	//TODO check class templates
private:
	char* word;
	double number;
public:
	Variable() {};
	Variable(char* word) : word(word){};
	Variable(double number) : number(number){};
	Variable(int number) : number(number){};

	inline bool operator==(char* string) {
		return (word == string && word != NULL);
	}

	inline bool operator==(int integer) {
		return (number == integer && number != NULL);
	}

	inline bool operator==(double dbl) {
		return (number == dbl && number != NULL);
	}

	inline bool operator==(Variable* rhs) {
		return (number == rhs->number && number != NULL);
	}

	Variable* operator = (Variable a) {
		return &a;
	}

	Variable* operator = (char* a) {
		return new Variable(a);
	}

	Variable* operator = (int a) {
		return new Variable(a);
	}

	Variable* operator = (double a) {
		return new Variable(a);
	}

	/*
	template<typename var>
	Variable* operator = (var a){ 
		//if(&other == this)
        //    return *this;
	   return new Variable(a);
	}

	template<typename var>
	inline Variable& operator=(var a) {
		return Variable(a);
	}
	*/

};