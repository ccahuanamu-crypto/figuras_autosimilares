#include "../turtlec.h"

int main(void){
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  turtleForward(t, 300.0f);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;

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

