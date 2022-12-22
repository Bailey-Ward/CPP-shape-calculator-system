#include "Point.h"

Point::Point() { //default constructor
	_xAxis = 0;
	_yAxis = 0;
}

Point::Point(int xAxis, int yAxis) { //Constructor for point object which contains x and y points
	_xAxis = xAxis;
	_yAxis = yAxis;
}

int Point::getX() {
	return _xAxis;
}

int Point::getY() { //^^^Getters for returning private axis variables for calculations
	return _yAxis;
}