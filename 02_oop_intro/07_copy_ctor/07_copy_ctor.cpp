#include <iostream>
#include <math.h>

//class Point
//{
//private:
//    int x;
//    int y;
//    bool flag;
//public:
//    explicit Point(int x, int y): x{x}, y{y}, flag{false} {}
//
//    // создаётся НЕЯВНО
//    // конструктор копирования
//    // осуществляет побитовое копирование
//    /*Point(const Point& obj)
//    {
//        this->x = obj.x;
//        this->y = obj.y;
//    }*/
//};
//
//int main()
//{
//    Point p{ 3, 4 };
//
//    Point q{ p };
//}





//class Box
//{
//private:
//	int* ptr;
//
//public:
//	Box():
//		ptr{nullptr}
//	{ }
//
//	Box(int val):
//		ptr{ new int{val} }
//	{ }
//
//	// конструктор копирования
//	/*Box(const Box& obj)
//	{
//		this->ptr = new int;
//		*(this->ptr) = *(obj.ptr);
//	}*/
//
//	Box(const Box& obj):
//		ptr{ new int{ *(obj.ptr)}}
//	{ }
//
//
//	int getVal()
//	{
//		return ptr != nullptr ? *ptr : -1;
//	}
//	void setVal(int val)
//	{
//		if (this->ptr == nullptr)
//			ptr = new int;
//
//		*ptr = val;
//	}
//
//	~Box()
//	{
//		if (this->ptr != nullptr)
//			delete ptr;
//	}
//};
//
//int main()
//{
//	Box a{ 10 };
//	Box b{ a };		// call copy ctor !!!
//
//	std::cout << a.getVal() << '\n';
//	std::cout << b.getVal() << '\n';
//
//	a.setVal(500);
//	std::cout << a.getVal() << '\n';
//	std::cout << b.getVal() << '\n';
//}





class Point
{
private:
	int* x;
	int* y;

public:
	Point() :
		x{ new int{} },
		y{ new int{} }
	{ }
	Point(int x, int y):
		x{ new int{x} },
		y{ new int{y} }
	{ }
	Point(const Point& obj):
		x{ new int{ *obj.x } },
		y{ new int{ *obj.y }}
	{ 
		std::cout << "copy ctor\n";
	}
	int getX()
	{
		return *this->x;
	}
	int getY()
	{
		return *this->y;
	}
	~Point()
	{
		if (this->x != nullptr && this->y != nullptr)
		{
			delete this->x;
			delete this->y;
		}
		std::cout << "dtor\n";
	}
};

double getVectorLength(Point p)		// Point p{ a }
{
	return sqrt(pow(p.getX(), 2) + pow(p.getY(), 2));
}

Point getVectorCenter(Point p)
{
	int x = p.getX() / 2;		// TODO: change fields type to double
	int y = p.getY() / 2;

	// Вариант 1
	//Point res{ x, y };
	//return res;

	// Вариант 2
	return Point{ x, y };
}

int main()
{
	// Случаи вызова конструктора копирования

	// 1. Инициализация другим объектом
	/*Point a{ 3, 4 };
	Point b{ a };*/

	// 2. Передача в ф-цию значения объекта (по значению)
	//Point a{ 3, 4 };
	//getVectorLength(a);
	// getVectorLength({5, 6});
	// getVectorLength({ });

	// 3. Возврат из ф-ции
	/*Point p{ 5, 7 };
	Point res{ getVectorCenter(p) };*/


	// Эллизия
	Point p{ Point {3, 4} };

	return 0;
}