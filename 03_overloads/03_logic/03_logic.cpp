#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

class Circle
{
private:
    int r;
public:
    Circle(int r = 1) :
        r{ r }
    { }
    double getArea() const
    {
        return M_PI * this->r * this->r;
    }
};

class Rect
{
private:
    int w;
    int h;

    int calcArea() const
    {
        return w * h;
    }
public:
    Rect(int w = 1, int h = 1):
        w{w},
        h{h}
    { }

    bool operator==(const Rect& obj) const
    {
        return this->calcArea() == obj.calcArea();
    }

    bool operator<(const Rect & obj) const
    {
        return this->calcArea() < obj.calcArea();
    }

    bool operator>(const Rect& obj) const
    {
        // return this->calcArea() > obj.calcArea();

        return !(*this < obj);
    }

    bool operator<=(const Rect& obj) const
    {
        // return this->calcArea() <= obj.calcArea();

        return *this < obj || *this == obj;
    }

    bool operator==(const Circle& obj) const
    {
        return this->calcArea() == obj.getArea();
    }

    bool operator==(int area) const
    {
        return this->calcArea() == area;
    }
};


int main()
{
    Rect a{ 3, 4 };
    Rect b{ 2, 6 };
    std::cout << (a == b) << '\n';
    std::cout << (a == 12);

}

