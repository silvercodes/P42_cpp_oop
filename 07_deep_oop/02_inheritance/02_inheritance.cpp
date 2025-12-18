#include <iostream>

#pragma region Intro
// composition
//class Human
//{
//public:
//    std::string name;
//    int age;
//    bool isMale;
//
//    const std::string& getName() const
//    {
//        return this->name;
//    }
//};
//
//class User
//{
//public:
//    Human human;
//    std::string email;
//    std::string password;
//};
//
//int main()
//{
//    Human a;
//    a.name;
//    User b;
//    b.human.name;
//}



// inheritance
//class Human
//{
//public:
//    std::string name;
//    int age;
//    bool isMale;
//
//    const std::string& getName() const
//    {
//        return this->name;
//    }
//};
//
//class User: public Human
//{
//public:
//    std::string email;
//    std::string password;
//};
//
//int main()
//{
//    Human a;
//    a.name;
//    User b;
//    b.name;
//}




// Сравнение
//class Human
//{
//public:
//    int age;
//    bool isMale;
//    std::string name;
//    Human(int age = 18, bool isMale = true, const std::string& name = "no_name") :
//        age{age},
//        isMale{isMale},
//        name{name}
//    { }
//
//    const std::string& getName() const
//    {
//        return this->name;
//    }
//};
//
//class User : public Human
//{
//public:
//    std::string email = "no_email";
//    std::string password = "no_password";
//};
//
//class Client
//{
//public:
//    Human human;
//    std::string email = "no_email";
//    std::string password = "no_password";
//};
//
//int main()
//{
//    //Human h{};
//    //std::cout << sizeof(h) << '\n';     // 48b
//    //std::cout << &h << '\n';
//
//    User a{};
//    std::cout << sizeof(a) << '\n';
//
//    Client b{};
//    std::cout << sizeof(b) << '\n';
//
//    std::cout << "test";
//}
#pragma endregion


#pragma region Building

// Наследование

//class Base
//{
//private:
//	int a;
//	int b;
//public:
//	Base(int a, int b):			// 6 (Находим конструктор + инициализация локальных переменных)
//		a{a},					// 7
//		b{b}					// 8
//	{ 
//		std::cout << this << '\n';		// 9
//		std::cout << "Base ctor\n";
//	}
//	int getVal() const
//	{
//		return this->a;
//	}
//	~Base()
//	{
//		std::cout << "Base dtor\n";
//	}
//};
//
//class Child : public Base
//{
//private:
//	double c;
//public:
//	Child(int a, int b, double c) :		// 4 (Находим конструктор + инициализация локальных переменных)
//		Base{ a, b },					// 5
//		c{ c }							// 10
//	{
//		std::cout << this << '\n';		// 11
//		std::cout << "Child ctor\n";
//	}
//	~Child()
//	{
//		std::cout << "Child dtor\n";
//	}
//};
//
//class Item : public Child
//{
//private:
//	char d;
//	bool e;
//public:
//	Item(int a, int b, double c, char d, bool e) :	// 2 (Находим конструктор + инициализация локальных переменных)
//		Child{ a, b, c },							// 3
//		d{ d },										// 12
//		e{ e }										// 13
//	{
//		std::cout << this << '\n';					// 14
//		std::cout << "Item ctor\n";
//	}
//	~Item()
//	{
//		std::cout << "Item dtor\n";
//	}
//};
//
//
//int main()
//{
//	// Base a{ 3, 5 };
//	// Child b{ 2, 3, 3.0 };
//	Item c{ 2, 3, 3.0, '+', true };			// 1
//}




// Композиция

//class Base
//{
//private:
//	int a;
//	int b;
//public:
//	Base(int a, int b) :
//		a{ a },
//		b{ b }
//	{
//		std::cout << this << '\n';
//		std::cout << "Base ctor\n";
//	}
//	int getVal() const
//	{
//		return this->a;
//	}
//	~Base()
//	{
//		std::cout << "Base dtor\n";
//	}
//};
//
//class Child
//{
//private:
//	double c;
//	Base base;
//	
//public:
//	Child(int a, int b, double c) :
//		c{ c },
//		base{ a, b }
//	{
//		std::cout << this << '\n';
//		std::cout << "Child ctor\n";
//	}
//	~Child()
//	{
//		std::cout << "Child dtor\n";
//	}
//};
//
//int main()
//{
//	Child c{ 3, 4, 5.0 };
//}



class Point
{
public:
	int x;
	int y;
	Point(int x, int y) :
		x{ x },
		y{ y }
	{ }
	~Point()
	{
		std::cout << "Point dtor\n";
	}
};

class Unit
{
private:
	int hp;
	Point* position;

public:
	Unit(int hp, const Point& p):
		hp{hp},
		position{ new Point { p } }
	{ }

	~Unit()
	{
		if (this->position != nullptr)
			delete position;
	}
};

int main()
{
	Unit a{ 100, {3, 4} };
}


#pragma endregion





