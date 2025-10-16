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



int* add(int* a, int* b)
{
	int* res = new int{ *a + *b };

	return res;
}

int main()
{
	int* a = new int{ 4 };
	int* b = new int{ 5 };

	std::cout << *(add(a, b));

	return 0;
}
