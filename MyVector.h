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
	int find(const _T& value)const;
	void erase(const _T& position);
	void insert(const _T& value, const size_t pos);
	const size_t Size()const;
	_T& operator[](int index)const;
	~Vector()noexcept;
	_T* begin();
	_T* end();

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
	std::copy_n(buff.Target, buff.size, Target);
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
inline  int  Vector<_T>::find(const _T& value) const
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
	auto positionSwap = position - 1;
	auto swapElem = Target[position];
	std::copy_n(this->Target, positionSwap-1, this->Target);
	std::copy_n(this->Target + positionSwap +1, positionSwap + 1, this->Target+ positionSwap);
	size--;

}

template<class _T>
inline void Vector<_T>::insert(const _T& value, const size_t pos)
{
	auto positionInsert = pos - 1;
	if (pos > size || pos < 0)
		return;
	if (pos > Capacity ||size > Capacity) {
		Resizeable();
		ReallocMem();	
	}

	size++;
	std::copy_n(this->Target + positionInsert, (size - positionInsert)-1, Target + positionInsert + 1);
	Target[positionInsert] = value;
	
}

template<class _T>
inline const size_t Vector<_T>::Size() const
{
	return this->size;
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
inline _T* Vector<_T>::begin()
{
	return this->Target;
}

template<class _T>
inline _T* Vector<_T>::end()
{
	return this->Target+size;
}
