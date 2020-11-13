#include "Session.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path): g({}), treeType(),agents(){
    std::ifstream i(path);
    json j;
    i >> j;
    g=Graph(j["Graph"]);
};




Session::Session(Graph g, TreeType treeType, std::vector<Agent *> agents):g(g),treeType(treeType),agents(agents) {}

const Graph & Session::getGraph() const {
    return g;
}
