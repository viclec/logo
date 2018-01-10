#include <iostream>
#include <vector>
#include "./statement.h"
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
#define ITEM
#define SETITEM

/*TURTLE MOVEMENT*/
#define SUM
//#define DIFFERENCE
#define MINUS
#define PRODUCT
#define QUOTIENT
#define MODULO
#define ASSIGN

/*STATEMENT METHODS*/
#define DO ){ statements.push_back(Statement(statementType));
#define END } statements.pop_back();

/*IF/ELIF STATEMENTS*/
#define IF statementType="if";if(
#define ELIF } else if(

/*REPEAT WHILE*/
#define REPEAT statementType="repeat"; for(int i = 0; i <
#define TIMES ; i++
#define WHILE
#define REPCOUNT

/*FOREACH*/
#define FOREACH statementType="repeat";

/*ELEM SHOW*/
#define ELEM
#define SHOW

/*BOOL OPERATORS*/
#define AND
#define OR
#define NOT

/*TURTLE MOVEMENTS AND METHODS*/
#define FORWARD
#define BACK
#define RIGHT
#define LEFT
#define CENTER
#define SETXY
#define CIRCLE
#define PRINT_WORD

/*TURTLE MOVEMENT*/
#define SETPENCOLOR
#define SETSCREENCOLOR
#define SETPENSIZE
#define PENDOWN
#define PENUP

/*FUNCTIONS*/
#define TO void
#define WITH
#define FSTART {
#define FEND }
#define RETURN return
#define CALL ()