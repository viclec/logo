#include <iostream>
#include <vector>
#include "./variable.h"
#include "./statement.h"
#include "./GUI_demo/hy352_gui.h"
#include <string>
using namespace ::std;

string statementType;
vector<Statement> statements;

/*VARIABLES*/
#define MAKE variable;
#define NUMBER false?-1
#define WORD false?""
#define LIST 
#define ARRAY
#define BOOLEAN false?0
#define SENTENCE

/*ARRAY ITEMS*/
#define ITEM(iterators, arr)
#define SETITEM(iterators, arr, newValue)

/*LIST ARGUMENTS*/
#define ARG(iterator) args[i-1];

/*TURTLE MOVEMENT*/
#define SUM Sum<Variable>()
//#define DIFFERENCE
#define MINUS Minus
#define PRODUCT Product
#define QUOTIENT Quotient
#define MODULO Modulo
#define ASSIGN Assign

/*STATEMENT METHODS*/
#define DO ){ statements.size() > 0 && statements.back().getLineNumber() == __LINE__ ? statements.back().incrementRepCount() : statements.push_back(Statement(statementType, __LINE__));
#define END } statements.pop_back();

/*IF/ELIF STATEMENTS*/
#define IF statementType = "if"; if(
#define ELIF } else if(

/*REPEAT WHILE*/
#define REPEAT statementType = "repeat"; //for(int i = 0; i <
#define TIMES ; i++
#define WHILE
#define REPCOUNT statements.back().getRepCount();

/*FOREACH*/
#define FOREACH statementType = "foreach";

/*ELEM SHOW*/
#define ELEM
#define SHOW

/*BOOL OPERATORS*/
#define AND(leftCondition, rightCondition) leftCondition && rightCondition
#define OR(leftCondition, rightCondition) leftCondition || rightCondition
#define NOT(condition) !condition

/*TURTLE MOVEMENTS AND METHODS*/
#define FORWARD turtle_mv_forward
#define BACK turtle_mv_backward
#define RIGHT turtle_rotate
#define LEFT turtle_rotate
#define CENTER turtle_go_to_center
#define SETXY turtle_go_to_position
#define CIRCLE turtle_draw_circle
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
#define RETURN return
#define CALL ()

/*
template <typename Var>
Var Sum(const Var v) {
	return v;
}

template <typename Var, typename... List>
Var Sum(Var v, List... l) {
	return v + Sum(l...);
}

template <typename Var>
Var Difference(Var v1, Var v2) {
	return v1 - v2;
}

template <typename Var>
Var Minus(Var v) {
	return v * (-1);
}

template <typename Var>
Var Product(Var v1, Var v2) {
	return v1 * v2;
}

template <typename Var, typename... List>
Var Product(Var v, List... l) {
	return v * Product(l...);
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
*/