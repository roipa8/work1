#include <iostream>
#include "Session.h"
#include "Graph.h"
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
    return 0;
}