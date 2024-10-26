#include "node.h"
#include <string>
#include <map>

struct NodeFunctionSet
{
    std::string (*to_string)(Node *);
};

struct NodeFunctionSet NodeFunctionSet(std::string(to_string)(Node *))
{
    struct NodeFunctionSet ret;
    ret.to_string = to_string;
    return ret;
}

std::map<std::string, struct NodeFunctionSet> node_function_sets_register;

std::string Node::to_string(Node *n)
{
    if (node_function_sets_register.find(n->type) != node_function_sets_register.end())
    {
        if (node_function_sets_register[n->type].to_string != NULL)
        {
            return node_function_sets_register[n->type].to_string(n);
        }
    }
    return "";
}

class Register
{
public:
    Register(std::string name, struct NodeFunctionSet function_set)
    {
        node_function_sets_register.insert(std::pair<std::string, struct NodeFunctionSet>(name, function_set));
    }
};