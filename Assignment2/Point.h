#pragma once
class Point {
private:
	int _xAxis, _yAxis; //private variables to restrict access

public:
	Point(void); //default constructor for points
	Point(int, int); //constructor for points
	int xAxis;
	int yAxis;
	int getX();
	int getY();
};