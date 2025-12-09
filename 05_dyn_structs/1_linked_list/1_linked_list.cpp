#include <iostream>
#include "List.h"

int main()
{
    List<int> a{};

    a.push(12);
    a.push(34);
    a.push(45);
    a.push(21);
    a.push(17);

    a.render();

    List<int> b{ a };
    b.render();
    b.pushToHead(101);
    b.render();
}
