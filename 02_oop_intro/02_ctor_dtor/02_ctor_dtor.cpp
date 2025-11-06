#include <iostream>

//#define PI 3.14
//
//#define FLAG_2

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
// #define PRACTICE_1
// #define INITIALIZATORS
// #define CTOR_DELEGATION
#define DESTRUCTOR

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

#ifdef INITIALIZATORS

//class Calc
//{
//private:
//	const double PI = 3.14;
//	std::string& title;
//public:
//	Calc()
//	{
//		PI = 3.14;		// ERROR
//	}
//};


// -------------------

//class Point
//{
//private:
//	int x;
//	int y;
//	const std::string title;
//	int statArr[3];
//	int dynCount;
//	int* dynArr;
//
//public:
//	// случай без параметров
//	Point() :
//		x{},
//		y{},
//		title {"no_title"},
//		statArr { 4, 5, 6 },
//		dynCount { 3 },
//		dynArr{ new int[3] {1, 2, 3} }
//	{}
//
//	// случай с параметрами
//	Point(int a, int b, std::string t, int dc):
//		x{ a },
//		y{ b },
//		title{ t },
//		statArr{ 4, 5, 6 },
//		dynCount{ dc },
//		dynArr{ new int[dc] {} }
//	{}
//
//	void render()
//	{
//		std::cout << x << '\t' << y << '\t' << title << '\n';
//		std::cout << "statArr\n";
//		for (int i{}; i < 3; ++i)
//			std::cout << statArr[i] << ' ';
//	}
//};
//
//int main()
//{
//	Point p{};
//	p.render();
//
//	Point b{ 3, 4, "B", 10 };
//	b.render();
//}

// ------- 

//class Role
//{
//private:
//	int id;
//	std::string title;
//
//public:
//	Role(int id, std::string title = "no_title") :
//		id{ id }, title{ title }
//	{}
//};
//
//class User
//{
//private:
//	int id;
//	std::string email;
//	Role role;
//
//public:
//	User(int id, std::string email, int roleId, std::string roleTitle):
//		id{ id },
//		email{ email },
//		role{ roleId, roleTitle }
//	{}
//};

// -----------
//class Point
//{
//private:
//	int x{ 1 };	// Значение по-умолчанию (запасной вариант инициализации)
//	int y{ 1 }; // Значение по-умолчанию (запасной вариант инициализации)
//	const int radius;
//public:
//	Point(int a, int b, int r = 1):
//		x{a},
//		y{b},
//		radius{r}
//	{}
//	Point(int r):
//		radius{r}
//	{ }
//	void render()
//	{
//		std::cout << x << ' ' << y << '\n';
//	}
//};
//
//int main()
//{
//	Point a{ 10 };
//	a.render();
//}

#endif // INITIALIZATORS

#ifdef CTOR_DELEGATION

//class User
//{
//private:
//	int id;
//	std::string email;
//
//public:
//	User(int newId, std::string email) :
//		email{ email }
//	{
//		id = newId < 0 ? 0 : newId;
//	}
//
//	User(std::string email):
//		User{ 102, email }
//	{}
//};
//
//int main()
//{
//	User("vasia@mail.com");
//}

#endif // CTOR_DELEGATION

#ifdef DESTRUCTOR

class Student
{
private:
	int id;
	int* grades;
	int gradesCount;

public:
	Student(int id, int gCount):
		id{id},
		gradesCount{gCount},
		grades{ new int[gCount] }
	{}
	/*void clearMemeory()
	{
		if (grades != nullptr)
			delete[] grades;
	}*/
	~Student()
	{
		if (grades != nullptr)
			delete[] grades;
		std::cout << "Student dtor";
	}
};

void func()
{
	Student s{ 101, 1000 };
	//
	//
	// s.clearMemeory();
}

int main()
{
	func();

	return 0;
}

#endif // DESTRUCTOR


