#pragma once
#include"Shape.h"

class Circle:public Shape
{
private:
	static constexpr double PI = 3.14;
	Point center;
	double radius;

public:
	Circle() = default;
	Circle(Point center, double radius);

	double getArea()const override;
	double getPerimeter()const override;
	bool isPointInside(Point p)const override;

	unique_ptr<Shape> clone()const override;
};

