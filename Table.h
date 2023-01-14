//
// Created by Mehr-systeM on 1/14/2023.
//

#ifndef UNTITLED_TABLE_H
#define UNTITLED_TABLE_H

#include "Node.h"
#include <vector>
#include <string>

class Table {
private:
    std::vector<Node> *nodes;
    int length;

    std::string showUpperNode(std::vector<Node> node);

public:
    Table(int length);

    void setNode(Type type, Size size, int x, int y);

    void print();

};


#endif //UNTITLED_TABLE_H
