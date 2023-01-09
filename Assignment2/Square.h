#pragma once
#include "Movable.h"
#include "Shape.h"
#include <sstream>
#include <iterator>
#include <iomanip>

class Square : public Shape, public Movable{ //square class inherits from shape and movable
	int edge;
	virtual void calculateArea();
	virtual void calculatePerimeter(); //these functions are virtual to allow for dynamic dispatch
	virtual void calculatePoints();

public:

	Square(int, int, int); //constructor for square objects declared here
	virtual ~Square(); //virtual destructor for each child class
	std::string getPoints();
	virtual void move(int, int);
	virtual void scale(float, float); 
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Square*); //friend funtion created to overload << operator 
};

