#include <iostream>

//class Fraction
//{
//private:
//	int num;
//	int denom;
//
//public:
//	Fraction(int num = 0, int denom = 1):
//		num{num},
//		denom{denom}
//	{}
//
//	/*Fraction(const Fraction& f)
//	{
//
//	}*/
//
//	int getNum()
//	{
//		return this->num;
//	}
//	void setNum(int val)
//	{
//		this->num = val;
//	}
//	void render()
//	{
//		std::cout << this->num << '/' << this->denom << '\n';
//	}
//};
//
//Fraction doNegative(Fraction f)			// ~~~ Fraction f{ 5 }
//{
//	f.setNum(-f.getNum());
//
//	return f;
//}
//
//int main()
//{
//	/*int a{ 4 };
//	double b{ (double)a };*/
//
//	Fraction x{ 5, 3 };			// Вызов конструктора Fraction(int num = 0, int denom = 1)
//
//	Fraction y{ x };			// Вызов неявного конструктора Fraction(const Fraction& f) с побитовым копированием
//
//	Fraction k{ 5 };			// конструктор Fraction(int num = 0, int denom = 1) используется, как преобразователь типов
//
//	Fraction a{ doNegative(5) };
//	a.render();
//}





class MyString
{
private:
	std::string str;
public:
	MyString(bool flag) = delete;		// Запретить использование такого конструктора
	MyString(char ch) = delete;			// Запретить использование такого конструктора

	explicit MyString(int size)
	{
		std::cout << "explicit MyString(int size)\n";
		str.resize(size);
	}
	explicit MyString(const char* str)
	{
		std::cout << "explicit MyString(const char* str)";
		this->str = str;
	}
	void render()
	{
		std::cout << this->str << '\n';
	}
};

int main()
{
	MyString str = 'a';			// ERROR
	str.render();
}






