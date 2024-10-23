#include <iostream>
#include "object.h"

class Person : public Object{
public:
    std::string name;
    int age;

    std::any identfy(std::vector<std::any> args){
        std::cout << name << " " << age << std::endl;
        return NULL;
    }

    Person(std::string name , int age){
        this->name = name;
        this->age = age;

        register_variable("name",&this->name);
        register_variable("age",&this->age);

        
        register_function("identfy",std::bind(&Person::identfy,this,std::placeholders::_1));

        
        //std::bind(&Person::identfy,this)();
    }
};

int main() {

    Object *obj = new Person("alan",29);
    obj->call("identfy",{});
    obj->set<std::string>("name","adam");
    obj->set<int>("age",23);
    std::cout << obj->get<std::string>("name") << " " << obj->get<int>("age") << std::endl;
    delete obj;
    
    return 0;
}
