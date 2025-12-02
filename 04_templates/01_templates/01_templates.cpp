#include <iostream>

//int sum(int a, int b)
//{
//    return a + b;
//}
//
//double sum(double a, double b)
//{
//    return a + b;
//}
//
//std::string sum(const std::string& a, const std::string& b)
//{
//    return a + b;
//}

//template<typename T>
//T sum(const T& a, const T& b)
//{
//    return a + b;
//}
//
//
//int main()
//{
//    std::cout << sum(4.0, 5.3);
//    std::cout << sum(4.1, 5.6);
//
//    std::cout << sum(3, 4);
//}




//class Box
//{
//private:
//	int val;
//public:
//	Box(int val):
//		val{val}
//	{ }
//
//	friend Box operator+(const Box&, const Box&);
//	friend std::ostream& operator<<(std::ostream&, const Box&);
//};
//
//Box operator+(const Box& a, const Box& b)
//{
//	return Box{ a.val + b.val };
//}
//std::ostream& operator<<(std::ostream& out, const Box& b)
//{
//	out << "val = " << b.val << '\n';
//
//	return out;
//}
//
//template<typename T>
//T sum(const T& a, const T& b)
//{
//    return a + b;
//}
//
//int main()
//{
//	Box a{ 3 };
//	Box b{ 4 };
//
//	std::cout << sum(a, b) << '\n';
//
//	return 0;
//}




// TASK
// Создать шаблон функции для нахождения среднего арифметического элементов массива
// Обеспечить работу ф-ции с массивом объектов Box

class Box
{
private:
	int val;
public:
	Box():
		val{}
	{ }
	Box(int val):
		val{val}
	{ }
	Box& operator+=(const Box& b)
	{
		this->val += b.val;

		return *this;
	}

	Box operator/(int denom)
	{
		return Box{ this->val / denom };
	}

	friend std::ostream& operator<<(std::ostream&, const Box&);
};

std::ostream& operator<<(std::ostream& out, const Box& b)
{
	out << "val = " << b.val << '\n';

	return out;
}


template<typename T, typename K = T>
K average(T* arr, int count)
{
	T sum{};

	for (int i{}; i < count; ++i)
		sum += arr[i];

	return (K)sum / count;
}

int main()
{
	int* arr0 = new int[5] {1, 3, 5, 6, 1};
	std::cout << average<int, double>(arr0, 5) << '\n';

	double* arr1 = new double[5] {1.4, 3.6, 5.7, 6.1, 1.0};
	std::cout << average<double>(arr1, 5) << '\n';

	Box* arr2 = new Box[5]{ Box{3}, Box{5}, Box{7}, Box{9}, Box{1} };
	std::cout << average<Box>(arr2, 5);
}


