#include <stdio.h>
#include <vector>
#include <allegro5/allegro.h>
#include "./defines.h"
using namespace ::std;

int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
   
   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

	MAKE number = NUMBER:31
	MAKE string = WORD : "sassy"
	MAKE boolean = BOOLEAN : true

	// MAKE list = LIST{ NUMBER:12, NUMBER : 0, NUMBER : 0 }


	IF (!(number) || !(number == (NUMBER:31))) DO	//TODO string comparisson 
		cout << "True";
	ELIF number >= (NUMBER:21) DO
		cout << "False";
	ELSE
		cout << "ELSE";
	END

	MAKE S = LIST[WORD:"test", NUMBER : 222, number, NUMBER : 444, string];
	MAKE MAN = LIST[string,S, NUMBER:666];
	MAKE SEN = SENTENCE((WORD: "This", WORD : " is", string));
	ARRAY{
		string, number,
		MAN
	};


	MAKE LALA = ITEM({ 2, 3 }, MAN)


	SETITEM({ 2,1 }, MAN, WORD: "fea")
	//ama to lala exei test tote exei mono value, ama exei fea exei reference

		MAKE aaa = SENTENCE(string, string, WORD: "is the", WORD:"NEXT big", WORD:"thing")



	MAKE av = DIFFERENCE(NUMBER:12, LALA);
	
	MAKE fdsa = MODULO(NUMBER:12, NUMBER:3);

	MAKE test = NUMBER:32;

	ASSIGN fdsa = DIFFERENCE(NUMBER:12, LALA);


	REPEAT 5 TIMES DO
		std::cout << "repeat";
	END
	
		
   al_clear_to_color(al_map_rgb(0,0,0));
   
   al_flip_display();

   al_rest(10.0);

   al_destroy_display(display);


   return 0;
}