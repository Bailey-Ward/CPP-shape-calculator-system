#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	int radius;
public:
	int calculateArea();
	int calculatePerimeter();
	int calculatePoints();
	int move();
	int scale();
	int toString();
};