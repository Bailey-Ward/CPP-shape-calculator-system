#pragma once
#include "Shape.h"

class Square : public Shape{
private:
	int edge;
public:
	virtual int calculateArea(int);
	virtual int calculatePerimeter(int);
	virtual int calculatePoints(Point, int, int);
	int move();
	int scale();
	int toString();
};

