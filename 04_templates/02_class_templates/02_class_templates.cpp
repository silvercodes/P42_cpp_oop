#include <iostream>
#include "Container.h"
#include "Point.h"

int main()
{
	//Container<int> a{};
	//a.render();

	//Container<double> b{};

	//Container<int*> c{};
	//c.render();

	Container<Point> d{};

	Container<Point> e{ d };
	// e.render();
	// e.erase();
	// e.render();

	e[1] = Point{ 3, 4 };
	e.render();


}

