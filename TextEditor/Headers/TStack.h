#pragma once
#include <iostream>


template <class T>
class TStack
{
protected:
	T* Array;
	size_t Size;
	int16_t LastIndex;
	virtual size_t NextIndex(size_t index) const;
	virtual bool IsFull();
	virtual bool IsEmpty();
public:
	TStack(const size_t size = 10);
	TStack(const T* array);
	~TStack();
	size_t Push(const T& elem);
	virtual T Pop(const T& elem);
	T Top();
};

template<class T>
inline size_t TStack<T>::NextIndex(size_t index) const
{
	return index++;
}

template<class T>
inline bool TStack<T>::IsFull()
{
	return Size == LastIndex-1;
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
	return LastIndex <= -1;
}

template<class T>
inline TStack<T>::TStack(const size_t size)
{
	Array = new T[size];
	Size = size;
	LastIndex = -1;
}

template<class T>
inline TStack<T>::TStack(const T* array)
{
	Size = sizeof(array) / sizeof(T);
	Array = new T[Size];
	initializer_list<T> temp(array);
	copy(temp.begin(), temp.end(), Array);
}

template<class T>
inline TStack<T>::~TStack()
{
	delete[] Array;
}

template<class T>
inline size_t TStack<T>::Push(const T& elem)
{
	if(IsFull()){
		return 1;
	}
	else {
		Array[NextIndex(LastIndex)] = elem;
		LastIndex = NextIndex(LastIndex);
	}
	return 0;
}

template<class T>
inline T TStack<T>::Pop(const T& elem)
{
	if(IsEmpty()){}
	else {
		LastIndex--;
	}
	return Array[LastIndex+1];
}

template<class T>
inline T TStack<T>::Top()
{
	return Array[LastIndex];
}
