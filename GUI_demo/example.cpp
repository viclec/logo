#include "../LOGO.h"

/*** function example ***/
TO draw_square WITH args FSTART // args is a list [ length, [r,g,b] ]
SETPENCOLOR ARG(2)
REPEAT 4 TIMES
DO
FORWARD ARG(1)
RIGHT 90
END
FEND

START_PROGRAM
/***				 call function example***/
SETSCREENCOLOR LIST[SUM(NUMBER:12, NUMBER : 21), NUMBER:25, NUMBER : 0]
SETPENCOLOR LIST[SUM(NUMBER:12, NUMBER : 12), NUMBER:255, NUMBER : 255]
REPEAT 36 TIMES
DO
CALL draw_square(LIST[PRODUCT(NUMBER:12, REPCOUNT),
	LIST[SUM(NUMBER:12, REPCOUNT), NUMBER:0, NUMBER : 0]])
	RIGHT 10
	END

/*
	FORWARD 100;
	LEFT 100;
	FORWARD 100;
	CIRCLE 40;

	MAKE numberz = NUMBER:31
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

		MAKE S = LIST[WORD:"test", NUMBER : 222, numberz, NUMBER : 444, string];
	MAKE MAN = LIST[string, S, NUMBER:666];
	MAKE SEN = SENTENCE(WORD: "This", WORD : " is ", string);

	SHOW SEN;

	MAKE b = ARRAY SIZE : 20;

	MAKE c = ARRAY{
		numberz, string, MAN, numberz
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
	*/

		/*** 1st example on project pdf

		//define number variable with value 21
		MAKE number = NUMBER: 21
		//define hello variable with value “hello”
		MAKE hello = WORD : "hello"
		//define myMoves variable contains list of turtle moves
		MAKE myMoves = LIST[ //BUG vazei 5 items anti gia 3. vazei extra WORD:"FORWARD", NUMBER: 100
			LIST[WORD:"FORWARD", NUMBER : 100],
				LIST[WORD:"LEFT", NUMBER : 90],
				LIST[WORD:"FORWARD", NUMBER : 100]
		]
		//define array variable with empty array
				MAKE array = ARRAY{
					number,
					hello,
					NUMBER: 12,
							BOOLEAN : TRUE,
					ARRAY{
						myMoves,
						LIST[WORD:"BACK", NUMBER : 100]
					}
				};
				//define book variable with sentence type
			MAKE book = SENTENCE(hello, WORD: "hello!")

				CALL draw_square()
				1st example on project pdf ***/
				

END_PROGRAM