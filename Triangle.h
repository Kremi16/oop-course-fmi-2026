#pragma once
#include"Shape.h"

class Triangle:public Shape
{
private:
	Point a;
	Point b;
	Point c;

public:
	Triangle(Point a, Point b, Point c);

	double getArea()const override;
	double getPerimeter()const override;
	bool isPointInside(Point p)const override;

	static double distance(Point p1, Point p2);
	double triangleArea(Point p1, Point p2, Point p3)const;

	unique_ptr<Shape> clone()const override;
};

