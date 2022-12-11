#include "Square.h"


void Square::calculatePoints() {
	Square::rightTop = Point(leftTop.xAxis + edge, leftTop.yAxis);
	Square::rightBottom = Point(leftTop.xAxis + edge, leftTop.yAxis + edge);
	Square::leftBottom = Point(leftTop.xAxis, leftTop.yAxis + edge);
	points = { leftTop, rightTop, rightBottom, leftBottom };
}

void Square::calculateArea() {
	int area = edge * edge;
}

void Square::calculatePerimeter() {
	int perimeter = edge * 4;
}