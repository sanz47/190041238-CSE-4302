#include <iostream>

int add(int x,int y)
{
    return (x+y);
}

namespace my_namespace
{
int add(int x, int y)
{
    return (x-y);
}
}

int main()
{
    std::cout << add(5,4)<< std::endl;
    std::cout << my_namespace::add(5,4) << std::endl;
    return 0;
}
