#include <iostream>
//#include "Session.h"
//#include "Graph.h"
#include <fstream>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;
using namespace std;

int main(int argc, char **argv) {

    if (argc != 2) {
        cout << "usage cTrace <config_path>" << endl;
//        return 0;
    }
//    Session sess(argv[1]);
//    sess.simulate();
//cout << "HEY" << endl;
    ifstream i("../config1.json");
    json j;
    i >> j;
    cout << j["graph"] << endl;
    vector<int> vect0{0, 1, 0};
//    vector<int>a;
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(10);
//    cout<<a.at(0) << endl;
//    cout<<a.at(1) << endl;
//    cout<<a.at(2) << endl;
//    vector<int> vect1{ 1, 0, 0 };
//    vector<int> vect2{ 0, 0, 0 };
//    vector<vector<int>> matrix{vect0,vect1,vect2};
//    Graph graph(matrix);
//    graph.setHealthy();
//    graph.infectNode(1);
//    graph.infectNode(0);
//    cout<< graph.isFinish();
//    return graph.isInfected();
//    graph.test(2);

    return 0;
}