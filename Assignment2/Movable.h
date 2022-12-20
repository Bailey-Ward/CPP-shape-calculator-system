#pragma once
class Movable {
private:

public:
	virtual void move(int, int) = 0;
	virtual void scale(float) = 0;
};