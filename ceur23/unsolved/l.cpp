#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int l;
    int p;
};

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    s--;

    string A;
    cin >> A;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, l, p;
        cin >> u >> v >> p >> l;
        u--, v--, p--;
        adj[u].push_back({v, l, p});
    }

    vector<vector<int>> bestPath(n);
    bestPath[s].push_back(s);

    // BFS to calculate best paths
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const auto& edge : adj[curr]) {
            int next = edge.to;
            vector<int> candidatePath = bestPath[curr];
            candidatePath.push_back(next);

            if (bestPath[next].empty() || lexicographical_compare(candidatePath.begin(), candidatePath.end(), bestPath[next].begin(), bestPath[next].end())) {
                bestPath[next] = candidatePath;  // Update with the better path
                q.push(next);
            }
        }
    }

    // Output results
    for (int i = 0; i < n; i++) {
        if (bestPath[i].empty()) {
            cout << "0\n";
        } else {
            cout << bestPath[i].size() << " ";
            for (int node : bestPath[i]) cout << node + 1 << " ";
            cout << "\n";
        }
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
