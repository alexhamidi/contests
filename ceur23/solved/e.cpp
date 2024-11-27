#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {

    set<string> names;
    vector<map<string, int>> p(2);
    string out = "";

    bool sec = false;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '-') {
            sec=true;
            continue;
        } else if (line[0] == '=') {
            break;
        }
        istringstream ss(line);
        int s, e;
        string name;
        ss >> s >> e >> name;
        names.insert(name);
        p[sec][name] += e-s;
    }

    for (string name : names) {
        int diff = p[1][name] - p[0][name];
        if (diff < 0) {
            out += name + " " + to_string(diff) + "\n";
        } else if (diff > 0) {
            out += name + " +" + to_string(diff) + "\n";
        }
    }
    if (out.empty()) {
        cout << "No differences found.";
    } else {
        cout << out;
    }

    return 0;
}


/*


im a swe, on call for when.

givena schdule,

startm end, name


just print differences, easy

*/
