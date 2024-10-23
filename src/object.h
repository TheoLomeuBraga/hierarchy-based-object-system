#include <set>
#include <string>
#include <any>
#include <vector>
#include <map>
#include <functional>


#define TYPE_ANY_FUNCTION_PTR std::function<std::any(std::vector<std::any>)>

class Object{

    std::map<std::string,std::any> variables;
    std::map<std::string,TYPE_ANY_FUNCTION_PTR> bindings;

public:

    template<typename X>
    void register_variable(std::string key,X* variable){
        variables.insert(std::pair<std::string,std::any>(key,(std::any)variable));
    }

    
    void register_function(std::string key,TYPE_ANY_FUNCTION_PTR variable){
        bindings.insert(std::pair<std::string,TYPE_ANY_FUNCTION_PTR>(key,variable));
    }



    Object(){}

    template<typename X>
    X get(std::string key){
        return *std::any_cast<X*>(variables[key]);
    }

    template<typename X>
    void set(std::string key,X value){
        *std::any_cast<X*>(variables[key]) = value;
    }

    std::any call(std::string key,std::vector<std::any> args){
        if(bindings.find(key) != bindings.end()){
            return ((TYPE_ANY_FUNCTION_PTR)bindings[key])(args);
        }
        return NULL;
    }

};