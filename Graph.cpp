/*
Dijkstra's Algorithm
Final Project COP 4530 

Names:  Jorge A. Gil
        Kevin Zhang Wang
        Mina Can 

For Programming Project 5, we implemented an undirected weighted Graph ADT and performed Dijkstra's Algorithm 
to find the shortest path between two vertices. Our graph implements methods that add and remove vertices, 
add and remove edges, and calculate the shortest path. Each vertex in our graph has a string label that helps 
to identify that vertex.
*/

#include "Graph.hpp"
#include <map>
#include <queue>
#include <string>
#include <vector>

//Destuctor
Graph::~Graph(){
   edgeGraph.erase(edgeGraph.begin(), edgeGraph.end());
};

//addVertex
//Creates and adds a vertex to the graph with label. 
//Two vertices can't have the same label.
void Graph::addVertex(std::string label) {
    for (unsigned int i = 0; i < vecVertex.size(); i++) {
        //don't add to the vertice vector if the label already exists.
        if (vecVertex.at(i) == label) 
        { 
            return; 
        }
    }
    vecVertex.push_back(label); //otherwise push back
};

//removeVertex
//Removes the vertex with label from the graph. 
//Also removes the edges between that vertex and the other vertices of the graph.
void Graph::removeVertex(std::string label) {
    for(unsigned int i = 0; i <  vecVertex.size(); i++) {
        if(vecVertex.at(i) == label) 
        {
            //remove the label from the vector if it exists
             vecVertex.erase(vecVertex.begin() + i);
        
            for(unsigned int j = 0; j < edgeGraph.size(); j++) 
            {
                Edge *edgeTemp = new Edge();
                edgeTemp = edgeGraph.at(j);               
                if(edgeTemp->str1 == label || edgeTemp->str2 == label)
                {
                    edgeGraph.erase(edgeGraph.begin() + j);
                }
            }
        }
    }
};

//addEdge
//Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2. 
//A vertex with label1 and a vertex with label2 must both exist, there must not already be
//an edge between those vertices, and a vertex cannot have an edge to itself.
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    bool str1Flag = false;
    bool str2Flag = false;

    for(unsigned int i = 0; i < vecVertex.size(); i++) {
        //if label1 and label2 exist in the vertice vector create the edge object. Otherwise, do nothing
        if(vecVertex.at(i) == label1) 
        { 
            str1Flag = true; 
        }
        if(vecVertex.at(i) == label2) 
        { 
            str2Flag = true; 
        }
    }
    
    if(str1Flag == true && str2Flag == true) {
        Edge *newEdge = new Edge();
        newEdge->str1 = label1;
        newEdge->str2 = label2;
        newEdge->edgeWeight = weight;
        edgeGraph.push_back(newEdge);
    }
};

//removeEdge
//Removes the edge from the graph between the vertex with label1 and the vertex with label2. A
//vertex with label1 and a vertex with label2 must both exist and there must be an edge between
//those vertices
void Graph::removeEdge(std::string label1, std::string label2) {
    Edge *edgeTemp = new Edge();

    // iterates through all the edges that exist and remove edge if it exists
    for(unsigned int i = 0; i < edgeGraph.size(); i++) 
    {
        edgeTemp = edgeGraph.at(i); 

        if(edgeTemp->str1 == label1 && edgeTemp->str2 == label2)
        {
            edgeGraph.erase(edgeGraph.begin() + i);
        }
    }
};

//shortestPath
//Calculates the shortest path between the vertex with startLabel and the vertex with endLabel
//using Dijkstra's Algorithm. A vector is passed into the method that stores the shortest path
//between the vertices. The return value is the sum of the edges between the start and end
//vertices on the shortest path.
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    std::priority_queue< std::pair<int, std::string>, std::vector <std::pair<int, std::string> >,
    std::greater<std::pair<int, std::string> > > priorityQueue;
    
    std::map<std::string,std::string> vertexLabel;
    std::map<std::string,int> mapWeight;
    
    //initalizes the dijkstra's table to empty strings, and infinity for the weights
    for (auto label : vecVertex) 
    {
        mapWeight[label] = INFINITE;
        vertexLabel[label] = EMPTY_STRING;
    }
    // first add the starting point to the priority queue
    priorityQueue.push(make_pair(0, startLabel));
    mapWeight[startLabel] = 0;
    
    //dijkstra's algorithm
    while (!priorityQueue.empty()) {
        std::string topLabel = priorityQueue.top().second;
        priorityQueue.pop();    
        std::string currentVer;

        //checking with all it's adjacent neighbors and their weights
        for (auto adjacentN : edgeGraph) {
            if(adjacentN->str1 == topLabel) 
            { 
                currentVer = adjacentN->str2; //current vertex = adjacent neighbor -> string2
            }
            else if(adjacentN->str2 == topLabel) 
            { 
                currentVer = adjacentN->str1; 
            }
            else {
                continue; 
            }

            int weight = adjacentN->edgeWeight;  //holds the temporary weight of current vertex

            //calculations
            if (mapWeight[topLabel] + weight < mapWeight[currentVer]) {
                vertexLabel[currentVer] = topLabel;
                mapWeight[currentVer] = mapWeight[topLabel] + weight;
                priorityQueue.push(make_pair(mapWeight[currentVer], currentVer));
            }
        }
    }
    path.push_back(startLabel);
    printShortestPath(vertexLabel, endLabel, path);   //print the shortest path
    return mapWeight[endLabel];
};

void Graph::printShortestPath(std::map<std::string,std::string> vertexLabel, std::string endLabel , std::vector<std::string> &path) {
    if (vertexLabel[endLabel] == EMPTY_STRING) 
    { 
        return; 
    }
    printShortestPath(vertexLabel, vertexLabel[endLabel], path);
    path.push_back(endLabel);
};

