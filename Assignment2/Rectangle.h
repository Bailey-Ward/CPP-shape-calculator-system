#pragma once
#include "Movable.h"
#include "Shape.h"
#include <sstream>

class Rectangle : public Shape {
private:
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();
	int height, width;
public:
	Rectangle(int, int, int, int);
	std::string getPoints();
	void move(int,int);
	void scale(float,float);
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Rectangle*);

};
