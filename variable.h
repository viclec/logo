#include <string>

class Variable{	//TODO check class templates
private:
	std::string word;
	double number;
	bool boolean;
public:
	Variable(std::string word) : word(word){};
	Variable(double number) : number(number){};
	Variable(int number) : number(number){};
	Variable(bool boolean) : boolean(boolean){};

	friend std::ostream& operator<< (std::ostream& stream, const Variable& var) {
		std::string s;
//		s = std::to_string(static_cast<long long>(number));
		return stream << s;
    }

	inline bool operator==(const Variable& rhs) {
		return (number == rhs.number && number != NULL) || (boolean == rhs.boolean && boolean);
	}

};


