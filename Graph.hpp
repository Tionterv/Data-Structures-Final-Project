#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include "Edge.hpp"
#include <iostream>
#include <string>
#include <map>
#define INFINITE 10000

class Graph : public GraphBase {
public:
    Graph() {};

    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
    void printShortestPath(std::map<std::string, std::string> startLabel, std::string endLabel, std::vector<std::string> &path);

    ~Graph();

private:
    friend class Edge;
    std::vector<Edge*> edgeGraph;
    std::vector<std::string> vecVertex;

};

#endif