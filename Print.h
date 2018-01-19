#include <iostream>

class Print {
public:
	Print() {}

	void operator= (Variable item) {
		turtle_draw_label(item.getSentenceAsString());
	}

	void operator= (char* string) {
		turtle_draw_label(string);
	}

};
