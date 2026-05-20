#include "Rectangle.h"
#include<stdexcept>

Rectangle::Rectangle(Point topLeft, Point bottomRight):Shape(),
topLeft(topLeft),bottomRight(bottomRight){ }

double Rectangle::getArea()const
{
	double a = abs(bottomRight.x - topLeft.x);
	double b = abs(bottomRight.y - topLeft.y);
	return a * b;
}

double Rectangle::getPerimeter()const
{
	double a = abs(bottomRight.x - topLeft.x);
	double b = abs(bottomRight.y - topLeft.y);
	return 2 * a + 2 * b;
}

bool Rectangle::isPointInside(Point p)const
{
	return p.x >= topLeft.x && p.x <= bottomRight.x &&
		p.y >= topLeft.y && p.y <= bottomRight.y;
}

unique_ptr<Shape> Rectangle::clone()const
{
	return make_unique<Rectangle>(*this);
}