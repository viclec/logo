#include "./LOGO.h"

TO lofos WITH args FSTART
	REPEAT 45 TIMES DO
		FORWARD 3
		RIGHT 1
	END
FEND

TO spiticabrio WITH args FSTART
	REPEAT 4 TIMES DO
		FORWARD 20
		RIGHT 90
	END
FEND

TO stegi WITH args FSTART
	REPEAT 3 TIMES DO
		FORWARD 20
		RIGHT 120
	END
FEND

TO spiti WITH args FSTART
	LEFT 90
	CALL spiticabrio(LIST[WORD:"fa"])
	FORWARD 20
	RIGHT 30
	CALL stegi(LIST[WORD:"fa"])
	LEFT 30
	BACK 20
	RIGHT 90
FEND

TO xorio WITH args FSTART
	REPEAT 3 TIMES DO
		CALL lofos(LIST[WORD:"fa"])
		CALL spiti(LIST[WORD: "fa"])
	END
	CALL lofos(LIST[WORD:"fa"])
FEND

START_PROGRAM
	SETPENCOLOR LIST[NUMBER: 100, NUMBER: 100, NUMBER: 100]
	CALL xorio(LIST[WORD: "fa"])
END_PROGRAM