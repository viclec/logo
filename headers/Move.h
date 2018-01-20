class Move {
private:
	const char* moveType;
	int x;
	int y;
public:
	Move(const char* move) : moveType(move) {};

	void Move::operator = (Variable v) {
		if (moveType == "xy") {
			x = static_cast<int>(v.getNumber());
			y = static_cast<int>(v.getNumber());

			turtle_go_to_position(x, y);
		}
		else if (moveType == "screenColor") {
			assert(v.getList().size() == 3);
			unsigned int r = static_cast<unsigned int>(v.getList()[0].getNumber()), g = static_cast<unsigned int>(v.getList()[1].getNumber()), b = static_cast<unsigned int>(v.getList()[2].getNumber());
			set_screen_color(r, g, b);
		}
		else if (moveType == "setPenColor") {
			assert(v.getList().size() == 3);
			unsigned int r = static_cast<unsigned int>(v.getList()[0].getNumber()), g = static_cast<unsigned int>(v.getList()[1].getNumber()), b = static_cast<unsigned int>(v.getList()[2].getNumber());
			set_pen_color(r, g, b);
		}
		else if (moveType == "setPenSize") {
			assert(v.getList().size() == 1);
			set_pen_thickness(static_cast<float>(v.getNumber()));
		}else if (moveType == "left") {
			turtle_rotate(-static_cast<int>(v.getNumber()));
		}
		else if (moveType == "right") {
			turtle_rotate(static_cast<int>(v.getNumber()));
		}
		else if (moveType == "forward") {
			turtle_mv_forward(static_cast<float>(v.getNumber()));
		}
		else if (moveType == "back") {
			turtle_mv_backward(static_cast<float>(v.getNumber()));
		}
		else if (moveType == "circle") {
			turtle_draw_circle(static_cast<unsigned int>(v.getNumber()));
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
			turtle_mv_forward(static_cast<float>(number));
		}
		else if (moveType == "back") {
			turtle_mv_backward(static_cast<float>(number));
		}
		else if (moveType == "circle") {
			turtle_draw_circle(number);
		}
		return;
	}

};

