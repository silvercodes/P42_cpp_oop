#include <iostream>

// Композиция (является частью, является владельцем)
// 1. Подчинённый объект является неотъемлемой частью главного объекту (и с точки зрения кода как правило)
// 2. Подчинённый объект в процессе своей жизни может принадлежать только одному главному объекту (и с точки зрения кода)
// 3. Главный объект управляет жизнью починённого объекта
// 4. Подчинённый объект понятия не имеет о существовании главного объекта


//class Point
//{
//private:
//    int x;
//    int y;
//public:
//    Point(int x = 0, int y = 0):
//        x{x},
//        y{y}
//    { }
//    void set(int x = 0, int y = 0)
//    {
//        this->x = x;
//        this->y = y;
//    }
//    friend std::ostream& operator<<(std::ostream& out, const Point& p);
//};
//std::ostream& operator<<(std::ostream& out, const Point& p)
//{
//    out << '(' << p.x << ';' << p.y << ")\n";
//
//    return out;
//}
//
//class Unit
//{
//private:
//    int id;
//    std::string title;
//    Point* position;
//
//public:
//    Unit(int id, const std::string& title, const Point& p):
//        id {id},
//        title {title},
//        position{ new Point{p} }
//    { }
//
//    ~Unit()
//    {
//        if (this->position != nullptr)
//            delete this->position;
//    }
//};
//
//int main()
//{
//    Unit a{ 101, "warrior", {3, 4} };
//}





// Агрегация (имеет)
// 1. Подчинённый объект является неотъемлемой частью главного объекта
// ~ 2. Подчинённый объект в процессе своей жизни может принадлежать нескольким главным объектам
// ~ 3. Главный объект НЕ управляет жизнью починённого объекта
// 4. Подчинённый объект понятия не имеет о существовании главного объекта

//class Engine
//{
//public:
//	int id;
//	int power;
//	Engine(int id, int power):
//		id{id},
//		power{power}
//	{ }
//	void start()
//	{
//		std::cout << this->power << ": " << "brum-brum\n";
//	}
//};
//
//class Car
//{
//public:
//	int id;
//	Engine* engine;
//	Car(int id, Engine* engine):
//		id {id},
//		engine{engine}
//	{ }
//	void setEngine(Engine* engine)
//	{
//		this->engine = engine;
//	}
//	void go()
//	{
//		std::cout << "Car::go()\n";
//		this->engine->start();
//	}
//};
//
//int main()
//{
//	Engine a{ 101, 150 };
//	Engine b{ 102, 180 };
//	Engine c{ 103, 210 };
//
//	Car car{ 201, &a };
//	car.go();
//
//	car.setEngine(&c);
//	car.go();
//}






// Ассоциация (связан с..., ассоциируется с..., использует)
// ~ 1. Первый объект изначально не связан со вторым (так может оставаться и далее)
// ~ 2. Первый объект в один момент времени может быть связан с одним или несколькими объектами второго типа
// ~ 3. Первый объект не управляет жьзнью второго (и наоборот)
// ~ 4. Первый объект может знать о существовании второго (и наоборот)

//#include <vector>
//class Teacher
//{
//public:
//	int id;
//	std::string name;
//};
//
//class Group
//{
//public:
//	int id;
//	std::string title;
//	std::vector<Teacher*> teachers;
//
//	void addTeacher(Teacher* t)
//	{
//		teachers.push_back(t);
//	}
//};



// -- рефлексивная ассоциация
//#include <vector>
//class Category
//{
//public:
//	std::string title;
//	Category* parentCategory = nullptr;
//	// std::vector<Category*> childCategories;
//};


// -- неявная
//class Category
//{
//public:
//	int id;
//	std::string title;
//};
//
//class Product
//{
//public:
//	int id;
//	std::string title;
//	int categoryId;
//};




// Зависимость (использует в качестве типа возврата метода или типа параметра метода)

class Tree;
class NPC;
class Stone;

class MapGenerator
{
public:
	//
	Tree generateTree();
	//
	void setStone(Stone* stone);
	//

};

