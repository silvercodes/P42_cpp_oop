#include <iostream>

#pragma region Intro
//struct Rect
//{
//	int x;
//	int y;
//	int w;
//	int h;
//};
//int test(int value)
//{
//	return value * 2;
//}
//
//int area1(Rect r)
//{
//	return r.w * r.h;
//}
//
//int area2(const Rect* r)
//{
//	// r->h = 100;			// ERROR
//
//	// return (*r).h * (*r).w;
//	return r->h * r->w;
//}
//
//int main()
//{
//	/*int val{ 101 };
//	std::cout << test(val);
//	std::cout << test(12);*/
//	 
//	Rect a{ 0, 0, 5, 2 };
//	//std::cout << area1(a);
//	//std::cout << area1({1, 2, 10, 5});
//
//	std::cout << area2(&a);
//	std::cout << area2(new Rect{ 3, 4, 5, 6 });
//}





//struct Rect
//{
//	int x;
//	int y;
//	int w;
//	int h;
//};
//
//int area(const Rect* r)
//{
//	return r->h * r->w;
//}
//int perimeter(const Rect* r)
//{
//	return 2 * (r->w + r->h);
//}
//void move(Rect* r, int x, int y)
//{
//	r->x = x;
//	r->y = y;
//}
//void render(const Rect* r)
//{
//	std::cout << '(' << r->x << ';' << r->y << ')' << " size: " << r->w << '*' << r->h << '\n';
//}
//
//int main()
//{
//	Rect a{ 0, 0, 5, 2 };
//
//	std::cout << area(&a) << '\n';
//	std::cout << perimeter(&a) << '\n';
//	move(&a, 10, 10);
//	render(&a);
//}




//class Rect
//{
//public:
//	int x;
//	int y;
//	int w;
//	int h;
//
//	int area()
//	{
//		return w * h;
//	}
//	int perimeter()
//	{
//		return 2 * (w + h);
//	}
//	void move(int newX, int newY)
//	{
//		x = newX;
//		y = newY;
//	}
//	void render()
//	{
//		std::cout << '(' << x << ';' << y << ')' << " size: " << w << '*' << h << '\n';
//	}
//};
//
//
//int main()
//{
//	//Rect a{0, 0, 5, 2};
//	//std::cout << a.area() << '\n';
//	//std::cout << a.perimeter() << '\n';
//	//a.move(10, 10);
//	//a.render();
//
//	Rect* rect = new Rect{ 0, 0, 5, 2 };
//
//	std::cout << rect->w << '\n';
//
//	std::cout << rect->perimeter();
//
//	return 0;
//}
#pragma endregion

#pragma region OOP intro

// ИНКАПСУЛЯЦИЯ		НАСЛЕДОВАНИЕ		ПОЛИМОРФИЗМ		АБСТРАКЦИЯ

// ====== Член класса, модификаторы доступа (private, public, protected)

//class Point
//{
//public:
//	int x;		// переменная-член класса (поле)
//	int y;		// переменная-член класса (поле)
//
//private:
//	int z;		// переменная-член класса (поле)
//
//public:
//	void print()	// функция-член класса (метод)
//	{
//		std::cout << '(' << x << ';' << y << ';' << z << ')' << '\n';
//	}
//};
//
//int main()
//{
//	//Point a;
//	//a.print();
//	//a.x = 12;
//	//std::cout << a.y;
//	//// std::cout << a.z;		// ERROR
//
//	Point* a = new Point{};
//	a->print();
//
//	return 0;
//}



// TASK
// Создать класс описывающий 3-мерную точку.
// Предусмотреть методы распечатывания и перемещения точки в пространстве

//class Point3D
//{
//public:
//	int x;
//	int y;
//	int z;
//
//	void print()
//	{
//		std::cout << '(' << x << ';' << y << ';' << z << ')' << '\n';
//	}
//
//	void move(int a, int b, int c)
//	{
//		x = a;
//		y = b;
//		z = c;
//	}
//};
//
//int main()
//{
//	int v{ 4 };
//	
//	Point3D a{};
//	a.print();
//	a.move(3, 4, 7);
//	a.print();
//}


// ====== геттер (аксессор) / сеттер (мутатор) / инспектор

//class Point3D
//{
//private:
//	int x;
//	int y;
//	int z;
//
//public:
//	// сеттер (мутатор)
//	void set(int a, int b, int c)
//	{
//		setX(a);
//		setY(b);
//		setZ(c);
//	}
//	// сеттер
//	void setX(int a)
//	{
//		x = a < 0 ? 0 : a;
//	}
//	// сеттер
//	void setY(int b)
//	{
//		y = b < 0 ? 0 : b;
//	}
//	// сеттер
//	void setZ(int c)
//	{
//		z = c < 0 ? 0 : c;
//	}
//	// геттер
//	int getX()
//	{
//		//
//		//
//		return x;
//	}
//	// инспектор
//	bool isOut()
//	{
//		return x > 100 || y > 100 || z > 100;
//	}
//
//	void print()
//	{
//		std::cout << '(' << x << ';' << y << ';' << z << ')' << '\n';
//	}
//};
//
//int main()
//{
//	Point3D a{};
//	a.set(2, 3, -5);
//	a.print();
//	a.setZ(12);
//	a.print();
//
//	std::cout << a.getX();
//	std::cout << a.isOut();
//}


// TASK
// Напишите класс SmartArray, который реализует функционал умного массива. Класс должен иметь:
// 1. Приватный целочисленный статический (динамический) массив определённой длины
// 2. Приватное целочисленное значение для отслеживания количества элементов
// 3. Публичный метод reset() для очистки массива
// 4. Публичный push() типа bool, который добавляет элемент в конец массива (возвращает true в случае успеха)
// 5. Публичный pop() для извлечения элемента из конца массива
// 6. Публичный print()

int main()
{



}





#pragma endregion




