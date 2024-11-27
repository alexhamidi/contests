#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
    string line; 
    int numExcluded =0; 
    int n;
    cin >> n; 

    vector<int> colors(n+1);
    vector<vector<bool>> edges (n+1, vector<bool>(n+1));
    
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color; 
        colors[i] = color; 
    }

    unordered_map<int, int> colorEdges; 


    for (int i = 0; i < n; i++) {
        int u, v; 

        cin >> u >> v;

        if (colors[u] == colors[v]) {
            colors[colors[u]]++;
        }
        
    }
    
    for (auto it = colorEdges.begin(); it != colorEdges.end(); it++) {
        cout << it->second << "\n"; 
    }
    
    return 0;
}



/*
what is the output? 





n nodes, n-1 edges

colors of the node

use a map

nnumbers of pairs of vertices wwith the same color that have an edge, for each folor

*/









// int main() {
//     string line; 
//     int numExcluded =0; 
//     int n;
//     cin >> n; 
    
//     for (int i = 0; i < n; i++) {
//         int diff;
//         cin >> diff; 
//         if (diff%2==1) numExcluded++;
//     }
    
//     cout << numExcluded;
    
//     return 0;
// }


/*

refuse to ude odd contests


*/

