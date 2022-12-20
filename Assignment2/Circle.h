#pragma once
#define _USE_MATH_DEFINES
#include "Shape.h"
#include "Movable.h"
#include <cmath>
#include <sstream>

class Circle : public Shape, public Movable {
private:
	float radius;
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual void calculatePoints();

public:
	Circle(int, int, float);
	std::string getPoints();
	void move(int,int);
	void scale(float);
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, Circle*);
};