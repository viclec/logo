#include "../LOGO.h"

START_PROGRAM

	FORWARD 100;
	LEFT 100;
	FORWARD 100;
	CIRCLE 40;

	MAKE number = NUMBER:31
		MAKE string = WORD : "sassy"
		MAKE boolean = BOOLEAN : true

		MAKE list = LIST[NUMBER:12, NUMBER : 0, NUMBER : 0];


	IF AND(string != string, string == string) DO	//TODO string comparisson 
		PRINT WORD : "True";
	ELIF string > string DO
		PRINT WORD: "False";
	ELSE
		PRINT WORD : "ELSE";
	END

		MAKE S = LIST[WORD:"test", NUMBER : 222, number, NUMBER : 444, string];
	MAKE MAN = LIST[string, S, NUMBER:666];
	MAKE SEN = SENTENCE(WORD: "This", WORD : " is ", string);

	SHOW SEN;

	MAKE b = ARRAY SIZE : 20;

	MAKE c = ARRAY{
		number, string, MAN, number
	};

	MAKE a;
	ASSIGN a = QUOTIENT(NUMBER: 18, NUMBER : 2);
	PRINT SEN;


	//SETITEM({ 3, 3, 1 }, a, WORD:"funny&sassy")
	//SETITEM({ 2 }, a, WORD:"funny&sassy")


		SETITEM({ 2,1 }, MAN, WORD: "fea")
		//ama to lala exei test tote exei mono value, ama exei fea exei reference

		MAKE aaa = SENTENCE(string, string, WORD: "is the", WORD : "NEXT big", WORD : "thing");

	PRINT string;
	PRINT aaa;
	PRINT WORD : "FEA34 fe eaf";

	MAKE test = NUMBER:32;


	REPEAT 5 TIMES DO
		FORWARD 50;
		LEFT 10;
	END

END_PROGRAM