#include "Rectangle.h"

//See square.cpp for more comprehensive documentation on functions 

Rectangle::Rectangle(int topLeftX, int topLeftY, int _height, int _width) { //Rectangle constructor takes 4 ints, the topleft X and Y coordinates, as well as the heigh and width of the rectangle
	Rectangle::leftTop = Point(topLeftX, topLeftY); //topLeftX and topLeftY are passed to the points constructor
	height = _height; //height and width are assigned values here because they are private variables and cannot be accessed directly
	width = _width;
	calculatePoints(); //maths functions are called 
	calculateArea();
	calculatePerimeter();
}

void Rectangle::calculatePoints() { //points vector is cleared, a reference to leftTop is added to the vector, and then the other points are calculated
	points.clear();
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY()));
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY() + height));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + height));
}

void Rectangle::calculateArea() { //area is calculated by multiplying height by width
	Shape::area = height * width;
}

void Rectangle::calculatePerimeter() { //perimeter is calculated by multiplying 2 by the height plus the width
	Shape::perimeter = 2 * (height + width);
}

std::string Rectangle::toString() { //adds the points to a stringsteam tempVar after toString has been called on them for printing
	std::stringstream tempVar;
	tempVar << "Rectangle[h = " + std::to_string(height) + " w = " + std::to_string(width) + "]\n";
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tempVar.str();
}

std::string Rectangle::getPoints() { //iterates through the points vector calling toString() to turn the points into strings and added them to a tempVar so they can be printed
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter;
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")";
	}
	tempVar += "]";
	return tempVar;
}

void Rectangle::move(int moveX, int moveY) { //moveX and MoveY are passed to a points constructor to give a new leftTop Point to the object being moved
	leftTop = Point(moveX, moveY);
	calculatePoints(); //once moved, points are recalculated and toString() is called
	toString();
}

void Rectangle::scale(float scaleX, float scaleY) { //both X and Y are used for scaling rectangles
	height = height * scaleX; //height is multiplied by scaleX and width is multiplied by scaleY
	width = width * scaleY;
	calculatePoints(); //points are then recalculated, maths functions are called and then toString() is called
	calculateArea();
	calculatePerimeter();
	toString();
}

std::ostream& operator<<(std::ostream& os, Rectangle* r) //friend function for operator overloading function for << operator, takes a reference to an ostream object (os) and a pointer to a rectangle object (r)
{
	std::string tempVar = r->toString(); //toString is called on the pointer r, and then it is assigned to the string tempVar
	os << tempVar.c_str(); //tempVar is then added to the output stream	
	return os; //the output stream is then returned
}

Rectangle::~Rectangle() { //virtual destructor for dynamic dispatch
	std::cout << "Rectangle object has been deleted" << std::endl;
}
