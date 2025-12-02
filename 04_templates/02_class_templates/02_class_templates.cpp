#include <iostream>
#include "Container.h"


template<typename T, typename K>
int func()
{

}


int main()
{
    Container<int> a{};
    Container<std::string> b{};

    func<Container<int>, Container<std::string>>();
}

