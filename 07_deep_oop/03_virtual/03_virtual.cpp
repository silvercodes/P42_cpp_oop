#include <iostream>

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







class Unit
{
private:
	int hp;
public:
	Unit(int hp) :
		hp{ hp }
	{
	}
	virtual void attack() const
	{
		std::cout << "Unit::attack()\n";
	}
};

class Archer : public Unit
{
private:
	int arrowsCount;
public:
	Archer(int hp, int ac) :
		Unit{ hp },
		arrowsCount{ ac }
	{
	}
	void attack() const override
	{
		std::cout << "Archer::attack()\n";
	}
};

class SuperArcher : public Archer
{
public:
	SuperArcher(int hp, int ac):
		Archer{hp, ac}
	{ }
	/*void attack() const override
	{
		std::cout << "SuperArcher::attack()\n";
	}*/
};

class Warrior : public Unit
{
private:
	int power;
public:
	Warrior(int hp, int power) :
		Unit{ hp },
		power{ power }
	{
	}
	virtual void attack() const override
	{
		std::cout << "Warrior::attack()\n";
	}
};

int main()
{
	Unit** army = new Unit * [6]
	{
		new Archer{ 50, 10 },
		new Archer{ 40, 3 },
		new Warrior{ 100, 40 },
		new Warrior{ 100, 80 },
		new SuperArcher{ 100, 2 },
		new SuperArcher{ 90, 5 }
	};

	for (int i{}; i < 6; ++i)
		army[i]->attack();
}

