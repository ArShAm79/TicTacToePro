//
// Created by Mehr-systeM on 1/14/2023.
//

#include "Table.h"
#include <iostream>

using namespace std;

Table::Table(int length) {
    this->length = length;
    this->nodes = new vector<Node>[length];
}

void Table::setNode(Type type, Size size, int x, int y) {
    Node node = {type, size};
    const int row = 3;
    const int index = (x - 1) * row + y - 1;
    this->nodes[index].push_back(node);
}

void Table::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "| ";
            const int index = i * 3 + j;
            const auto data = nodes[index];
            if (data.empty())
                cout << "   ";
            else
                cout << showUpperNode(nodes[index]) << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

std::string Table::showUpperNode(std::vector<Node> node) {
    if (node.empty()) {
        return " ";
    }
    Node answer = node[0];
    for (auto &n: node)
        if (n.size > answer.size)
            answer = n;

    if (answer.type == Type::Blue)
        return "B" + to_string(answer.size + 1);
    else
        return "R" + to_string(answer.size + 1);


}

std::string Table::checkGameIsEnd() {
    string status = "";
    for (int i = 0; i < this->length; ++i) {
        status += showUpperNode(this->nodes[i]).substr(0, 1);
    }
    string dia1 = status.substr(0, 1) + status[4] + status[8];
    string dia2 = status.substr(2, 1) + status[4] + status[6];

    if (status.substr(0, 3) == "RRR" ||
        status.substr(3, 3) == "RRR" ||
        status.substr(6, 3) == "RRR" ||
        dia1 == "RRR" || dia2 == "RRR")
        return "R";
    else if (status.substr(0, 3) == "BBB" ||
             status.substr(3, 3) == "BBB" ||
             status.substr(6, 3) == "BBB" ||
             dia1 == "BBB" || dia2 == "BBB")
        return "B";

    return status;
}

bool Table::checkNodeIncludes(const std::vector<Node> &vNodes, Node node) {
    bool ans = false;
    for (auto vNode: vNodes) {
        if (vNode.size == node.size && vNode.type == node.type) {
            ans = true;
            break;
        }
    }
    return ans;
}

bool Table::moveNode(Type type, Size size, int pastX, int pastY, int x, int y) {
    auto node = this->nodes[(pastX - 1) * 3 + pastY - 1];

    const auto newNode = Node{type, size};

    const auto isExist = checkNodeIncludes(node, newNode);

    if (!isExist) {
        return false;
    }

    for (int i = 0; i < node.size(); ++i)
        if (node[i].size == size && node[i].type == type) {
            this->nodes[(pastX - 1) * 3 + pastY - 1].
                    erase(nodes[(pastX - 1) * 3 + pastY - 1].cbegin() + i);
            break;
        }

    this->nodes[(x - 1) * 3 + y - 1].push_back(newNode);

    return true;
}





