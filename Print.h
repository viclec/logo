#include <iostream>

class Print {
public:
	Print() {}

	void operator= (Variable& item) {
		std::cout << item.getSentenceAsString();
	}

	void operator= (char* string) {
		turtle_draw_label(string);
	}

};
