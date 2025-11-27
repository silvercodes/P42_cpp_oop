#include <iostream>

//int main()
//{
//    int a{ 45 };
//
//    int* ptr{ &a };
//
//    int& ref = a;           // int* const ref = &a;
//
//    std::cout << a << '\n';
//    std::cout << *ptr << '\n';
//    std::cout << ref << '\n';
//
//    int x = a;
//    int y = *ptr;
//    int z = ref;
//
//    int*& r = ptr;         // int** const r = &ptr; 
//    std::cout << *ptr << '\n';
//    std::cout << *r << '\n';
//}



//int main()
//{
//	// l-value
//	// --------------------
//	// Модифицируемые (неконствнтные): int a; std::string name = "Vasia"
//	// Немодифицируемые (константные): const int a{ 45 }
//
//	// r-value
//	// --------------------
//	// Литералы, временные значения, анонимные объекты
//	// Существуют в рамках выражения (стейтмента)
//
//	// -----------------------------------
//	// | l-value reference (классические) |
//	// -----------------------------------
//	// 1. Обычные
//	//		Инициализируются только неконстантными l-value
//	// int a{ 43 };		// non const l-value
//	// const int b{ 32 };	// const l-value
//
//	// int& ref0 = a;
//	// // int& ref1 = b;	// ERROR
//	
//	// 2. Ссылка на константное значение (константная ссылка)
//	//		Инициализируется const l-value, l-value, r-value (!!!)
//	// int x{ 45 };
//	// const int p{ 3 };
//
//	// const int& ref0{ p };
//	// const int& ref1{ x };
//	// const int& ref2{ 12 };
//
//	
//
//	// --------------------
//	// | r-value reference |
//	// --------------------
//	//		Инициализируются ТОЛЬКО r-value !!!
//	int x{ 7 };
//	int& ref{ x };
//	int&& rref{ 7 };		// r-value ref
//	rref = 45;
//	std::cout << &rref;
//
//	return 0;
//}



//class Box
//{
//private:
//	int val;
//public:
//	Box(int val = 0):
//		val{val}
//	{ }
//};
//
//void f(const int& lref)
//{
//	std::cout << "l-value ref\n";
//}
//
//void f(int&& rref)
//{
//	std::cout << "r-value ref\n";
//}
//
//int main()
//{
//	//Box a{ 34 };	// ctor
//	//Box b{ a };		// copy ctor
//
//	//Box&& ref{ Box{ 23 } };
//
//	int a{ 7 };
//	f(a);
//	f(7);
//}





class Student
{
private:
	static int currentId;

	int id;
	std::string email;
	int gCount;
	int* grades;

	void clearGradesMemory()
	{
		if (this->grades != nullptr)
			delete[] this->grades;
	}

public:
	// Обычный конструктор
	explicit Student(std::string email = "", int gCount = 1) :
		id{ ++Student::currentId },
		email{ email },
		gCount{ gCount },
		grades{ new int[gCount] {} }
	{
		std::cout << "normal ctor\n";
	}

	// Конструктор копирования (ОБЯЗАТЕЛЬНО)
	Student(const Student& obj) :
		id{ ++Student::currentId },
		email{ obj.email },
		gCount{ obj.gCount }
	{
		this->grades = new int[this->gCount] {};
		for (int i{}; i < this->gCount; ++i)
			this->grades[i] = obj.grades[i];

		std::cout << "copy ctor\n";
	}

	// Конструктор переноса
	Student(Student&& obj) :
		id{ ++Student::currentId },
		email{ obj.email },
		gCount{ obj.gCount }
	{
		this->grades = obj.grades;	// <---- КЛЮЧЕВОЙ МОМЕНТ

		obj.grades = nullptr;

		std::cout << "move ctor\n";
	}

	// Оператор присваивания копированием (ОБЯЗАТЕЛЬНО)
	Student& operator=(const Student& obj)
	{
		if (this == &obj)
			return *this;

		this->email = obj.email;
		this->gCount = obj.gCount;

		clearGradesMemory();

		this->grades = new int[this->gCount] {};
		for (int i{}; i < this->gCount; ++i)
			this->grades[i] = obj.grades[i];

		std::cout << "copy assign\n";

		return *this;
	}

	// Оператор присваивания переносом
	Student& operator=(Student&& obj)
	{
		this->email = obj.email;
		this->gCount = obj.gCount;
		this->grades = obj.grades;
		obj.grades = nullptr;

		std::cout << "move asign\n";

		return *this;
	}

	void render()
	{
		std::cout << "id: " << this->id << "\temail: " << this->email << "\nGRADES:\n";
		for (int i{}; i < this->gCount; ++i)
			std::cout << this->grades[i] << ' ';
		std::cout << "\n\n";
	}

	// Деструктор (ОБЯЗАТЕЛЬНО)
	~Student()
	{
		clearGradesMemory();

		std::cout << "destructor\n";
	}
};

int Student::currentId{ 100 };


Student generate()
{
	std::cout << "generate\n";

	std::string email = "vasia@mail.com";

	Student a{ email, 1000 };
	return a;
}

int main()
{
	/*Student a{ "vasia@mail.com", 15 };
	a.render();

	Student b{ a };
	b.render();

	Student c{ "petya@mail.com", 30};
	c.render();
	c = a;
	c.render();*/


	
	//Student a{ Student{ "dima@mail.com", 5 } };		// эллизия
	//a.render();

	// Student a{ generate() };

	

	/*Student a{};
	a = generate();*/
}