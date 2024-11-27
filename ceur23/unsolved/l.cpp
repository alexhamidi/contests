//shouldsolve
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    string A;  //all edge labels are substrings of A
    cin >> A;

    vector<pair<string, int>> adj[n+1]; //target, substring
    for (int i = 0; i < m; i++) {
        int u, v, p, l;
        cin >> u >> v >> p >> l;
        adj[u].push_back({A.substr(p-1, l), v});
    }

    for (int i = 1; i <= n; i++) {
        vector<pair<string, vector<int>>> wrk;
        vector<pair<string, vector<int>>> cmp;

        wrk.push_back({"",{s}});

        while (!wrk.empty()) {
            vector<pair<string, vector<int>>> cwrk;
            for (auto [s, vec] : wrk) {
                int ln = vec.back();
                if (ln == i) {
                    cmp.push_back({s, vec});
                } else for (auto [newS, v] : adj[ln]) {
                    vector<int> tmp = vec;
                    tmp.push_back(v);
                    cwrk.push_back({s+newS, tmp});
                }
            }
            wrk = cwrk;
        }
        if (cmp.empty()) {
            cout << 0;
        } else {
            auto [_, bestPath] = *min_element(cmp.begin(), cmp.end());
            cout << bestPath.size() << " ";
            for (auto node : bestPath) cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}


/*
strings are correct, why is there a 2 randomly


first, try brute force, maybe dag makes it not too bad


given a dag, each edge has a label

label of a path is the concatenation of labels in the path

smallest path is the one earliest in lexicographic oorder.

give the smallest path for all vertices



always just do greedy should be easy, choose th

only problem - empty string -
*/


/*

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    string A;  // All edge labels are substrings of A
    cin >> A;

    vector<vector<pair<string, int>>> adj(n + 1); // {substring, target node}
    for (int i = 0; i < m; i++) {
        int u, v, p, l;
        cin >> u >> v >> p >> l;
        adj[u].push_back({A.substr(p - 1, l), v});
    }

    for (int target = 1; target <= n; target++) {
        vector<string> dp(n + 1, string(d + 1, 'z')); // DP table for shortest string
        dp[s] = ""; // Start at source with empty string

        priority_queue<tuple<string, int>, vector<tuple<string, int>>, greater<>> pq;
        pq.push({"", s});

        while (!pq.empty()) {
            auto [curStr, u] = pq.top();
            pq.pop();

            if (dp[u] < curStr) continue; // Skip if not optimal

            for (auto [edgeStr, v] : adj[u]) {
                string newStr = curStr + edgeStr;

                if (newStr < dp[v] && newStr.size() <= d) {
                    dp[v] = newStr;
                    pq.push({newStr, v});
                }
            }
        }

        if (dp[target] == string(d + 1, 'z')) {
            cout << 0 << "\n";
        } else {
            cout << dp[target].size() + 1 << " " << s << " " << target << "\n";
        }
    }

    return 0;
}
*/
