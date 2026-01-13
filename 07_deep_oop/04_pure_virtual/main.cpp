#include <iostream>

#pragma region Чистые виртуальные ф-ции / абстрактные классы

// АБСТРАКНЫЙ КЛАСС
//class Parent
//{
//public:
//	virtual void f1()
//	{
//		std::cout << "Parent::f1()\n";
//	}
//
//	virtual void f2() = 0;				// Чистая виртуальная ф-ция (абстрактная ф-ция)
//
//	// void f3() = 0;					// ERROR
//
//	virtual void f3() = 0;				// Чистая виртуальная ф-ция (абстрактная ф-ция)
//};
//
//
//class Child : public Parent
//{
//public:
//	virtual void f2() override
//	{
//		std::cout << "Child::f2()\n";
//	}
//	virtual void f3() override
//	{
//		std::cout << "Child::f3()\n";
//	}
//};
//
//
//
//int main()
//{
//	/*Parent* ptr;
//	ptr->f2();*/
//
//	/*Parent* p = new Parent{};			// ERROR
//	p->f2();*/
//
//	//Child* c = new Child{};
//	//c->f1();
//	//c->f2();
//	//c->f3();
//
//	//Parent* p = c;
//	//p->f1();
//	//p->f2();
//	//p->f3();
//
//	Child* c = new Child{};
//
//
//	return 0;
//}



//class A
//{
//public:
//	int id;
//};
//
//class B : public A
//{
//public:
//	virtual void f1() = 0;
//};
//
//class C : public B
//{
//public:
//	virtual void f1() override
//	{
//		std::cout << "OKOOKOKOK";
//	}
//};
//
//int main()
//{
//	//A a{};
//
//	//A* ptr = new C{};
//	//// ptr->f1();				// ERROR
//
//	//B* ptr2 = new C{};
//	//ptr2->f1();
//
//
//	C* c = new C{};
//	A* a = c;
//	std::cout << a->id << '\n';
//
//}




#include <vector>

//class Mesh
//{
//public:
//	//
//	//
//	//
//	virtual void render() = 0;
//};
//
//class Tree : public Mesh
//{
//public:
//	virtual void render() override
//	{
//		std::cout << "tree\n";
//	}
//};
//
//class Stone : public Mesh
//{
//public:
//	virtual void render() override
//	{
//		std::cout << "stone\n";
//	}
//};
//
//class Unit : public Mesh
//{
//public:
//	virtual void render() override
//	{
//		std::cout << "unit\n";
//	}
//};
//
//class Archer : public Unit
//{
//
//};
//
//
//int main()
//{
//	std::vector<Mesh*> arr;
//	arr.push_back(new Tree{});
//	arr.push_back(new Stone{});
//	arr.push_back(new Archer{});
//	arr.push_back(new Archer{});
//
//	for (int i{}; i < arr.size(); ++i)
//		arr[i]->render();
//}

#pragma endregion


#pragma region Interfaces (контрактами)

//class ILogger
//{
//public:
//	virtual void save() = 0;
//	virtual int getState() = 0;
//	virtual void setSource(const std::string& src) = 0;
//
//	virtual ~ILogger() {}
//};
//
//class FileLogger : public ILogger  // реализация интерфейса (контракта, абстракции)
//{
//public:
//	virtual void save() override
//	{
//		std::cout << "FileLogger::save\n";
//	}
//	virtual int getState() override
//	{
//		std::cout << "FileLOgger::getState\n";
//		return 3;
//	}
//	virtual void setSource(const std::string& src) override
//	{
//		std::cout << "FileLogger::setSource\n";
//	}
//};
//
//class TelegramLogger : public ILogger
//{
//public:
//	virtual void save() override
//	{
//		std::cout << "TelegramLogger::save\n";
//	}
//	virtual int getState() override
//	{
//		std::cout << "TelegramLogger::getState\n";
//		return 3;
//	}
//	virtual void setSource(const std::string& src) override
//	{
//		std::cout << "TelegramLogger::setSource\n";
//	}
//};
//
//
//class Application
//{
//private:
//	ILogger* logger{ nullptr };
//public:
//	void setLogger(ILogger* logger)
//	{
//		this->logger = logger;
//	}
//	//
//	//
//	void run()
//	{
//		//
//		//
//		this->logger->save();
//	}
//};
//
//int main()
//{
//	Application app{};
//	app.setLogger(new TelegramLogger{});
//	//
//	//
//	app.run();
//
//	app.setLogger(new FileLogger{});
//	app.run();
//
//	return 0;
//}

#pragma endregion


// Класс <-- Абстрактный класс <-- Интерфейсный класс (Интерфейс)
// Ф-ция <-- Виртуальная ф-ция <-- Чистая виртуальная ф-ция (абстрактная)
