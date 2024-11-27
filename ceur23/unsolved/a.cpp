//shouldsolve
#include <iostream>
#include <vector>

using namespace std;


class DJS {
private:
    vector<int> parent;
    vector<pair<int, int>> intervals;
    int numSeen = 0;
public:
    DJS(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find (int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }

    int unite (int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }

    pair<int, int> getRange(int x) {
        pair<int, int> currRange = intervals[x];
        while (x != parent[x]) {
            x = parent[x];
            currRange.first = min(currRange.first, intervals[x].first);
            currRange.second = min(currRange.second, intervals[x].second);
        }
        return currRange;
    }

    bool numIntervals() {
        return ??
    }
};

int main() { ??
    int n;
    cin >> n;
    DJS djs(n);

    djs.add(x, A, B);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) { //removing x
            int x = -a;
            djs.remove(x-1);
        } else { //adding a new interval
            int b;
            cin >> b;
            djs.add(i, a, b);
        }
    }




    return 0;
}

/*
dealing with intervals, number of noncontiguous intervals with the ability to remove or add

seems like segment tree@

*/
