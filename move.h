class Move {
private:
	const char* moveType;
public:
	Move(const char* move) : moveType(move) {};

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
		else if (moveType == "x") {
			turtle_mv_backward(number);
		}
		else if (moveType == "y") {
			turtle_mv_backward(number);
		}
		return;
	}

	void Move::operator , (int y) {
		turtle_mv_backward(y);
	};

};

