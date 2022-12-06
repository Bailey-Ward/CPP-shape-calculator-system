#pragma once
class Shape {
private:
	int area;
	int isCircular;
	int leftTop;
	int perimeter;
	int points;
public:
	int calculateArea();
	int calculatePerimeter();
	int calculatePoints();
	int toString();
};