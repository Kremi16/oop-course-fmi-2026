#pragma once
#include"Utils.h"
#include<stdexcept>

template<Cloneable T>
class SharedContainer
{
private:
	vector<shared_ptr<T>> data;

	void copyFrom(const SharedContainer<T>& other);

public:
	SharedContainer() = default;
	SharedContainer(const SharedContainer<T>& other);
	SharedContainer<T>& operator=(const SharedContainer<T>& other);

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
void SharedContainer<T>::copyFrom(const SharedContainer<T>& other)
{
	for (const auto& object : other.data)
	{
		data.push_back(shared_ptr<T>(object.clone().release()));
	}
}

template<Cloneable T>
SharedContainer<T>::SharedContainer(const SharedContainer<T>& other)
{
	copyFrom(other);
}

template<Cloneable T>
SharedContainer<T>& SharedContainer<T>::operator=(const SharedContainer<T>& other)
{
	if (other != this)
	{
		data.clear();
		copyFrom(other);
	}
	return *this;
}

template<Cloneable T>
void SharedContainer<T>::add(const T& object)
{
	data.push_back(shared_ptr<T>(object.clone().release()));
}

template<Cloneable T>
void SharedContainer<T>::remove(size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	data.erase(data.begin() + index);
}

template<Cloneable T>
auto SharedContainer<T>::begin()
{
	return data.begin();
}

template<Cloneable T>
auto SharedContainer<T>::end()
{
	return data.end();
}

template<Cloneable T>
auto SharedContainer<T>::cbegin()const
{
	return data.cbegin();
}

template<Cloneable T>
auto SharedContainer<T>::cend()const
{
	return data.cend();
}

template<Cloneable T>
size_t SharedContainer<T>::size()const
{
	return data.size();
}

template<Cloneable T>
const T& SharedContainer<T>::operator[](size_t index)const
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}

template<Cloneable T>
T& SharedContainer<T>::operator[](size_t index)
{
	if (index >= data.size())
	{
		throw out_of_range("Index is out of range.");
	}
	return *data[index];
}