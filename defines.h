#include <iostream>
#include <vector>
#include "./variable.h"
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
#define ARRAY List()=
#define SENTENCE ;

/*ARRAY ITEMS*/
#define ITEM(iterators, arr) ;
#define SETITEM(iterators, arr, newValue) ;

/*LIST ARGUMENTS*/
#define ARG(iterator) ;args[i-1];

/*TURTLE MOVEMENT*/
#define SUM ;Sum<Variable>()
//#define DIFFERENCE
#define MINUS ;Minus<Variable>
#define PRODUCT ;Product<Variable>
#define QUOTIENT ;Quotient<Variable>
#define MODULO ;Modulo<Variable>
#define ASSIGN ;Assign<Variable>

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

template <typename Var>
Variable Sum(const Var v) {
	return v;
};

template <typename... List>
Variable Sum(Variable v, List... l) {
	return v + Sum(l...);
};

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

/* ################################################ */

std::vector<Variable>* new_list() {
	return new std::vector<Variable>;
} 

