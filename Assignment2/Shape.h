#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class Shape {
private:
	
	bool isCircular = false;
	
protected:
	int area{};
	int perimeter{};
	Point leftTop;
	std::vector<Point*> points;
	virtual std::string getPoints() = 0;

public:
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	void toString();
};