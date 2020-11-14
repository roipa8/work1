#ifndef GRAPH_H_
#define GRAPH_H_
#include <list>
#include <vector>
#include "Tree.h"
#include "Session.h"
#include "queue"
enum Status{
    Sick,
    Healthy,
    Infected
};
//struct node{
//    int number;
//    Status status;
//};
class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph (const Graph& other);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    Tree* BFS(const Session& session, int nodeInd);
    void setHealthy();
    bool isFinish();
    bool isFinishAux(std::vector<bool> &isVisited, int row, Status status);
    void removeEdges(const Session &session, int);
protected:
    std::vector<Status> statusList;

private:
    std::vector<std::vector<int>> edges;
};

#endif