#include <iostream>

// #define STATIC_FIELD
// #define STATIC_METHODS
// #define PRACTICE_1
#define PRACTICE_2

#ifdef STATIC_FIELD

//int count{ 0 };
//
//class Container
//{
//public:
//	int val;
//
//	void render()
//	{
//		std::cout << this->val << ' ' << count << '\n';
//	}
//};




static int a;
static const int b;

class Container
{
public:
	static int count;
	static const int id{ 101 };		// Как исключение для static CONST
	int val;
	void render()
	{
		std::cout << Container::count;
	}
};

// Только за пределами класса
// Не привязано к модификаторам доступа
int Container::count{ 10 };


int main()
{
	Container a;
	Container b;

	a.val = 10;
	b.val = 20;

	a.count = 500;				// :-( Обращение через объект
	Container::count = 700;		// :-) Обращение через имя класса (даже, если не создан ни один объект)

	std::cout << b.val << ' ' << b.count << '\n';
	std::cout << Container::count << '\n';
}

#endif // STATIC_FIELD

#ifdef STATIC_METHODS

class Container
{
private:
	static int count;

public:
	int val;

	static int getCount()
	{
		// нет *this !!!
		// std::cout << this;		// ERROR

		return Container::count;
	}
};
int Container::count{};

int main()
{
	std::cout << Container::getCount();			// OK

	Container a{};
	std::cout << a.getCount();					// не OK

}

#endif // STATIC_METHODS

#ifdef PRACTICE_1
// Написать класс, который самостоятельно определяет уникальный id очередному экземпляру
class Student
{
private:
	static int nextId;

	int id;
	std::string name;
public:
	Student(std::string name):
		id{ Student::nextId++ },
		name{ name }
	{}
	void show()
	{
		std::cout << this->id << ' ' << this->name << '\n';
	}
};
int Student::nextId{101};

int main()
{
	Student a{ "Vasia" };
	Student b{ "Petya" };
	Student c{ "Dima" };

	a.show();
	b.show();
	c.show();
}

#endif // PRACTICE_1

#ifdef PRACTICE_2
// Написать класс Virus, который считает количество созданных копий



#endif // PRACTICE_1



