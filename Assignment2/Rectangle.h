#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	int height, width;
public:
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	int move();
	int scale();
	int toString();

};
