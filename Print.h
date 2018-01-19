#include <iostream>

class Print {
public:
	Print() {}

	void operator= (Variable item) {
		std::cout << item.getSentenceAsString();	//TODO draw label
	}

	void operator= (char* string) {
		turtle_draw_label(string);
	}

};
