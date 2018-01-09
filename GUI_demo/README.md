# CS352_GUI_API
API definition and implemention for using Allegro 5 library in course cs352 


> Windows users

 - Build and run using visual studio editor



> Linux users

COMPILE: 
	g++ hy352_gui.cpp example.cpp -o hy352_demo  $(pkg-config --libs allegro-5 allegro_image-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5)



> Mac users

COMPILE: 
	g++ hy352_gui.cpp example.cpp  -o hy352_demo  -lallegro -lallegro_primitives -lallegro_image -lallegro_ttf -lallegro_font -lallegro_main
