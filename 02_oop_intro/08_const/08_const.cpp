#include <iostream>

// #define CONST_OBJECT
// #define CONST_FUNCTIONS_OR_METHODS
#define METHODS_WITH_CONST_THIS

#ifdef CONST_OBJECT

class Point
{
public:
	int x;
	int y;

	Point() :
		x{ },
		y{ }
	{
	}
	Point(int x, int y) :
		x{ x },
		y{ y }
	{}

	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	void setX(int val)
	{
		this->x = val;
	}
};

int main()
{
	const int b = 54;

	const Point a{};
	const Point c{ 3, 4 };

	// c.x = 34;			// ERROR
	// c.setX(34);				// ERROR
}


#endif // CONST_OBJECT

#ifdef CONST_FUNCTIONS_OR_METHODS

class Box
{
private:
	int x;
public:
	Box() : x{}
	{ }
	void setX(const int val)
	{
		this->x = val;
	}
	const int getX()
	{
		return this->x;
	}
};

int main()
{
	Box a{};
	a.setX(12);

	int val{ a.getX() };
}

#endif // CONST_FUNCTIONS_OR_METHODS

#ifdef METHODS_WITH_CONST_THIS


//class Box
//{
//private:
//	int x;
//public:
//	explicit Box() : x{}
//	{ }
//	//Box(int val) const			// ERROR (Запрещены конструкторы с константным this)
//	//{
//	//	this->x = val;
//	//}
//	//static void f() const		// ERROR (в static методах нет this!!!)
//	//{
//
//	//}
//	void setX(int val)			// (Box* const this,.......)
//	{
//		this->x = val;
//	}
//	int getX() const			// (const Box* const this,.......)
//	{
//		// this->x = 12;		// ERROR
//		return this->x;
//	}
//	void show() const
//	{
//		std::cout << this->x;
//	}
//};


class Point
{
private:
	int x;
	int y;
public:
	explicit Point(int x, int y): x{x}, y{y}
	{ }
	int getX() const
	{
		return this->x;
	}
	int getY() const
	{
		return this->y;
	}
	int f()
	{
		return 5;
	}
	int f() const
	{
		return 12;
	}
};

void render(const Point& p)
{
	std::cout << p.getX() << ' ' << p.getY();
}

int main()
{
	Point a{ 3, 4 };

	render(a);
}

#endif // METHODS_WITH_CONST_THIS



