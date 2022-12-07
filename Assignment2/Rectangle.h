#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	int height;
	int width;
public:
	int calculateArea();
	int calculatePerimeter();
	int calculatePoints();
	int move();
	int scale();
	int toString();

};
