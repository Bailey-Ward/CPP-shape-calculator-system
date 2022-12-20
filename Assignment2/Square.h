#pragma once
#include "Movable.h"
#include "Shape.h"
#include <sstream>
#include <iterator>

class Square : public Shape, public Movable{
	int edge;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	std::string getPoints();
	Square(int, int, int);
	void move(int, int);
	void scale(float);
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Square* );
};

