#pragma once
#define _USE_MATH_DEFINES
#include "Shape.h"
#include "Movable.h"
#include <cmath>
#include <sstream>

class Circle : public Shape, public Movable { //circle class inherits from shape and moveable
private:
	int radius;
	virtual void calculateArea();
	virtual void calculatePerimeter(); //these functions are virtual to allow for dynamic dispatch
	virtual void calculatePoints();

public:
	Circle(int, int, int); //constructor for square objects declared here
	virtual ~Circle(); //virtual destructor for each child class
	std::string getPoints();
	virtual void move(int,int);
	virtual void scale(float,float);
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Circle*); //friend funtion created to overload << operator 
};