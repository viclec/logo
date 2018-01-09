#include <string>
using namespace ::std;

// Collor in rgb value
class Color_pallete
{
public:
  unsigned red;
  unsigned green;
  unsigned blue;
};

// Point in canvas/display
class Point
{
public:
  unsigned x;
  unsigned y;
};

// Abstract class, represent the notion of a graphic element
class Shape
{
public:
  unsigned thickness;
  Color_pallete color;
  bool draw;
  virtual string getName() = 0;
};

// Circle with center and radius
class Circle : public Shape
{
public:
  Point center;
  unsigned radius;
  string getName()
  {
    return "Circle";
  };
};

// Line between points start and end
class Line : public Shape
{
public:
  Point start;
  Point end;
  string getName()
  {
    return "Line";
  };
};

// Label in a specific point
class Label : public Shape
{
public:
  char *text;
  Point point;
  string getName()
  {
    return "Label";
  };
};

// Rotate turtle by d degrees relatively to current turtle direction
void turtle_rotate(int d);

// Draw circle with center the current position of the turtle and radius r
void turtle_draw_circle(unsigned r);

// Move the turtle forward
int turtle_mv_forward(float n);

// Move the turtle backward
int turtle_mv_backward(float n);

// Set the color of the pen
int set_pen_color(unsigned r, unsigned g, unsigned b);

// Set the color of the screen
int set_screen_color(unsigned r, unsigned g, unsigned b);

// Set the thickness of the pen
void set_pen_thickness(float thickness);

// Raise up the pen
void pen_up();

// Put down the pen
void pen_down();

// Move the turtle to the target position without drawing
int turtle_go_to_position(unsigned x, unsigned y);

// Move the turtle to the center of the display without drawing
int turtle_go_to_center();

// Turtle writes a label
int turtle_draw_label(char const *text);

// Initialize the GUI (display, init allegro addons etc)
int init_GUI();

// Release the memory of GUI elements
void destroy_GUI();

// Show debug message
int show_debug_message(char const *msg);

// Freeze the execution for s seconds
void wait(unsigned s);

// Defines number pi
#define PI 3.14159265

// Converts degrees to radians.
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0)

// Converts radians to degrees.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI)
