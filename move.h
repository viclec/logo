class Move {
private:
	const char* moveType;
	int x;
	int y;
public:
	Move(const char* move) : moveType(move) {};

	void Move::operator , (Variable number) {
		std::cout << "XY" << std::endl;
	}

	void Move::operator , (int number) {
		std::cout << "XY" << std::endl;
	}

	void Move::operator = (Variable v) {
		if (moveType == "x") {
			turtle_go_to_position(v.getNumber(), v.getNumber());
		}
		else if (moveType == "y") {
			turtle_go_to_position(v.getNumber(), v.getNumber());
		}
		else if (moveType == "xy") {
			//turtle_go_to_position(v.getNumber(), v.getNumber());
			x = v.getNumber();
		}
		else if (moveType == "screenColor") {
			assert(v.getList().size() == 3);
			set_screen_color(v.getList()[0].getNumber(), v.getList()[1].getNumber(), v.getList()[2].getNumber());
		}
		else if (moveType == "setPenColor") {
			assert(v.getList().size() == 3);
			int r = v.getList()[0].getNumber(), g = v.getList()[1].getNumber(), b = v.getList()[2].getNumber();
			set_pen_color(r, g, b);
		}
		else if (moveType == "setPenSize") {
			assert(v.getList().size() == 1);
			set_pen_thickness(v.getNumber());
		}
	}

	void Move::operator = (int number) {
		if (moveType == "left") {
			turtle_rotate(-number);
		}
		else if (moveType == "right") {
			turtle_rotate(number);
		}
		else if (moveType == "forward") {
			turtle_mv_forward(number);
		}
		else if (moveType == "back") {
			turtle_mv_backward(number);
		}
		else if (moveType == "circle") {
			turtle_draw_circle(number);
		}
		return;
	}

};

