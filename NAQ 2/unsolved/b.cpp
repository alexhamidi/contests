#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> A;

vector<pair<int, int>> randpoints(mt19937 &rng) {
    vector<pair<int, int>> res;
    sample(A.begin(), A.end(), back_inserter(res), 2, rng);
    return res;
}

bool isCol(pair<int, int> s1, pair<int, int> s2, pair<int, int> p) {
    auto [sx1, sy1] = s1;
    auto [sx2, sy2] = s2;
    auto [x, y] = p;
    return ((sy2 - sy1) * (x - sx1) == (sx2 - sx1) * (y - sy1));
}

int main() {
    const int MAX_OUTER_TESTS = 1000;
    const int MAX_INNER_TESTS = 10;
    int n;
    cin >> n;
    A.resize(n);
    for (auto& [x,y]:A) cin >> x >> y;

    mt19937 rng(random_device{}());

    for (int _1 = 0; _1 < MAX_OUTER_TESTS; _1++) {
        bool used[n];
        memset(used, 0, sizeof(used));
        int usedCt = 0;

        for (int i = 3; i > 0; i--) {
            bool foundLine = false;
            for (int _2 = 0; _2 < MAX_INNER_TESTS && !foundLine; _2++) {
                int target = (n-usedCt)/i;
                vector<pair<int, int>> points = randpoints(rng);
                auto [sx1, sy1] = points[0];
                auto [sx2, sy2] = points[1];

                vector<int> currUsedIndices;
                for (int j = 0; j < n; j++) {
                    if (!used[j] && isCol(points[0], points[1], A[j])) {
                        currUsedIndices.push_back(j);
                    }
                }

                if (currUsedIndices.size() >= target) {
                    for (int idx : currUsedIndices) {
                        used[idx] = true;
                    }
                    usedCt += currUsedIndices.size();
                    foundLine = true;
                }
            }
            if (!foundLine) break;
        }

        if (usedCt == n) {
            cout << "possible";
            return 0;
        }
    }

    cout << "impossible";
    return 0;
}


/*

what would randomizing involve? choose six random points (constant), draw lines between them (constant), and check if all lie on the line (10^4)



bext
take the 4 first points. Draw a line of the first one, and then  do the same thing for
all remaining points (n_0).

Or, do random


*/



/*
    10^4 balloons
*/
