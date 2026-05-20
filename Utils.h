#pragma once
#include<memory>
#include<vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Shape;

template<typename T>
concept Cloneable = requires(const T & object)
{
	{ object.clone() }->convertible_to<unique_ptr<T>>;
};