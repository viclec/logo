#include <iostream>

class Print {
public:
	Print() {}

	void operator= (Variable item) {
		if (item.getType() == "word") {
			turtle_draw_label(item.getWord());
			return;
		}
		turtle_draw_label(item.getSentenceAsString());
	}

	void operator= (char* string) {
		turtle_draw_label(string);
	}

};
