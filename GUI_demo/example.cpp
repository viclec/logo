#include "../LOGO.h"

START_PROGRAM
	FORWARD 100;
	LEFT 100;
	FORWARD 100;
	CIRCLE 40;

	MAKE numberz = NUMBER:31
		MAKE string = WORD : "sassy"
		MAKE boolean = BOOLEAN : true

		MAKE list = LIST[NUMBER:12, NUMBER : 0, NUMBER : 0];


	IF AND(string != string, string == string) DO
		PRINT WORD : "True";
	ELIF string > string DO
		PRINT WORD: "False";
	ELSE
		PRINT WORD : "ELSE";
	END

	MAKE S = LIST[WORD:"test", NUMBER : 222, numberz, NUMBER : 444, string];
	MAKE MAN = LIST[string, S, NUMBER:666];
	MAKE SEN = SENTENCE(WORD: "This", WORD : " is ", string);

	SHOW: SEN;

	MAKE b = ARRAY SIZE : 20;

	MAKE c = ARRAY{
		numberz, string, MAN, numberz
	};

	MAKE a;
	ASSIGN a = QUOTIENT(NUMBER: 18, NUMBER : 2);
	PRINT SEN;

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