#include "Session.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path): g({}), treeType(),agents(){
    std::ifstream i(path);
    json j;
    i >> j;
    g=Graph(j["Graph"]);
    if(j["tree"]=="C"){
        treeType=Cycle;
    }
    else{
        if(j["tree"]=="M"){
            treeType=MaxRank;
        }
        else{
            treeType=Root;
        }
    }
};



TreeType Session::getTreeType() const {
    return treeType;
}


//Session::Session(Graph g, TreeType treeType, std::vector<Agent *> agents):g(g),treeType(treeType),agents(agents) {}

const Graph & Session::getGraph() const {
    return g;
}