#pragma once
#include <vector>
#include <iostream>
#include "Point.h"


class Shape { //shape is an abstract class
protected: //variables below are protected to allow derived classes to inherit
	bool isCircular; //isCircular boolean check set to false by default
	float area{};
	float perimeter{};
	Point leftTop; //leftTop variable of type Point is used for holiding topleft coordinates for calculations
	std::vector<Point*> points; //vector which holds pointers of type point
	virtual std::string getPoints() = 0;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0; //pure virtual functions declared here as they are defined in their derived classes
	virtual void calculatePoints() = 0;

public:
	virtual std::string toString() = 0;
	virtual ~Shape() {}; //virtual destructor for dynamic dispatch
};