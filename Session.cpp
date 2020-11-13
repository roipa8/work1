#include "Session.h"

Session::Session(const std::string &path): g({}), treeType(),agents(){

};




Session::Session(Graph g, TreeType treeType, std::vector<Agent *> agents):g(g),treeType(treeType),agents(agents) {}

const Graph & Session::getGraph() const {
    return g;
}
