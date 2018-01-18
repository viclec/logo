#include <iostream>
#include <vector>
#include "./variable.h"
#include "./Array.h"
#include "./statement.h"
#include "./GUI_demo/hy352_gui.h"
#include "./move.h"
#include "./list.h"
#include <string>
using namespace ::std;

string statementType;
vector<Statement> statements;
//List funcArgs;

/*VARIABLES*/
#define MAKE ;Variable
#define NUMBER Variable()=false?-1
#define WORD Variable()=false?""
#define BOOLEAN Variable()=false?0
#define LIST Variable()
#define ARRAY Variable a[]=
#define SIZE false?-1
#define SENTENCE(...) Sentence<Variable>(__VA_ARGS__)

/*ARRAY ITEMS*/
#define ITEM(...) getItem<int>(__VA_ARGS__);
#define SETITEM(...) setItem<int>(__VA_ARGS__);

/*LIST ARGUMENTS*/
#define ARG(iterator) ;args[i-1];

/*TURTLE MOVEMENT*/
#define SUM(...) Sum<Variable>(__VA_ARGS__)
#define DIFFERENCE(...) Difference<Variable>(__VA_ARGS__)
#define MINUS(...) Minus<Variable>(__VA_ARGS__)
#define PRODUCT(...) Product<Variable>(__VA_ARGS__)
#define QUOTIENT(...) Quotient<Variable>(__VA_ARGS__)
#define MODULO(...) Modulo<Variable>(__VA_ARGS__)
#define ASSIGN(...) Assign<Variable>(__VA_ARGS__)

#define __NL__ ;

/*STATEMENT METHODS*/
#define DO ){	//TODO add ; for repeats 
#define END } statements.pop_back();

/*IF/ELIF STATEMENTS*/
#define IF ;statements.push_back(Statement("if", __LINE__)); if(
#define ELIF } else if(
#define ELSE } else if(true){

/*REPEAT WHILE*/
#define REPEAT ;statements.push_back(Statement("repeat", __LINE__)); for(statements.back().initRepCount();
#define TIMES != statements.back().getRepCount(); statements.back().incrementRepCount()
#define WHILE false?false:
#define REPCOUNT ;statements.back().getRepCount();

/*FOREACH*/
#define FOREACH ;statements.push_back(Statement("foreach", __LINE__);  for(auto i = 0;

/*ELEM SHOW*/
#define ELEM
#define SHOW

/*BOOL OPERATORS*/
#define AND(leftCondition, rightCondition) leftCondition && rightCondition
#define OR(leftCondition, rightCondition) leftCondition || rightCondition
#define NOT(condition) !condition

/*TURTLE MOVEMENTS AND METHODS*/
#define FORWARD Move("forward")=
#define BACK Move("back")=
#define RIGHT Move("right")=
#define LEFT Move("left")=
#define CENTER turtle_go_to_center();
#define SETXY SETX SETY	//TODO SETXY 50 50
#define SETX Move("x")=
#define SETY Move("y")=
#define CIRCLE Move("circle")=
#define PRINT_WORD turtle_draw_label

/*TURTLE MOVEMENT*/
#define SETPENCOLOR set_pen_color
#define SETSCREENCOLOR set_screen_color
#define SETPENSIZE set_pen_thickness
#define PENDOWN pen_down();
#define PENUP pen_up();

/*FUNCTIONS*/
#define TO void
#define WITH (
#define FSTART ){
#define FEND }
#define RETURN return;
#define CALL(...) (__VA_ARGS__); funcArgs = __VA_ARGS__;

template <typename T>
Variable getItem(initializer_list<T> l, Variable& var)
{
	const T*       it = l.begin();
	const T* const end = l.end();
	int i = 0;

	std::vector<Variable> array;
	
	array.push_back(var.getList()[*(it++)-1]);
	for (i = 0; it != end; it++, i++) {
		array.push_back(array[i].getList()[*(it) - 1]);
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

	array.push_back(var.getList()[*(it++) - 1]);

	for (i = 0; it != end; it++, i++) {
		array.push_back(array[i].getList()[*(it)-1]);
	}
	array.pop_back();
	array.push_back(value);



	return Variable();

}

void printArgs(initializer_list <int> iterator, Variable arr[]) {
	const int*       it = iterator.begin();  // raw pointer!
	const int* const end = iterator.end();    // raw pointer!

	std::vector<int> v;

	for (; it != end; ++it)
		v.push_back(*it);
};

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
Var Assign(Var v1, Var v2) {
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

/* ################################################ */

std::vector<Variable>* new_list() {
	return new std::vector<Variable>;
} 

