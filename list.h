class List {
private:

	vector<Variable> items;
	unsigned int n;

public:

	List() {};
	List(unsigned int n) : n(n) {};
	~List() {};

	template<class...T>
	List& List::operator , (T v...) {
		items.push_back(v);
		return *this;
	}

	List& List::operator , (Variable &v) {
		items.push_back(v);
		return *this;
	}

	List& List::operator = (Variable &v) {
		items.push_back(v);
		return *this;
	}

	Variable& operator[](unsigned int i) { return items.at(i); }
	const Variable& operator[](unsigned int i)const { return items.at(i); }

	Variable& operator()(unsigned int i) { return items.at(i); }
	const Variable& operator()(unsigned int i)const { return items.at(i); }

	unsigned int size() { return n; }
	unsigned int size()const { return n; }
};

