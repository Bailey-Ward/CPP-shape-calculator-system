#pragma once
class Point {
private:
	int _xAxis, _yAxis;

public:
	Point(void);
	Point(int, int);
	int xAxis;
	int yAxis;
	void setX();
	void setY();
	int getX();
	int getY();
};