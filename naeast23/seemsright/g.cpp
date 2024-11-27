#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int main() {
    int nt, ns, rmax;
    cin >> nt >> ns >> rmax;

    unordered_map<int, unordered_map<int, bool>> grid;
    vector<pair<int, int>> t(nt);

    for (int i = 0; i < nt; i++) {
        int x, y;
        cin >> x >> y;
        t[i] = {x, y};
        grid[x][y] = true;
    }

    vector<pair<int, int>> s(ns);
    pair<int, int> fp = {-1, -1};
    int minMan = INT_MAX;

    for (int i = 0; i < ns; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = {x, y};
        if (x+y < minMan) {
            minMan = x+y;
            fp = {x, y};
        }
    }

    auto [fx, fy] = fp;


    vector<pair<int, int>> pos;
    for (auto[x, y] : t) {

        //under
        if (!grid[x-fx][y-fy]) {
            int robotX = x-fx;
            int robotY = y-fy;
            bool found = true;
            for (auto [sx, sy] : s) {
                int targetX = robotX + sx;
                int targetY = robotY + sy;
                if (grid[targetX][targetY] == false) {
                    found = false;
                    break;
                }
            }
            if (found) {
                pos.push_back({robotX, robotY});
            }
        }

        //over
        if (!grid[x+fx][y+fy]) {
            int robotX = x+fx;
            int robotY = y+fy;
            bool found = true;
            for (auto [sx, sy] : s) {
                int targetX = robotX - sx;
                int targetY = robotY - sy;
                if (grid[targetX][targetY] == false) {
                    found = false;
                    break;
                }
            }
            if (found) {
                pos.push_back({robotX, robotY});
            }
        }

        //to the left
        if (!grid[x-fy][y+fx]) {
            int robotX = x-fy;
            int robotY = y+fx;
            bool found = true;
            for (auto [sx, sy] : s) {
                int targetX = robotX + sy;
                int targetY = robotY - sx;
                if (grid[targetX][targetY] == false) {
                    found = false;
                    break;
                }
            }
            if (found) {
                pos.push_back({robotX, robotY});
            }
        }

        //to the right
        if (!grid[x+fy][y-fx]) {
            int robotX = x+fy;
            int robotY = y-fx;
            bool found = true;
            for (auto [sx, sy] : s) {
                int targetX = robotX - sy;
                int targetY = robotY + fx;
                if (grid[targetX][targetY] == false) {
                    found = false;
                    break;
                }
            }
            if (found) {
                pos.push_back({robotX, robotY});
            }
        }
    }

    //pos has too many things
    if (pos.empty()) {
        cout << "Impossible";
    } else if (pos.size() > 1) {
        cout << "Ambiguous";
    } else {
        cout << pos[0].first << " " << pos[0].second;
    }

    return 0;
}

/*

will always be aligned with one of the axes


determining if the given sequence occurs anywhere in the forest

for all trees, start at the closest, check all directions, check all ns

*/
