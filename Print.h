#include <iostream>

class Print {
public:
	Print() {}

	void operator= (Variable& item) {
		std::cout << item;
	}

	void operator= (char* string) {
		std::cout << string;
	}

};
