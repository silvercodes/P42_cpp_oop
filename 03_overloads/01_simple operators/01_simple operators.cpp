#include <iostream>

class Point
{
private:
    int x;
    int y;
public:
    Point() : x{}, y{}
    { }
    Point(int x, int y): x{x}, y{y}
    { }
    int getX() const { return this->x; }
    int getY() const { return this->y; }
    void setX(int val) { this->x = val; }
    void setY(int val) { this->y = val; }
    void render() const
    {
        std::cout << '(' << this->x << ';' << this->y << ')' << '\n';
    }

    // binary +
    Point operator+(const Point& p) const
    {
        return Point{ this->getX() + p.getX(), this->getY() + p.getY() };
    }

    // unary -
    Point operator-()
    {
        // Вариант 1
        // this не меняем
        // return Point{ -this->x, -this->y };

        // Вариант 2
        // this изменяется
        this->x = -this->x;
        this->y = -this->y;

        return *this;
    }

    // unary +
    Point operator+()
    {
        int x = this->x < 0 ? 0 : this->x;
        int y = this->y < 0 ? 0 : this->y;

        return Point{ x, y };
    }
};

// binary +
//Point operator+(Point a, Point b)
//{
//    return Point{ a.getX() + b.getX(), a.getY() + b.getY() };
//}

int main()
{
    Point a{ 3, 4 };
    Point b{ 4, 5 };

    Point c{ a + b };           // a + b  --->  a.operator+(b)
    c.render();

    Point d{ -a };
    d.render();
    a.render();

    Point e{ +d };
    d.render();
    e.render();
}
