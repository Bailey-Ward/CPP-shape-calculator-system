#pragma once
#define _USE_MATH_DEFINES
#include "Shape.h"
#include <cmath>


class Circle : public Shape {
private:
	int radius;
public:
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	int move();
	int scale();
	int toString();
};