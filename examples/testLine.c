#include "../turtlec.h"
#include <math.h>

void fractalTree(Turtle *turtle, float len, int depth){
  if(depth == 0 || len < 5)
	      	return;

  if (depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else 
    turtleSetColor(turtle, 0, 200, 0);

	turtleForward(turtle, len);

	turtleLeft(turtle, 30);
	fractalTree(turtle, len * 0.7, depth - 1);

	turtleRight(turtle, 60);
	fractalTree(turtle, len * 0.7, depth - 1);

  turtleRight(turtle, 30);
  fractalTree(turtle, len * 0.7, depth - 1):

	turtleLeft(turtle, 30);
	turtleBackward(turtle, len);
}

void levy(Turtle *turtle, float len, int depth){
  if (depth == 0){
    turtleForward(turtle, len);
    return;
  }

  turtleLeft(turtle, 45);
  levy(turtle, len / sqrt(2), depth - 1);
  
  turtleRight(turtle, 90);
  levy(turtle, len / sqrt(2), depth - 1);

  turtleLeft(turtle, 45);
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 400.0f);
  turtlePenDown(t);

  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 300, 4);
  levy(t, 300, 3);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

