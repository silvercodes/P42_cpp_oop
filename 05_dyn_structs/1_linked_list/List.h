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
	List<T>(const List<T>& obj):
		head{ nullptr },
		tail{ nullptr },
		count{ 0 }
	{
		if (obj.isEmpty())
			return;

		ListItem<T>* objCurrent{ obj.head };
		ListItem<T>* newItem{ nullptr };
		ListItem<T>* prev{ nullptr };

		for (int i{}; i < obj.count; ++i)
		{
			newItem = new ListItem<T>{ *objCurrent };
			this->tail = newItem;

			if (i == 0)
			{
				this->head = newItem;
			}
			else
			{
				prev->setNext(newItem);
			}

			prev = newItem;
			objCurrent = objCurrent->getNext();
		}

		this->count = obj.getCount();
	}
	// operator= copy
	// getCount()
	int getCount() const
	{
		return this->count;
	}
	// isEmpty()
	bool isEmpty() const
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
	void pushToHead(T val)
	{
		ListItem<T>* newItem = new ListItem<T>{ val };

		if (this->isEmpty())
			this->tail = newItem;
		else
			newItem->setNext(this->head);

		this->head = newItem;

		++this->count;
	}
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

