#include "../turtlec.h"


  void fractalTree(Turtle *turtle, float len, int depth){
	if(depth == 0 || len < 5)
	      	return;
	turtleForward(turtle, len);

	turtleLeft(turtle, 30);
	fractalTree(turtle, len * 0.7, depth - 1);

	turtleRight(turtle, 60);
	fractalTree(turtle, len * 0.7, depth - 1);

	turtleLeft(turtle, 30);
	turtleBackward(turtle, len);
}

int main(void){
  TurtleApp *app = turtleAppCreate(800, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 400.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  fractalTree(t, 300, 4);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

