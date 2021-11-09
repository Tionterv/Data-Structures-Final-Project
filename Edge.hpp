#ifndef EDGE_H
#define EDGE_H
#include <string>
const std::string EMPTY_STRING = " ";

class Edge {
public:
    Edge() {
        edgeWeight = 0;
        str1 = EMPTY_STRING;
        str2 = EMPTY_STRING;
    };

    std::string str1;
    std::string str2;
    unsigned long edgeWeight;

    ~Edge();
};

#endif /*EDGE_H*/