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
	void Resizeable();
	void ReallocMem();
	void AllocMem(size_t srcSize);
public:
	Vector();
	Vector(const Vector<_T> &vect);
	Vector(size_t count, const_pointer arr);
	void push_back(const_reference value);
	~Vector();
};

template<class _T>
inline void Vector<_T>::Resizeable()
{
	while (size+1 > Capacity)
		Capacity += 10;
}

template<class _T>
inline void Vector<_T>::ReallocMem()
{
	Vector buff(*this);
	delete[]Target;
	Target = new _T[Capacity];
	
}

template<class _T>
inline void Vector<_T>::AllocMem(size_t srcSize)
{

	Resizeable();
	Target = new _T[Capacity];
}

template<class _T>
inline Vector<_T>::Vector()
{
	AllocMem(0);
}

template<class _T>
inline Vector<_T>::Vector(const Vector &vect)
{
	size = vect.size;
	AllocMem(size);
	std::copy_n(vect.Target, vect.size, Target);

}

template<class _T>
inline Vector<_T>::Vector(size_t count, const_pointer arr)
{
	if (arr != nullptr)
	{
		size = count;
		AllocMem(count);
		std::copy_n(arr, count, Target);
	}
}

template<class _T>
inline void Vector<_T>::push_back(const_reference value)
{
	if (size+1 < Capacity)
	{
		 new((void*)(Target + size))_T(value);
		size++;
	}
	else
	{
		Vector buff(*this);
		delete[]Target;
		AllocMem(size);
		std::copy_n(buff.Target, size++, this->Target);
	}
}

template<class _T>
inline Vector<_T>::~Vector()
{
	delete[]Target;
	Target = nullptr;
	Capacity = NULL;
	size = NULL;

}
