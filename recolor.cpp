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

	MAKE color
	MAKE mod

	REPEAT arg6 TIMES DO
		ASSIGN mod = MODULO(REPCOUNT, NUMBER:6)
		IF mod == 0 DO
			ASSIGN color = ITEM({ 1 }, colors)
		ELIF mod == 1 DO
			ASSIGN color = ITEM({ 2 }, colors)
		ELIF mod == 2 DO
			ASSIGN color = ITEM({ 3 }, colors)
		ELIF mod == 3 DO
			ASSIGN color = ITEM({ 4 }, colors)
		ELIF mod == 4 DO
			ASSIGN color = ITEM({ 5 }, colors)
		ELSE
			ASSIGN color = ITEM({ 6 }, colors)
		END
		SETPENCOLOR color
		RIGHT arg3
		REPEAT arg1 TIMES DO
			FORWARD arg2
			RIGHT QUOTIENT(NUMBER:360,arg1)
		END
		ASSIGN arg2 = SUM(arg2, arg4)
		ASSIGN arg1 = arg1 + arg5
	END

FEND


START_PROGRAM
	CALL bam(LIST[NUMBER:5, NUMBER : 4, NUMBER : 3, NUMBER : 5, NUMBER : 0, NUMBER : 35])
END_PROGRAM