#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+5);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    queue<int> q;
    vector<int> pa(n+5);
    vector<int> pid(n+5);
    vector<int> dep(n+5);
    vector<int> typ(n+5);
    pair<int, int>




    return 0;
}

/*
n rooms, m doors
doors connect rooms or a room with outdoors and have a unique key

they only use one room - the bedroom.

Alice needs to leave and bob needs to get back in

Alice can drop keys on her way out

cany have duplicates


*/
