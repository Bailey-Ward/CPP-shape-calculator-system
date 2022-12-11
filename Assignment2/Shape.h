#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class Shape {
private:
	
	bool isCircular = false;
	
protected:
	int area;
	int perimeter;
	Point leftTop;
	std::vector<Point> points{ Point(0,0), Point(0,0), Point(0,0), Point(0,0) };
public:
	virtual void calculateArea(void);
	virtual void calculatePerimeter(void);
	virtual void calculatePoints() = 0;
	void toString();
};