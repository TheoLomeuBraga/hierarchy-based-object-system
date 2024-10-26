#pragma once
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
};

std::string Person_to_string(Node *n)
{
    Person *p = (Person *)n;
    return std::string("name: ") + p->name + ". age: " + std::to_string(p->age);
}

Register personRegister("Person", {Person_to_string});