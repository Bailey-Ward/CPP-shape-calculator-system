#pragma once
#include "Shape.h"

class Square : public Shape{
private:
	int edge;
public:
	int calculateArea();
	int calculatePerimeter();
	int calculatePoints();
	int move();
	int scale();
	int toString();
};

