#include <iostream>


#pragma region Intro

//class Parent
//{
//protected:
//    int value;
//public:
//    Parent(int value):
//        value{value}
//    { }
//    std::string getName() const
//    {
//        return "Parent";
//    }
//    int getValue() const
//    {
//        return this->value;
//    }
//};
//
//class Child : public Parent
//{
//public:
//    Child(int value):
//        Parent{value}
//    { }
//    std::string getName() const
//    {
//        return "Child";
//    }
//    int getDoubled() const
//    {
//        return 2 * this->value;
//    }
//};
//
//
//int main()
//{
//    //Child c{ 7 };
//    //std::cout << c.getName() << ' ' << c.getValue() << '\n';
//
//    //Child& cref = c;
//    //std::cout << cref.getName() << ' ' << cref.getValue() << '\n';
//
//    //Child* cptr = &c;
//    //std::cout << cptr->getName() << ' ' << cptr->getValue() << '\n';
//
//
//    Child child{ 7 };
//
//    Child* c = &child;
//    Parent* p = &child;
//}




//class A
//{
//public:
//	int a;
//	double b;
//	void f1() {}
//};
//
//class B : public A
//{
//public:
//	int c;
//	void f2() {}
//};
//
//int main()
//{
//	B* ptr = new B{};
//	A* ptr2 = ptr;
//}




//
//class Unit
//{
//private:
//	int hp;
//public:
//	Unit(int hp):
//		hp{hp}
//	{ }
//	void attack() const
//	{
//		std::cout << "Unit::attack()\n";
//	}
//};
//
//class Archer : public Unit
//{
//private:
//	int arrowsCount;
//public:
//	Archer(int hp, int ac):
//		Unit{hp},
//		arrowsCount{ac}
//	{ }
//	void attack() const
//	{
//		std::cout << "Archer::attack()\n";
//	}
//};
//
//class Warrior : public Unit
//{
//private:
//	int power;
//public:
//	Warrior(int hp, int power) :
//		Unit{ hp },
//		power{ power }
//	{}
//	void attack() const
//	{
//		std::cout << "Warrior::attack()\n";
//	}
//};
//
//int main()
//{
//	/*Archer a{ 100, 10 };
//	Warrior b{ 100, 150 };
//
//	a.attack();
//	b.attack();*/
//
//	Unit** army = new Unit*[4]
//	{
//		new Archer{50, 10},
//		new Archer{40, 3},
//		new Warrior{100, 40},
//		new Warrior{100, 80}
//	};
//
//	/*for (int i{}; i < 4; ++i)
//		army[i]->attack();*/
//
//	/*for (int i{}; i < 4; ++i)
//	{
//		Archer* archer = static_cast<Archer*>(army[i]);
//		archer->attack();
//	}*/
//}







//class Unit
//{
//private:
//	int hp;
//public:
//	Unit(int hp) :
//		hp{ hp }
//	{
//	}
//	virtual void attack() const
//	{
//		std::cout << "Unit::attack()\n";
//	}
//};
//
//class Archer : public Unit
//{
//private:
//	int arrowsCount;
//public:
//	Archer(int hp, int ac) :
//		Unit{ hp },
//		arrowsCount{ ac }
//	{
//	}
//	void attack() const override
//	{
//		std::cout << "Archer::attack()\n";
//	}
//};
//
//class SuperArcher : public Archer
//{
//public:
//	SuperArcher(int hp, int ac):
//		Archer{hp, ac}
//	{ }
//	/*void attack() const override
//	{
//		std::cout << "SuperArcher::attack()\n";
//	}*/
//};
//
//class Warrior : public Unit
//{
//private:
//	int power;
//public:
//	Warrior(int hp, int power) :
//		Unit{ hp },
//		power{ power }
//	{
//	}
//	virtual void attack() const override
//	{
//		std::cout << "Warrior::attack()\n";
//	}
//};
//
//int main()
//{
//	Unit** army = new Unit * [6]
//	{
//		new Archer{ 50, 10 },
//		new Archer{ 40, 3 },
//		new Warrior{ 100, 40 },
//		new Warrior{ 100, 80 },
//		new SuperArcher{ 100, 2 },
//		new SuperArcher{ 90, 5 }
//	};
//
//	for (int i{}; i < 6; ++i)
//		army[i]->attack();
//}

#pragma endregion


#pragma region Covariance return

//class Parent
//{
//public:
//	void render()
//	{
//		std::cout << "Parent::render()\n";
//	}
//	virtual Parent* get()
//	{
//		return this;
//	}
//};
//
//class Child : public Parent
//{
//public:
//	void render()
//	{
//		std::cout << "Child::render()\n";
//	}
//
//	virtual Child* get() override			// <--- Covariance return
//	{
//		return this;
//	}
//};
//
//int main()
//{
//	Child* cPtr = new Child{};
//
//	Parent* pPtr = cPtr;
//
//	// Child* -> render()
//	cPtr->get()->render();
//
//	// Parent* -> render()
//	pPtr->get()->render();
//
//
//	return 0;
//}

#pragma endregion


#pragma region Functions pointers

//typedef bool (*validateFn)(int, int);
//// >>> EQUALS <<<
//using validateFn2 = bool(*)(int, int);			// :-)
//
//
//int f1()
//{
//	return 34;
//}
//
//int f2()
//{
//	return 17;
//}
//
//int f3(int a)
//{
//	return 56;
//}
//
//int main()
//{
//	//std::cout << f1 << '\n';
//
//	//int(*fPtr)() = nullptr;
//
//	//fPtr = f1;
//	//fPtr = f2;
//	//// fPtr = f3;		// ERROR
//
//	//std::cout << (*fPtr)() << '\n';
//	//// >>> EQUALS <<<
//	//std::cout << fPtr() << '\n';
//
//
//	//--------------
//
//	validateFn a = nullptr;
//	// >>> EQUALS <<<
//	bool(*b)(int, int) = nullptr;
//}

#pragma endregion


#pragma region Позднее (динимическое) связывание

//using OperationFn = int(*)(int, int);
//
//int sum(int a, int b) { return a + b; }
//int sub(int a, int b) { return a - b; }
//int mul(int a, int b) { return a * b; }
//
//int main()
//{
//	int a;
//	std::cout << "Enter a: ";
//	std::cin >> a;
//
//	int b;
//	std::cout << "Enter b: ";
//	std::cin >> b;
//
//	char op;
//	std::cout << "Enter op: ";
//	std::cin >> op;
//
//	OperationFn opFn = nullptr;
//
//	switch (op)
//	{
//	case '+':
//		opFn = sum;
//		break;
//	case '-':
//		opFn = sub;
//		break;
//	case '*':
//		opFn = mul;
//		break;
//	}
//
//	int result{};
//	if (opFn != nullptr)
//		result = opFn(a, b);			// <--- Позднее связывание
//
//	std::cout << "Result: " << result << '\n';
//}

#pragma endregion


#pragma region Example
// TASK
// Написать ф-цию, которая суммирует чётные элементы массива

//int sum(int* arr, int count)
//{
//	int res{};
//
//	for (int i{}; i < count; ++i)
//	{
//		if (arr[i] % 2 == 0)
//			res += arr[i];
//	}
//
//	return res;
//}
//
//int main()
//{
//	int* arr = new int[6] {5, 6, 7, 8, 9, 2};
//	std::cout << sum(arr, 6) << '\n';
//}



//using Predicate = bool(*)(int);
//
//int sum(int* arr, int count, Predicate predicate)
//{
//	int res{};
//
//	for (int i{}; i < count; ++i)
//	{
//		if (predicate(arr[i]))
//			res += arr[i];
//	}
//
//	return res;
//}
//
//bool isEven(int n) { return n % 2 == 0; }
//bool isDivThree(int n) { return n % 3 == 0; }
//
//int main()
//{
//	int* arr = new int[6] {5, 6, 7, 8, 9, 2};
//
//	std::cout << sum(arr, 6, isEven) << '\n';
//	std::cout << sum(arr, 6, isDivThree);
//}

#pragma endregion


#pragma region Lambda

// []()->type {}


//void(*fptr)() = []()->void {std::cout << "Vasia"; };
//
//void(*fptr2)()
//{
//	[]()
//		{
//			std::cout << "Vasia";
//		}
//};



//using Predicate = bool(*)(int);
//
//int sum(int* arr, int count, Predicate predicate)
//{
//	int res{};
//
//	for (int i{}; i < count; ++i)
//	{
//		if (predicate(arr[i]))
//			res += arr[i];
//	}
//
//	return res;
//}
//
//int main()
//{
//	int* arr = new int[6] {5, 6, 7, 8, 9, 2};
//
//	std::cout << sum(arr, 6, [](int n) {return n % 2 == 0;}) << '\n';
//	std::cout << sum(arr, 6, [](int n) {return n % 3 == 0;}) << '\n';
//}



// TODO: ????
//using Fn = void(*)();
//
//int main()
//{
//	int a{ 4 };
//	int b{ 5 };
//
//	Fn p1 = []() { std::cout << a << '\n'; };
//}


#include <functional>

std::function<void()> ptr = []() {std::cout << 4;};





#pragma endregion

