#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class Shape {
private:
	int area;
	bool isCircular;
	Point leftTop;
	int perimeter;
	std::vector<Point> points;
public:
	virtual void calculateArea(void);
	virtual void calculatePerimeter(void);
	virtual void calculatePoints(void);
	void toString();
};