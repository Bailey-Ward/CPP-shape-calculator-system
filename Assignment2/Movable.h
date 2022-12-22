#pragma once
class Movable {
public:
	virtual void move(int, int) = 0; //These methods are pure virtual as this is an abstract class
	virtual void scale(float, float) = 0;
};