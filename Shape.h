#pragma once
#include"Utils.h"

class Shape
{
public:
	Shape() = default;
	virtual double getArea()const = 0;
	virtual double getPerimeter()const = 0;
	virtual bool isPointInside(Point p)const = 0;
	virtual ~Shape() = default;

	virtual unique_ptr<Shape> clone()const = 0;
};

