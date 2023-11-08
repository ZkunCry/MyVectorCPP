#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
template<class _T>
class Vector
{
	using pointer = _T*;
	using reference = _T&;
	using const_pointer = const _T*;
	using const_reference = const _T&;

private:
	pointer Target;
	size_t Capacity=10;
	size_t size;

public:
	Vector();
	Vector(const Vector<_T> &vect);
	Vector(size_t count, const_pointer arr);
	Vector(const size_t size);
	void push_back(const_reference value);
	void reserve(size_t n);
	void resize(size_t n, const _T& value = _T());
	_T find(const _T& value)const;
	void erase(const _T& position);
	void insert(const _T& value, const size_t pos);
	const size_t Size()const;
	const size_t _Capacity()const;
	_T& operator[](int index)const;
	~Vector()noexcept;
	_T* begin()const;
	_T* end()const;

};

template<class _T>
inline Vector<_T>::Vector()
{
	this->Target = new _T[Capacity];
	size = 0;

}

template<class _T>
inline Vector<_T>::Vector(const Vector &vect)
{
	size = vect.size;
	Capacity = vect.Capacity;
	this->Target = new _T[Capacity];

	std::copy_n(vect.Target, vect.size, Target);

}
template<class _T>
inline Vector<_T>::Vector(size_t count, const_pointer arr)
{
	if (arr != nullptr)
	{
		size = count;
		reserve(count);
		if (Target == nullptr)
			Target = new _T[Capacity];

		std::copy_n(arr, count, Target);
	}
}

template<class _T>
inline Vector<_T>::Vector(const size_t size)
{
	if (size >= Capacity)
		Capacity = size * 2;
	this->Target = new _T[Capacity];
	this->size = size;
}

template<class _T>
inline void Vector<_T>::push_back(const_reference value)
{
	
	if (size == Capacity) reserve(2 * size);
	new(Target + size)_T(value);
	++size;
}

template<class _T>
inline void Vector<_T>::reserve(size_t n)
{
	if (n <= Capacity)return;
	_T* newarr = new _T[n];
	for (size_t i = 0; i < size; ++i)
		new(newarr + i)_T(Target[i]);
	delete[]Target;
	Target = newarr;
	Capacity = n;
}

template<class _T>
inline void Vector<_T>::resize(size_t n, const _T& value)
{
	if (n > Capacity)
		reserve(n);
	for (size_t i  = size; i < n; ++i)
		new(Target + i)_T(value);
	if (n < size)
		size = n;
}

template<class _T>
inline  _T  Vector<_T>::find(const _T& value) const
{
	int first = 0;
	int last = size -1;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (Target[mid] == value)
			return mid;
		else if (Target[mid] < value)
			first = mid + 1;
		else if (Target[mid] > value)
			last = mid - 1;
	}
	return -1;
}

template<class _T>
inline void Vector<_T>::erase(const _T& position)
{	
	if (position > size || position <= 0 || this == nullptr ||size ==0)
		return;
	auto positionSwap = position - 1;
	for (int i = positionSwap; i < size; i++)
		Target[i] = Target[i + 1];
	size--;

}

template<class _T>
inline void Vector<_T>::insert(const _T& value, const size_t pos)
{

	if (pos < 0 || pos > size)
		return;
	if (size != Capacity)
	{
		for (int i = size - 1; i >= pos; --i)
			Target[i + 1] = Target[i];
		Target[pos] = value;
		++size;
	}
	else
	{
		reserve(size * 2);
		insert(value, pos);
	}
	
}

template<class _T>
inline const size_t Vector<_T>::Size() const
{
	return this->size;
}

template<class _T>
inline const size_t Vector<_T>::_Capacity() const
{
	return this->Capacity;
}

template<class _T>
inline _T& Vector<_T>::operator[](int index) const
{
	return *(this->Target + index);
}

template<class _T>
inline Vector<_T>::~Vector()noexcept
{
	delete[]Target;
	Target = nullptr;
	Capacity = NULL;
	size = NULL;
}

template<class _T>
inline _T* Vector<_T>::begin()const
{
	return this->Target;
}

template<class _T>
inline _T* Vector<_T>::end()const
{
	return this->Target+size;
}
