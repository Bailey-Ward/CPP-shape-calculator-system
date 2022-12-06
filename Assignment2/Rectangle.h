#pragma once
class Rectangle {
private:
	int height;
	int width;
public:
	int calculateArea();
	int calculatePerimeter();
	int calculatePoints();
	int move();
	int scale();
	int toString();

};
