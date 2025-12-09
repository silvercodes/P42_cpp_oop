#pragma once

// Требования для T
// default ctor --> default initialization
// copy ctor
// operator <<

template <typename T>
class ListItem
{
private:
	T val;
	ListItem<T>* next;

public:
	ListItem():
		val{ },
		next{ nullptr }
	{ }

	ListItem(T val):
		val{ val },
		next{ nullptr }
	{ }

	ListItem(const ListItem<T>& obj) :
		val{ obj.val },
		next{ nullptr }
	{ }

	const T& getVal()
	{
		return this->val;
	}

	ListItem<T>* getNext()
	{
		return this->next;
	}

	void setNext(ListItem<T>* next)
	{
		this->next = next;
	}
};

