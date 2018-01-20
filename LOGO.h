#ifdef APPLE
#include <allegro5/allegro.h> //**
#endif
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include "./GUI_demo/hy352_gui.h"
#include "./headers/Variable.h"
#include "./headers/Statement.h"
#include "./headers/Print.h"
#include "./headers/Move.h"
using namespace ::std;

vector<Statement> statements;

/*VARIABLES*/
#define MAKE ;Variable
#define NUMBER Variable("number")=false?-1
#define WORD Variable("word")=false?""
#define BOOLEAN Variable("number")=false?0
#define LIST Variable("list")
#define ARRAY Variable("array")=
#define SIZE false?-1
#define SENTENCE(...) Sentence<Variable>(__VA_ARGS__)

/*ARRAY ITEMS*/
#define ITEM(...) getItem<int>(__VA_ARGS__)
#define SETITEM(...) setItem<int>(__VA_ARGS__)	//TODO

/*LIST ARGUMENTS*/
#define ARG(i) (args.getList()[i-1].getType().std::string::compare("number")==0)?args.getList()[i-1].getNumber() : args.getList()[i-1];
//#define ARG(i) args.getList()[i-1];
//#define ARG(i) args.getList()[i-1].getNumber();

/*BOOL CONSTANTS*/
#define TRUE true
#define FALSE false

/*TURTLE MOVEMENT*/
#define SUM(...) Sum<Variable>(__VA_ARGS__)
#define DIFFERENCE(...) Difference<Variable>(__VA_ARGS__)
#define MINUS(...) Minus<Variable>(__VA_ARGS__)
#define PRODUCT(...) Product<Variable>(__VA_ARGS__)
#define QUOTIENT(...) Quotient<Variable>(__VA_ARGS__)
#define MODULO(...) Modulo<Variable>(__VA_ARGS__)
#define ASSIGN ;

#define __NL__ ;

/*STATEMENT METHODS*/
#define DO ){	//TODO add ; for repeats 
#define END ;} statements.pop_back();

/*IF/ELIF STATEMENTS*/
#define IF ;statements.push_back(Statement("if", __LINE__)); if(
#define ELIF ;} else if(
#define ELSE ;} else if(true){

/*REPEAT WHILE*/
#define REPEAT ;statements.push_back(Statement("repeat", __LINE__)); for(statements.back().initRepCount();
#define TIMES != statements.back().getRepCount(); statements.back().incrementRepCount()
#define WHILE false?false:
#define REPCOUNT (Variable("number")=statements.back().getRepCount())

/*FOREACH*/
#define FOREACH ;statements.push_back(Statement("foreach", __LINE__));  for(auto &i :
#define ELEM i

/*SHOW*/
#define SHOW cout << 

/*PROGRAM DEFINES*/
#define START_PROGRAM int main(int argc, char **argv){const char *msg = "START";init_GUI();
#define END_PROGRAM ;destroy_GUI();return 0;}

/*BOOL OPERATORS*/
#define AND(...) And<bool>(__VA_ARGS__)
#define OR(...) Or<bool>(__VA_ARGS__)
#define NOT(...) Not(__VA_ARGS__)

/*TURTLE MOVEMENTS AND METHODS*/
#define FORWARD ;Move("forward")=
#define BACK ;Move("back")=
#define RIGHT ;Move("right")=
#define LEFT ;Move("left")=
#define CENTER ;turtle_go_to_center();
#define SETXY ;Move("xy")=
#define CIRCLE ;Move("circle")=
#define PRINT ;Print()=

/*TURTLE MOVEMENT*/
#define SETPENCOLOR ;Move("setPenColor")=
#define SETSCREENCOLOR ;Move("screenColor")=
#define SETPENSIZE ;Move("setPenSize")=
#define PENDOWN ;pen_down();
#define PENUP ;pen_up();

/*FUNCTIONS*/
#define TO ;void
#define WITH (Variable args){
#define FSTART ;
#define FEND ;}
#define RETURN ;return;
#define CALL ;

template <typename T>
Variable getItem(initializer_list<T> l, Variable& var)
{
	const T*       it = l.begin();
	const T* const end = l.end();
	int i = 0;

	std::vector<Variable> array;
	if (var.getType() == "array") {
		array.push_back(var.getArray()[*(it++) - 1]);
	}
	else {
		array.push_back(var.getList()[*(it++) - 1]);
	}
	for (i = 0; it != end; it++, i++) {
		if (array[i].getType() == "array") {
			array.push_back(array[i].getArray()[*(it)-1]);
		}
		else {
			array.push_back(array[i].getList()[*(it)-1]);
		}
	}

	return array[array.size() - 1];
}

template <typename T>
Variable setItem(initializer_list<T> l, Variable& var, Variable& value)
{

	const T*       it = l.begin();
	const T* const end = l.end();
	int i = 0;

	std::vector<Variable> array;


	if (var.getType() == "array") {
		array.push_back(var.getArray()[*(it++) - 1]);
	}
	else {
		array.push_back(var.getList()[*(it++) - 1]);
	}

	for (i = 0; it != end; it++, i++) {
		if (array[i].getType() == "array") {
			array.push_back(array[i].getArray()[*(it)-1]);
		}
		else {
			array.push_back(array[i].getList()[*(it)-1]);
		}
	}

	array.pop_back();
	array.push_back(value);



	return Variable();

}

template <typename Var>
bool And(bool b) {
	return b;
}
template <typename... List>
bool And(bool b, List... l) {
	return b && And<bool>(l...);
}

template <typename Var>
bool Or(bool b) {
	return b;
}
template <typename... List>
bool Or(bool b, List... l) {
	return b || Or<bool>(l...);
}

bool Not(bool b) {
	return !b;
}

template <typename Var>
Variable Sum(const Var v) {
	return v;
};
template <typename... List>
Variable Sum(Variable v, List... l) {
	return v + Sum<Variable>(l...);
};

template <typename Var>
Var Difference(Var v1, Var v2) {
	return v1 - v2;
}

template <typename Var>
Var& Minus(Var v) {
	return v * (-1);
}

template <typename Var>
Var Product(Var v1, Var v2) {
	return v1 * v2;
}

template <typename Var, typename... List>
Var Product(Var v, List... l) {
	return v * Product<Variable>(l...);
}

template <typename Var>
Var Quotient(Var v1, Var& v2) {
	return v1 / v2;
}

template <typename Var>
Var Modulo(Var v1, Var v2) {
	return v1 % v2;
}

template <typename Var>
Var& Assign(Var& v1, Var v2) {
	return v1 = v2;
}

template <typename Var>
Var Sentence(Var v) {
	return v << v;
}

template <typename Var, typename... List>
Var Sentence(Var v, List... l) {
	

	v << Sentence<Variable>(l...);
	return v;
}

