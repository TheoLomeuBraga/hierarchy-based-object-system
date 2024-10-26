#include <iostream>
#include "person.h"

int main()
{
    Person p("alan", 32);
    std::cout << Node::to_string(&p) << std::endl;

    return 0;
}
