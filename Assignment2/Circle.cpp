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
	points.clear(); //points vector is cleared before every calculation
	points.push_back(&leftTop); //refernce to left top is passed in
	points.push_back(new Point(leftTop.getX() + 2 * radius, leftTop.getY() + 2 * radius)); //circle only has 2 points, left top and right bottom
}

void Circle::calculateArea() { //M_PI from CMATH is used for the value of pi
	Shape::area = M_PI * radius * radius; //area is calculated by multiplying pi by radius^2
}

void Circle::calculatePerimeter() { //M_PI from CMATH is also used for the perimeter function
	Shape::perimeter = 2 * M_PI * radius; //perimeter is calculated via 2 * the value of pi * the radius input by the user
}

std::string Circle::toString() { // radius, area and perimeter are converted to strings via to_string() and added to a tempVar to be printed
	std::stringstream tempVar;
	tempVar << "Circle[r = " + std::to_string(radius) + "] \n";
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tempVar.str();
}

std::string Circle::getPoints() { //function for printing the points to the console
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter; //iterates through the vector of point references and prints them with a bracket and comma to separate points
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")";
	}
	tempVar += "]";
	return tempVar;
}

void Circle::move(int moveX, int moveY) { //gives new coordinates to a points constructor and assigns them to be the new coordinates of a given object
	leftTop = Point(moveX, moveY);
	calculatePoints(); //points are then recalculated and toString() is called
	toString();
}

void Circle::scale(float scaleX, float scaleY) { //scale only uses radius so only scaleX is used
	radius = radius * scaleX; //radius is multiplied by scaleX and then all maths functions are called on the resized shape
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

std::ostream& operator<<(std::ostream& os, Circle* c)  //friend function for operator overloading function for << operator, takes a reference to an ostream object (os) and a pointer to a circle object (c)
{	
	std::string tempVar = c->toString(); //toString is called on circle pointer and the string created is added to a tempVar
	os << tempVar.c_str(); //the tempvar is added to the output stream
	return os; //output stream is returned
}

Circle::~Circle() { //virtual circle destructor for dynamic dispatch
	std::cout << "Circle object has been deleted" << std::endl;
}