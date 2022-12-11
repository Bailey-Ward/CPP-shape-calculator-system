#include "Circle.h"

void Circle::calculatePoints() {
	Point rightBottom = Point(leftTop.xAxis + (2 * radius), leftTop.yAxis + (2 * radius));
	points = { leftTop, rightBottom };
}

void Circle::calculateArea() {
	int area = (M_PI * radius) * 2;
}

void Circle::calculatePerimeter() {
	int perimeter = 2 * M_PI * radius;
}
