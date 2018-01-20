#include <iostream>

class Print {
	std::string destination;
public:
	Print(char* dest) : destination(dest) {}

	void operator= (Variable item) {
		if (destination == "console") {
			std::cout << item;
		}
		else if (destination == "bitmap") {
			if (item.getType() == "word") {
				turtle_draw_label(item.getWord());
				return;
			}
			turtle_draw_label(item.getSentenceAsString());
		}
	}

	void operator= (char* string) {
		if (destination == "console") {
			std::cout << string;
		}
		else {
			turtle_draw_label(string);
		}
	}

};
