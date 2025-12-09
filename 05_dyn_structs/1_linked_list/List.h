#pragma once

#include "ListItem.h"

template <typename T>
class List
{
private:
	ListItem<T>* head;
	ListItem<T>* tail;
	int count;

public:
	List<T>():
		head{ nullptr },
		tail{ nullptr },
		count{ 0 }
	{ }

	// copy ctor
	// operator= copy
	// getCount()
	// isEmpty()
	bool isEmpty()
	{
		return count == 0;
	}
	// add Item to tail
	void push(T val)
	{
		ListItem<T>* newItem = new ListItem<T>{ val };

		if (this->isEmpty())
			this->head = newItem;
		else
			this->tail->setNext(newItem);

		this->tail = newItem;
		++this->count;
	}
	// add Item to head
	// operator[]
	// insert(T val, int index)
	// remove
	// render()
	void render()
	{
		std::cout << "count = " << this->count << '\n';
		std::cout << "List";
		if (this->isEmpty())
			std::cout << " is empty\n\n";
		else
			std::cout << ":\n";

		ListItem<T>* temp = this->head;

		while (temp != nullptr)
		{
			std::cout << temp->getVal() << ' ';
			temp = temp->getNext();
		}
		std::cout << "\n\n";
	}
	// dctor
};

