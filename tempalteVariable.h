template<class T>
class Variable {	//TODO check class templates
private:
	T value;
public:
	Variable() {};
	Variable(T value) : value(value) {};
	bool operator==(Variable other) {
		return (value == other.value && value != NULL);
	};

	Variable& Variable::operator = (Variable &other) {
		if (this == &other)
			return *this;
		return other;
	};

	Variable& Variable::operator = (T other) {
		return Variable<T>(other);
	};
};