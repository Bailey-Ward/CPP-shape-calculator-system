#include "Rectangle.h"

//See square.cpp for more comprehensive documentation on functions as they are similar and I'm too lazy to retype the same comments

Rectangle::Rectangle(int topLeftX, int topLeftY, int _height, int _width) { //Rectangle constructor takes 4 ints, the topleft X and Y coordinates, as well as the heigh and width of the rectangle
	Rectangle::leftTop = Point(topLeftX, topLeftY);
	height = _height;
	width = _width;
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

void Rectangle::calculatePoints() {
	points.clear();
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY()));
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY() + height));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + height));
}

std::string Rectangle::getPoints() {
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter;
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")";
	}
	tempVar += "]";
	return tempVar;
}

void Rectangle::move(int moveX, int moveY) {
	leftTop = Point(moveX, moveY);
	calculatePoints();
	toString();
}

void Rectangle::scale(float scaleX, float scaleY) {
	height = height * scaleX;
	width = width * scaleY;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

void Rectangle::calculateArea() {
	 Shape::area = height * width;
}

void Rectangle::calculatePerimeter() {
	Shape::perimeter = 2*(height + width);
}

std::string Rectangle::toString() {
	std::stringstream tempVar;
	tempVar << "Rectangle[h = " + std::to_string(height) + " w = " + std::to_string(width) + "]\n";
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tempVar.str();
}

std::ostream& operator<<(std::ostream& os, Rectangle* r)
{
	std::string tempVar = r->toString();
	os << tempVar.c_str();
	return os;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle object has been deleted" << std::endl;
}
