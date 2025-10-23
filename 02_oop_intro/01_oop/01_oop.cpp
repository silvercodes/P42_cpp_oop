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



#pragma endregion






