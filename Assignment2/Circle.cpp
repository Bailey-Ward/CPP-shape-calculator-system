#include "Circle.h"

//See square.cpp for more comprehensive documentation on functions 

Circle::Circle(int topLeftX, int topLeftY, int cRadius) //circle constructor takes 3 ints, the topleft X and Y coordinates, and the length of the radius
{
	leftTop = Point(topLeftX, topLeftY); //topleftX and topleftY are passed to the points constructor to create a point object which is assigned to leftTop
	radius = cRadius; //cRadius is assigned to radius because radius is a private variable and cannot be directly accessed
	calculatePoints(); //maths functions are called
	calculateArea();
	calculatePerimeter();
}

void Circle::calculatePoints() { //only 2 points are calculated here, leftTop and rightBottom (as per the brief)
	points.clear();
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + 2 * radius, leftTop.getY() + 2 * radius));
}

std::string Circle::getPoints() {
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter;
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")";
	}
	tempVar += "]";
	return tempVar;
}

std::string Circle::toString() {
	std::stringstream tempVar;
	tempVar << "Circle[r = " + std::to_string(radius) + "] \n";
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tempVar.str();
}

void Circle::move(int moveX, int moveY) {
	leftTop = Point(moveX, moveY);
	calculatePoints();
	toString();
}

void Circle::scale(float scaleX, float scaleY) {
	radius = radius * scaleX;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

void Circle::calculateArea() {
	Shape::area = M_PI * radius * radius;
}

void Circle::calculatePerimeter() {
	Shape::perimeter = 2 * M_PI * radius;
}

std::ostream& operator<<(std::ostream& os, Circle* c)
{
	std::string tempVar = c->toString();
	os << tempVar.c_str();
	return os;
}

Circle::~Circle() {
	std::cout << "Circle object has been deleted" << std::endl;
}