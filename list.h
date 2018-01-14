class List {
private:

	vector<Variable> pA;
	unsigned int n;

public:

	List(unsigned int n) : n(n) {}
	~List() {}


	unsigned int size() { return n; }
	unsigned int size()const { return n; }
};

