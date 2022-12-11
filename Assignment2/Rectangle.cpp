#include "Rectangle.h"

void Rectangle::calculatePoints() {
	Point rightTop = Point(leftTop.xAxis + width, leftTop.yAxis);
	Point rightBottom = Point(leftTop.xAxis + width, leftTop.yAxis + height);
	Point leftBottom = Point(leftTop.xAxis, leftTop.yAxis + height);
	points = { leftTop, rightTop, rightBottom, leftBottom };
}

void Rectangle::calculateArea() {
	 Shape::area = height * width;
}

void Rectangle::calculatePerimeter() {
	Shape::perimeter = 2*(height + width);
}