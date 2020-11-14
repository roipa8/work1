#include <iostream>
#include "Graph.h"
using namespace std;
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix){}
Graph::Graph(const Graph &other) {};

void Graph::infectNode(int nodeInd) {
    statusList[nodeInd]=Infected;

}
bool Graph::isInfected(int nodeInd) {
    return (statusList[nodeInd]==Infected);
}

void Graph::setHealthy(){
    for(int i = 0; i<this->edges.size(); i++){
        statusList.push_back(Healthy);
    }
}

Tree * Graph::BFS(const Session &session, int nodeInd) {
    Tree* root=Tree::createTree(session,nodeInd);
//    Graph g1=session.getGraph();
    std::vector<bool> isVisited;
    for(int i=0; i<edges.size(); i++){
        isVisited.push_back(false);
    }
    queue<int> q;
    q.push(nodeInd);
    while (!q.empty()){
        int currIndex=q.front();
        q.pop();
        Tree* currTree=Tree::createTree(session,currIndex);
        for(int i=0;i<edges.size(); i++){
            if(!isVisited[i]&&edges[i][currIndex]==1){
                q.push(i);
                isVisited[i]=true;
                Tree* nextTree=Tree::createTree(session,i);
                currTree->addChild(nextTree);
            }
        }
    }
    return root;
}




bool Graph::isFinish() {
    std::vector<bool> isVisited;
    for(int i=0; i<edges.size(); i++){
        isVisited.push_back(false);
    }
    for (int i=0; i<this->edges.size(); i++){
        if(!isVisited[i]){
            isVisited[i]=true;
            if(!isFinishAux(isVisited, i, statusList[i]))
                return false;
        }
    }
    return true;
}

bool Graph::isFinishAux(std::vector<bool> &isVisited, int row, Status status) {
    for(int i=0; i<edges.size(); i++){
        if(edges[row][i]==1){
            if(!isVisited[i]){
                isVisited[i]=true;
                if(statusList[i]!=status){
                    return false;
                }
                else{
                    return isFinishAux(isVisited,i,statusList[i]);
                }
            }
        }
    }

}
void Graph::removeEdges(const Session &session, int nI) {
    Graph g1 = session.getGraph();
    for(int i = 0; i<g1.edges.size();i++){
        if(edges[nI][i]==1){
            edges[nI][i]=0;
            edges[i][nI]=0;
        }
    }
}
//Graph::Graph(std::vector<std::vector<int>> matrix) {
//    edges = matrix;
//}
//Graph::~Graph() {}
