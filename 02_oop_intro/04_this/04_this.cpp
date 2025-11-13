#include <iostream>

// #define INTRO
// #define CHAINING
#define PRACTICE_1

#ifdef INTRO

class Container
{
private:
    int val;
public:
    Container(int val)
    {
        this->val = val;
    }
    int getVal()
    {
        return this->val;
    }
    void setVal(int val)        // ~~~ void setVal(Container* const this, int val)
    {
        // this = new Container{ 3 };      // ERROR

        this->val = val;
    }
    void exp()
    {
        std::cout << this << '\n';
    }
};

int main()
{
    //Container a{ 10 };
    //Container b{ 20 };

    ////std::cout << a.getVal() << '\n';
    ////std::cout << b.getVal() << '\n';

    //std::cout << &a << '\n';
    //std::cout << &b << '\n';

    //a.exp();        // ~~~ exp(&a);
    //b.exp();


    //Container* c = new Container{ 30 };
    //std::cout << c << '\n';
    //c->exp();               // (*c).exp()
}

#endif // INTRO

#ifdef CHAINING

//class Calc
//{
//private:
//    int val;
//public:
//    Calc() :
//        val{}
//    {}
//    int getVal()
//    {
//        return this->val;
//    }
//    int add(int v)
//    {
//        return this->val += v;      // return this->val = this->val + v;
//    }
//    int sub(int v)
//    {
//        return this->val -= v;
//    }
//    int mult(int v)
//    {
//        return this->val *= v;
//    }
//    void render()
//    {
//        std::cout << "val = " << this->val << '\n';
//    }
//};

class Calc
{
private:
    int val;
public:
    Calc() :
        val{}
    {
    }
    int getVal()
    {
        return this->val;
    }
    Calc* add(int v)
    {
        this->val += v;

        return this;
    }
    Calc* sub(int v)
    {
        this->val -= v;

        return this;
    }
    Calc* mult(int v)
    {
        this->val *= v;

        return this;
    }
    void render()
    {
        std::cout << "val = " << this->val << '\n';
    }
};

int main()
{
    // Calc calc{};

    //std::cout << calc.add(5) << '\n';
    //std::cout << calc.mult(4) << '\n';
    //std::cout << calc.sub(17) << '\n';

    //calc.render();

    Calc* calc = new Calc{};

    // chaining (chain)
    calc
        ->add(5)
        ->mult(4)
        ->sub(17)
        ->render();
}

#endif // CHAINING

#ifdef PRACTICE_1
// TASK
// class Student
// fields: id, name, age, gender, group, grades(dynamic array)
// ctor --> init all fields
// methods: getName, setName, getAge, setAge, render, addGrade
// test: array, render for all students

int currentId{ 100 };

enum Gender
{
    MALE,
    FEMALE
};

class Student
{
private:
    int id;
    std::string name;
    short age;
    Gender gender;
    std::string group{""};

    int gCount{};
    int* grades{nullptr};

public:
    Student(std::string name, short age, Gender gender):
        id{ ++currentId },
        name{ name },
        age{ age },
        gender{ gender }
    {}
    void setGroup(std::string group)
    {
        this->group = group;
    }
    void render()
    {
        std::cout << "id: " << this->id << " name: " << this->name
            << " age: " << this->age;

        std::cout << " gender: " << (this->gender == Gender::MALE ? "male" : "female");

        std::cout << " group: " << (this->group == "" ? "no group" : this->group);

        std::cout << "\nGRADES:\n";
        if (this->grades == nullptr)
            std::cout << "no grades";
        else
            for (int i{}; i < this->gCount; ++i)
                std::cout << grades[i] << ' ';
    }
    void addGrade(int grade)
    {
        if (this->grades == nullptr)
        {
            grades = new int[++this->gCount] {grade};

            return;
        }

        int* temp = new int[++this->gCount];
        for (int i{}; i < this->gCount - 1; ++i)
            temp[i] = this->grades[i];
        temp[this->gCount - 1] = grade;
        
        delete[] this->grades;

        this->grades = temp;
    }
};

int main()
{
    Student s{"Vasia", 23, Gender::MALE};
    s.setGroup("P42");
    s.render();

    s.addGrade(10);
    s.addGrade(11);
    s.addGrade(10);

    s.render();
}

#endif // PRACTICE_1






