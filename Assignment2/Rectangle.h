#pragma once
#include "Movable.h"
#include "Shape.h"
#include <sstream>

class Rectangle : public Shape, public Movable { //rectangle class inherits from shape and movable
private:
	virtual void calculateArea();
	virtual void calculatePerimeter(); //these functions are virtual to allow for dynamic dispatch
	virtual void calculatePoints();
	int height, width;

public:
	Rectangle(int, int, int, int); //constructor for rectangle objects declared here
	virtual ~Rectangle();
	std::string getPoints();
	virtual void move(int,int);
	virtual void scale(float,float);
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Rectangle*); //friend funtion created to overload << operator 
};
