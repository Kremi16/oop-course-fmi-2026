#pragma once
#include"Shape.h"

class Rectangle:public Shape
{
private:
	Point topLeft;
	Point bottomRight;

public:
	Rectangle(Point topLeft, Point bottomRight);

	double getArea()const override;
	double getPerimeter()const override;
	bool isPointInside(Point p)const override;

	unique_ptr<Shape> clone()const override;
};

