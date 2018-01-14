class List {
private:
	//std::vector<Variable> vector;
public:
	List() {};

	template<class...T>
	List& operator [] (T...) {
		va_list args;
		va_start(args, list);

		while (*list != NULL) {
			vector.push_back(list);
			++list;
		}

		va_end(args);
		return rhs;
	}

	List& List::operator = (List &rhs) {
		if (this == &rhs)
			return *this;
		return rhs;
	}
};

