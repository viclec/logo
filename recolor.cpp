#include "./LOGO.h"

TO bam WITH args FSTART

	MAKE red = LIST[NUMBER:255, NUMBER : 0, NUMBER : 0]
	MAKE orange = LIST[NUMBER:200, NUMBER : 55, NUMBER : 0]
	MAKE yellow = LIST[NUMBER:170, NUMBER : 185, NUMBER : 0]
	MAKE green = LIST[NUMBER:0, NUMBER : 255, NUMBER : 0]
	MAKE blue = LIST[NUMBER:0, NUMBER : 0, NUMBER : 255]
	MAKE violet = LIST[NUMBER:170, NUMBER : 0, NUMBER : 185]
	MAKE colors = LIST[red, orange, yellow, green, blue, violet]

	MAKE arg1 = ARG(1)
	MAKE arg2 = ARG(2)
	MAKE arg3 = ARG(3)
	MAKE arg4 = ARG(4)
	MAKE arg5 = ARG(5)
	MAKE arg6 = ARG(6)

	REPEAT arg6 TIMES DO	//TODO fix error: argX vars don't have types
		MAKE color = ITEM({ 4 }, colors)	//TODO fix error: list Variable has to clean list when at far left
		SETSCREENCOLOR color
		RIGHT arg3
		REPEAT arg1 TIMES DO	//TODO fix error: argX vars don't have types
			FORWARD arg2
			RIGHT QUOTIENT(NUMBER:360,arg1)	//TODO fix error: argX vars don't have types
		END
		ASSIGN arg2 = SUM(arg2, arg4)
		ASSIGN arg1 = arg1 + arg5
	END

FEND


START_PROGRAM
	CALL bam(LIST[NUMBER:21, NUMBER : 21, NUMBER : 21, NUMBER : 21, NUMBER : 21, NUMBER : 21])
END_PROGRAM