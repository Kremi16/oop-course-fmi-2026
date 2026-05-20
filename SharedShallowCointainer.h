#pragma once
#include"Utils.h"
#include<stdexcept>

template<Cloneable T>
class SharedShallowCointainer
{
private:
	vector<shared_ptr<T>> data;

public:
	SharedShallowCointainer() = default;
	
	SharedShallowCointainer(const SharedShallowCointainer<T>& other);
	SharedShallowCointainer<T>& operator=(const SharedShallowCointainer<T>& other);

	void add(shared_ptr<T> object);
	void remove(size_t index);
	const T& operator[](size_t index)const;
	T& operator[](size_t index);

	auto begin();
	auto end();
	auto cbegin()const;
	auto cend()const;
	size_t size()const;
};

template<Cloneable T>
SharedShallowCointainer<T>::SharedShallowCointainer(const SharedShallowCointainer<T>& other)
{
	data = other.data;
}

template<Cloneable T>
SharedShallowCointainer<T>& SharedShallowCointainer<T>::operator=(const SharedShallowCointainer<T>& other)
{
	if (other != this)
	{
		data.clear();
		data = other.data;
	}
	return *this;
}

template<Cloneable T>
void SharedShallowCointainer<T>::add(shared_ptr<T> object)
{
	data.push_back(object);
}

template<Cloneable T>
void SharedShallowCointainer<T>::remove(size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	data.erase(data.begin() + index);
}

template<Cloneable T>
auto SharedShallowCointainer<T>::begin()
{
	return data.begin();
}

template<Cloneable T>
auto SharedShallowCointainer<T>::end()
{
	return data.end();
}

template<Cloneable T>
auto SharedShallowCointainer<T>::cbegin()const
{
	return data.cbegin();
}

template<Cloneable T>
auto SharedShallowCointainer<T>::cend()const
{
	return data.cend();
}

template<Cloneable T>
size_t SharedShallowCointainer<T>::size()const
{
	return data.size();
}

template<Cloneable T>
const T& SharedShallowCointainer<T>::operator[](size_t index)const
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}

template<Cloneable T>
T& SharedShallowCointainer<T>::operator[](size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}
