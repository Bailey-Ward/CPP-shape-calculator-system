#pragma once
#include "Movable.h"
#include "Shape.h"

class Square : public Shape{
private:
	Point rightTop;
	Point rightBottom;
	Point leftBottom;
	int edge;
public:
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	int move();
	int scale();
	int toString();
};

