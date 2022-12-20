#include "Square.h"


Square::Square(int topLeftX, int topLeftY, int edgeLength) {
	Square::leftTop = Point(topLeftX, topLeftY);
	edge = edgeLength;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}


void Square::calculatePoints() {
	points.clear();
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY()));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + edge));
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY() + edge));
}

std::string Square::getPoints() {
	std::string tempVar = "Points[";
	std::vector<Point*>::iterator pointsGetter;
	for (pointsGetter = points.begin(); pointsGetter < points.end(); pointsGetter++)
	{
		tempVar += "(" + std::to_string((*pointsGetter)->getX()) + "," + std::to_string((*pointsGetter)->getY()) + ")";
	}
	tempVar += "]";
	return tempVar;
}

void Square::move(int moveX, int moveY) {
	leftTop = Point(moveX, moveY);
	calculatePoints();
	toString();
}

void Square::scale(float scale) {
	edge = edge * scale;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

std::string Square::toString() {
	std::stringstream tempVar;
	tempVar << "Square[e = " + std::to_string(edge) + "] \n";
	tempVar << getPoints().c_str();
	tempVar << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return tempVar.str();
}

void Square::calculateArea() {
	Shape::area = edge * edge;
}

void Square::calculatePerimeter() {
	Shape::perimeter = edge * 4;
}

std::ostream& operator<<(std::ostream& os, Square* s)
{
	std::string tempVar = s->toString();
	os << tempVar.c_str();
	return os;
}