#pragma once
#include <string>

class Node {
public:
    std::string type;
    Node(std::string type){
        this->type = type;
    };
    static std::string to_string(Node *n);
};
