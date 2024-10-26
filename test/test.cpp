#include <iostream>
#include "node_register.h"

class Person : public Node
{
public:
    std::string name;
    int age;
    Person(std::string name, int age) : Node("Person")
    {
        this->name = name;
        this->age = age;
    }

    std::string to_string()
    {
        return std::string("name: ") + name + ". age: " + std::to_string(age);
    }
};

std::string Person_to_string(Node *n)
{
    return ((Person*)n)->to_string();
}


Register personRegister("Person",{Person_to_string});

int main()
{
    Person p("alan",32);
    std::cout << Node::to_string(&p) << std::endl;


    return 0;
}
