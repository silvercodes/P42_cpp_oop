#include <iostream>

#pragma region []

//class Box
//{
//private:
//	int arr[10];
//public:
//	Box()
//	{
//		for (int i{}; i < 10; ++i)
//			arr[i] = i * i;
//	}
//
//	int getElement(int index)
//	{
//		return arr[index];
//	}
//
//	void render() const
//	{
//		for (int i{}; i < 10; ++i)
//			std::cout << arr[i] << ' ';
//		std::cout << "\n\n";
//	}
//
//	/*int operator[](int index)
//	{
//		return arr[index];
//	}*/
//
//	/*int& operator[](int index)
//	{
//		return arr[index];
//	}*/
//
//	//const int& operator[](const int index) const
//	//{
//	//	// return 12;
//	//	return this->arr[index];
//	//}
//
//	/*const int* operator[](const int index) const
//	{
//		return this->arr + index;
//	}*/
//
//};
//
//int main()
//{
//	/*Box a{};
//	a.render();
//
//	std::cout << a.getElement(5);
//	std::cout << a[5];*/
//
//
//	//Box a{};
//	//int res{ a[5] };
//	//std::cout << a[5] << '\n';
//	//// a[5] = 100;	// ERROR
//
//
//	/*Box a{};
//	int res{ a[5] };
//	std::cout << a[5] << '\n';
//	a[5] = 100;
//	a.render();*/
//
//
//	//Box a{};
//	//int res{ a[5] };
//	//std::cout << a[5] << '\n';
//	//// a[5] = 100;				// ERROR
//	//a.render();
//
//
//	//Box a{};
//	//int res{ *a[5] };
//	//std::cout << *a[5] << '\n';
//	//// *a[5] = 100;			// ERROR
//	//a.render();
//}

#pragma endregion

#pragma region ()

//class Matrix
//{
//private:
//	int arr[5][5]{};
//
//public:
//	void operator()()
//	{
//		for (int i{}; i < 5; ++i)
//			for (int j{}; j < 5; ++j)
//				arr[i][j] = 9;
//	}
//	int& operator()(int r, int c)
//	{
//		return arr[r][c];
//	}
//	const int& operator()(int r, int c) const
//	{
//		return arr[r][c];
//	}
//};
//
//int main()
//{
//	Matrix a{};
//	a();			// <--- ФУНКТОР
//
//	std::cout << a(3, 4) << '\n';
//	a(3, 4) = 100;
//}



//class Box
//{
//private:
//	int val;
//public:
//	Box(int val = 1):
//		val{val}
//	{ }
//
//	int& operator()(int inc)
//	{
//		this->val += inc;
//
//		return this->val;
//	}
//
//	void render()
//	{
//		std::cout << "val = " << this->val << '\n';
//	}
//};
//
//int main()
//{
//	Box a{ 100 };
//	Box b{};
//
//	a(20);
//	b(30);
//
//	a.render();
//	b.render();
//}




//class Counter
//{
//private:
//	int val;
//public:
//	Counter(int init) :
//		val{ init }
//	{
//	}
//	Counter& operator()()
//	{
//		this->val++;
//		return *this;
//	}
//	void render()
//	{
//		std::cout << "counter: " << this->val << '\n';
//	}
//};
//
//int main()
//{
//	Counter a{ 100 };
//	a()()()();
//	a.render();
//}

#pragma endregion

#pragma region type casting operator

//class Pocket
//{
//private:
//	int val;
//public:
//	explicit Pocket(int val):
//		val{val}
//	{ }
//	int getVal() { return this->val; }
//	void setVal(int val) { this->val = val; }
//
//	operator int() const
//	{
//		return this->val;
//	}
//};
//int main()
//{
//	Pocket a{ 100 };
//	a.setVal(500);
//	std::cout << a.getVal() << '\n';
//
//	std::cout << (int)a << '\n';
//}


//class Point
//{
//public:
//	int x;
//	int y;
//	Point(int x, int y):
//		x{x}, y{y}
//	{ }
//};
//
//class Circle
//{
//private:
//	Point center;
//	int r;
//public:
//	Circle(const Point& center, int r):
//		center{center},
//		r{r}
//	{ }
//	void render()
//	{
//		std::cout << "x = " << this->center.x << " y = " << this->center.y << " r = " << this->r << '\n';
//	}
//};
//
//class Square
//{
//private:
//	Point c;
//	int size;
//public:
//	explicit Square(const Point& p, int size):
//		c{p},
//		size{size}
//	{ }
//	void render()
//	{
//		std::cout << "x = " << this->c.x << " y = " << this->c.y << " size = " << this->size << '\n';
//	}
//	operator Circle()
//	{
//		int radius = this->size / 2;
//		
//		return Circle{ c, radius };
//	}
//};
//
//int main()
//{
//	Square a{ Point{10, 10}, 4 };
//	a.render();
//
//	Circle b{ (Circle)a };
//	b.render();
//
//}

#pragma endregion

#pragma region << >>

class Point
{
private:
	int x{};
	int y{};
public:
	Point(int x = 0, int y = 0):
		x{ x }, y{ y }
	{ }

	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, Point&);
};

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << '(' << p.x << ';' << p.y << ")\n";

	return out;
}

std::istream& operator>>(std::istream& in, Point& p)
{
	in >> p.x;
	in >> p.y;

	return in;
}

int main()
{
	/*std::ostream*/
	// cout << 34;

	/*Point a{3, 4};
	std::cout << a << '\n';*/

	Point p;
	std::cin >> p;
	std::cout << p;

	
}






#pragma endregion


