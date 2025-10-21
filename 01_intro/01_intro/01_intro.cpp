#include <iostream>

//int add(int a, int b)
//{
//    return a + b;
//}
//
//int main()
//{
//    int c = add(4, 5);
//    int d = add(7, 8);
//    
//    return 0;
//}



//int* add(int* a, int* b)
//{
//	int* res = new int{ *a + *b };
//
//	return res;
//}
//
//int main()
//{
//	int* a = new int{ 4 };
//	int* b = new int{ 5 };
//
//	std::cout << *(add(a, b));
//
//	return 0;
//}



//int main()
//{
//	int a = 5;
//	int* ptr = &a;
//	std::cout << ptr << '\n';
//	std::cout << &ptr << '\n';
//
//	std::cout << *ptr << '\n';
//
//
//	return 0;
//}




//int main()
//{
//	int a = 5;
//	int* ptr = &a;
//	int** p = &ptr;
//	int*** q = &p;
//}



//int main()
//{
//	int a = 5;
//	int* b = new int{ 6 };
//
//	return 0;
//}



//int main()
//{
//	// int* ptr = new int[3];
//
//	int** ptr = new int* [3];
//
//	*ptr = new int{ 1018 };
//
//	int* val = *ptr;
//
//	*(ptr + 1) = new int{ 202 };
//	*(ptr + 2) = new int{ 303 };
//
//
//}



int main()
{
	int rows = 2;
	int cols = 3;

	int** arr = new int* [rows];
	for (int i{ 0 }; i < rows; ++i)
	{
		*(arr + i) = new int[cols];
		// >>> EQUALS <<<
		// arr[i] = new int[cols];
	}

	for (int i{ 0 }; i < rows; ++i)
	{
		int* rowsAddr = *(arr + i);
		for (int j{ 0 }; j < cols; ++j)
		{
			*(rowsAddr + j) = 8;
		}
	}

	for (int i{ 0 }; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
		{
			// std::cout << *(*(arr + i) + j) << ' ';
			// >>> EQUALS <<<
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
}



