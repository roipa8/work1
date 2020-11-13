#include "Session.h"

Session::Session(const std::string &path): g(std::vector<<int>>), treeType(),agents(){
    std::ifstream i(path);
    json j;
    i >> j;
    g=Graph(j["Graph"]);
    treeType=TreeType;
};




Session::Session(Graph g, TreeType treeType, std::vector<Agent *> agents):g(g),treeType(treeType),agents(agents) {}

const Graph & Session::getGraph() const {
    return g;
}
