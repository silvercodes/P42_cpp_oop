#include <iostream>

#define PI 3.14

#define FLAG_2

//#ifdef FLAG_1
//
//int main()
//{
//	std::cout << "101";
//}
//
//#endif
//
//#ifdef FLAG_2
//
//int main()
//{
//	std::cout << "202";
//}
//
//#endif
//
//#ifndef 1
//
//#endif // !1
//
//#pragma once 


// #define CONSTRUCT
// #define CLASS_IN_CLASS
#define PRACTICE_1

#ifdef CONSTRUCT

class Point
{
private:
	int x;
	int y;
public:
	// Конструктор, создаваемый автоматически в случае отсутствия явного конструктора
	/*Point()
	{ }*/

	// Конструктор по-умолчанию (дефолтный конструктор) без параметров
	// Конструктор, который можно вызвать без параметров
	/*Point()
	{
		x = 10;
		y = 20;
		std::cout << "Point default crot\n";
	}*/
	Point(int a = 10, int b = 10)
	{
		x = a;
		y = b;
		std::cout << "Point ctor\n";
	}
	void render()
	{
		std::cout << '(' << x << ';' << y << ')' << '\n';
	}
};

int main()
{
	//Point a;		// :-|
	//a.render();
	//Point b{};		// :-)
	//b.render();

	/*Point* p = new Point{};
	p->render();*/

	Point a;
	a.render();

	Point b{};
	b.render();

	Point* c = new Point{};
	c->render();

	Point* d = new Point;
	d->render();

	Point* e = new Point();
	e->render();

	Point f{ 1, 2 };
	f.render();

	Point g{ 3 };
	g.render();

	Point* h = new Point{ 5, 6 };
	h->render();

	Point* i = new Point{ 7 };
	i->render();

}


#endif // CONSTRUCT

#ifdef CLASS_IN_CLASS

class Group
{
private:
	std::string title;									// <9>
public:
	Group()												// <8>
	{
		std::cout << "Group ctor\n";					// <10>
	}
};
class Role
{
private:
	std::string title;					// <5>
public:
	Role()								// <4>
	{
		std::cout << "Role ctor\n";				// <6>
	}
};

class User
{
private:
	Role role;							// <3>
	Group group;								// <7>
	int id;												// <11>
public:
	User()								// <2>
	{
		std::cout << "User ctor\n";								// <12>
	}
};

int main()
{
	User u{};							// <1>
}


#endif // CLASS_IN_CLASS

#ifdef PRACTICE_1
// TASK
// Создать класс Circle
// Свойства: 
//			координаты центра (тип Point), 
//			радиус
//			цвет (тип enum Color),
//			динамический массив вложенных окружностей
// Методы:
//			show()
//			move()
//			setColor()
// *** Оптимизировать конструкторы


class Point
{
private:
	int x;
	int y;

public:
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	void setX(int val)
	{
		x = val;
	}
	int getX()
	{
		return x;
	}
	void setY(int val)
	{
		y = val;
	}
	int getY()
	{
		return y;
	}
};

enum Color
{
	Black,
	Red,
	Green
};

class Circle
{
private:
	Point center;
	int radius;
	Color color;
	int count;
	Circle** arr;

public:
	Circle(int x, int y, int r, Color c)
	{
		center.setX(x);
		center.setY(y);
		radius = r;
		color = c;
		count = 0;
		arr = nullptr;
	}

	void show()
	{
		std::cout << "center: " << center.getX() << ';' << center.getY() << ", r = " << radius << '\n';
	}

	void addCircle(Circle* c)
	{

	}
};

int main()
{

}




#endif // PRACTICE_1


