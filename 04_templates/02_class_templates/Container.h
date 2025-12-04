#pragma once
#include <iostream>

template <typename T>
class Container
{
private:
	int size;
	T* arr;

public:
	Container(int size = 10);

	Container(const Container<T>& obj);

	Container<T>& operator=(const Container<T>& obj);

	void erase();

	void render();

	T& operator[](int index);

	int getSize();

	~Container();
};


