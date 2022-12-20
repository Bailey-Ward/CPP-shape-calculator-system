#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class Shape {
protected:
	bool isCircular;
	float area{};
	float perimeter{};
	Point leftTop;
	std::vector<Point*> points;
	virtual std::string getPoints() = 0;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;

public:
	virtual std::string toString() = 0;
};