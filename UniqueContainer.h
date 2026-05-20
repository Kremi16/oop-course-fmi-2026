#pragma once
#include"Utils.h"
#include<stdexcept>

template<Cloneable T>
class UniqueContainer
{
private:
	vector<unique_ptr<T>> data;

	void copyFrom(const UniqueContainer<T>& other);

public:
	UniqueContainer() = default;
	UniqueContainer(const UniqueContainer<T>& other);
	UniqueContainer<T>& operator=(const UniqueContainer<T>& other);

	void add(const T& object);
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
void UniqueContainer<T>::copyFrom(const UniqueContainer<T>& other)
{
	for (const auto& object : other.data)
	{
		data.push_back(object->clone());
	}
}

template<Cloneable T>
UniqueContainer<T>::UniqueContainer(const UniqueContainer<T>& other)
{
	copyFrom(other);
}

template<Cloneable T>
UniqueContainer<T>& UniqueContainer<T>::operator=(const UniqueContainer<T>& other)
{
	if (other != this)
	{
		data.clear();
		copyFrom(other);
	}
	return *this;
}

template<Cloneable T>
void UniqueContainer<T>::add(const T& object)
{
	data.push_back(object.clone());
}

template<Cloneable T>
void UniqueContainer<T>::remove(size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	data.erase(data.begin() + index);
}

template<Cloneable T>
auto UniqueContainer<T>::begin()
{
	return data.begin();
}

template<Cloneable T>
auto UniqueContainer<T>::end()
{
	return data.end();
}

template<Cloneable T>
auto UniqueContainer<T>::cbegin()const
{
	return data.cbegin();
}
template<Cloneable T>
auto UniqueContainer<T>::cend()const
{
	return data.cend();
}

template<Cloneable T>
size_t UniqueContainer<T>::size()const
{
	return data.size();
}

template<Cloneable T>
const T& UniqueContainer<T>::operator[](size_t index)const
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}

template<Cloneable T>
T& UniqueContainer<T>::operator[](size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}


