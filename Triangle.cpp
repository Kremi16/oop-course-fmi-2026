#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c):Shape(),a(a),b(b),c(c){}

double Triangle::getArea()const
{
	return triangleArea(a, b, c);
}

double Triangle::getPerimeter()const
{
	return distance(a, b) + distance(a, c) + distance(b, c);
}

double Triangle::distance(Point p1, Point p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double Triangle::triangleArea(Point p1, Point p2, Point p3)const
{
	double p = getPerimeter() / 2;
	double side1 = distance(p1, p2);
	double side2 = distance(p1, p3);
	double side3 = distance(p2, p3);

	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

bool Triangle::isPointInside(Point p)const
{
	double total = getArea();
	double s1 = triangleArea(p, a, b);
	double s2 = triangleArea(p, b, c);
	double s3 = triangleArea(p, a, c);

	return abs((s1 + s2 + s3) - total) < 1e-9;
}

unique_ptr<Shape> Triangle::clone()const
{
	return make_unique<Triangle>(*this);
}