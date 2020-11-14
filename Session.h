#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"
#include "fstream"
#include "json.hpp"

class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    Session(const std::string& path);
//    Session(Graph g, TreeType treeType, std::vector<Agent*> agents);

//    void simulate();
//    void addAgent(const Agent& agent);
//    void setGraph(const Graph& graph);
    const Graph &getGraph() const;

//    void enqueueInfected(int);
//    int dequeueInfected();
    TreeType getTreeType() const;

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif