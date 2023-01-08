#include "Square.h"

Square::Square(int topLeftX, int topLeftY, int edgeLength) { //square constructor takes 3 ints, the topleft X and Y coordinates, and the length of an edge
	Square::leftTop = Point(topLeftX, topLeftY); //these values are run through the point constructor and assigned to leftTop
	edge = edgeLength; //edge is a private variable so its value is assigned here
	calculatePoints();
	calculateArea(); //maths functions are called after
	calculatePerimeter();
}

void Square::calculatePoints() { 
	points.clear(); //points vector is first cleared
	points.push_back(&leftTop); //a reference to leftTop is passed in
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY()));
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY() + edge)); //edge is then used to calculate the other 3 points (the order goes: leftTop, rightTop, rightBottom, leftBottom)
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + edge));
}

std::string Square::getPoints() { //function for printing the points to the console
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter; //iterator pointsGetter is declared to iterate through the vector
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")"; //for each Point object in the vector is appended onto the end of tempVar, with these strings being concatinated
	}
	tempVar += "]";
	return tempVar; //comma separated list of points in square brackets is returned
}

void Square::move(int moveX, int moveY) { //move function sets a new leftTop for a shape, then recalculates the points and calls the toString() function 
	leftTop = Point(moveX, moveY);
	calculatePoints();
	toString();
}

void Square::scale(float scaleX, float ScaleY) { //scales a selected shape by a float, then reperforms all the calculations
	edge = edge * scaleX;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

std::string Square::toString() { //function converts all integers to strings via the std::to_string() method and returns them
	std::stringstream tempVar;
	tempVar << "Square[e = " + std::to_string(edge) + "] \n"; //edge is returned in square brackets
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n"; //area and perimeter are returned without square brackets
	return tempVar.str();
}

void Square::calculateArea() {
	Shape::area = edge * edge; //calculations for area of a square
}

void Square::calculatePerimeter() {
	Shape::perimeter = edge * 4; //calculations for perimeter of a square
}

std::ostream& operator<<(std::ostream& os, Square* s) //operator overloading function for << operator, takes an ostream object (os) and a pointer to a square object (s)
{
	std::string tempVar = s->toString(); //toString is called on the square pointer, and then it is added to the tempVar
	os << tempVar.c_str(); //the tempVar is then added to the output stream
	return os; //when << is called to print, the modified output stream is printed instead
}

Square::~Square() {
	std::cout << "Square object has been deleted" << std::endl;
}