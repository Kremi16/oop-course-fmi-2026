#include "Circle.h"
#include<stdexcept>

Circle::Circle(Point center, double radius) :Shape(),center(center)
{
	if (radius < 0.0)
	{
		throw invalid_argument("The radius cannot be negative.");
	}
	this->radius = radius;
}

double Circle::getArea()const
{
	return PI * radius * radius;
}

double Circle::getPerimeter()const 
{
	return 2 * PI * radius;
}

bool Circle::isPointInside(Point p)const
{
	double dist = sqrt(pow(center.x - p.x, 2) + pow(center.y - p.y, 2));
	return dist < radius;
}

unique_ptr<Shape> Circle::clone()const
{
	return make_unique<Circle>(*this);
}