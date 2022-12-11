#include "Square.h"


void Square::calculatePoints() {
	Square::rightTop = Point(leftTop.xAxis + edge, leftTop.yAxis);
	Square::rightBottom = Point(leftTop.xAxis + edge, leftTop.yAxis + edge);
	Square::leftBottom = Point(leftTop.xAxis, leftTop.yAxis + edge);
	points = { leftTop, rightTop, rightBottom, leftBottom };
}

void Square::calculateArea() {
	Shape::area = edge * edge;
}

void Square::calculatePerimeter() {
	Shape::perimeter = edge * 4;
}