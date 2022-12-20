#pragma once
#define _USE_MATH_DEFINES
#include "Shape.h"
#include "Movable.h"
#include <cmath>


class Circle : public Shape, public Movable {
private:
	int radius;
public:
	Circle(int, int);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	int move();
	int scale();
	std::string toString();
};