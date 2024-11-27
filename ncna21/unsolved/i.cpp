#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

bool canTravel (pair<int, int> orig, pair<int, int> dest, vector<vector<char>>& A) { // doesnt work for (4, 0), (5, 5)
    int m = A.size();
    int n = A[0].size();

    auto [i, j] = orig;
    auto [ni, nj] = dest;
    if (i == ni || j == nj) {
        return true;
    } else if (ni-i < nj-j) {
        double xinc = double(ni-i)/double(nj-j);
        for (int cj = j; cj < nj; cj++) {
            int ci = i + int((cj-j) * xinc);
            if (ci < m && cj < n && A[ci][cj] == '#') {
                return false;
            }
        }
    } else { //dealing with this one
        double yinc = double(nj-j)/double(ni-i);
        for (int ci = i; ci < ni; ci++) {
            int cj = j + int((ci-i) * yinc);
            if (ci < m && cj < n && A[ci][cj] == '#') {
                return false;
            }
        }
    }
    return true;
}

double getDistance (pair<int, int> orig, pair<int, int> dest) {
    auto [i, j] = orig;
    auto [ni, nj] = dest;
    return sqrt(pow((double(ni-i)), 2) + pow(double(nj-j), 2));
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>>A(m, vector<char>(n));
    for (auto& v : A) for (auto& a : v) cin >> a;

    cout << canTravel({0, 0}, {2, 3}, A);


    double best = numeric_limits<double>::max();
    queue<tuple<int, int, double>> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        auto [i, j, t] = q.front();
        q.pop();

        if (i == m && j == n) {
            if (t < best) {
                cout << "best of " << t << "\n";
                best = t;
                best = min(best, t);
            }

            continue;
        }

        for (int ni = i; ni <= m; ni++) {
            for (int nj = j; nj <= n; nj++) {
                if (ni == i && nj == j) continue;
                if (canTravel({i, j}, {ni, nj}, A)) {
                    q.push({ni, nj, t + getDistance({i, j}, {ni, nj})});
                }
            }
        }
    }
    cout << best;
    return 0;
}

//access in order of time or currdistance, once we find our best we shouldnt keep going



/*

    diags of empty, lines of parked

    low constraints, just

    can do weird diagonals


    go to every place possible that is closer to start?

    too many.

*/
