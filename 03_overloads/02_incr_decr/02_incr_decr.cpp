#include <iostream>

class Box
{
private:
    int num;
public:
    explicit Box(int val) : num{val}
    { }

    void render()
    {
        std::cout << "num = " << this->num << '\n';
    }

    // prefix increment
    Box& operator++()
    {
        if (this->num == 10)
            this->num = 0;
        else
            ++this->num;

        return *this;
    }

    // prefix decrement
    Box& operator--()
    {
        if (this->num == 0)
            this->num = 10;
        else
            --this->num;

        return *this;
    }

    // postfix increment
    Box operator++(int)     // <--- this is kostil :-)
    {
        Box temp = *this;

        if (this->num == 10)
            this->num = 0;
        else
            ++this->num;

        return temp;
    }

    // postfix decrement
    Box operator--(int)     // <--- this is kostil :-)
    {
        Box temp = *this;

        if (this->num == 0)
            this->num = 10;
        else
            --this->num;

        return temp;
    }
};



int main()
{
    /*Box b{ 5 };
    Box c{ ++b };
    b.render();
    c.render();*/

    //Box a{ 8 };
    //++a;
    //++a;
    //++a;
    //++a;
    //a.render();

    //Box a{ 5 };
    //Box b{ a++ };
    //a.render();
    //b.render();

    // :-)))
    Box a{ 7 };

    Box b{ ++a++ };
    a.render();
    b.render();
}
