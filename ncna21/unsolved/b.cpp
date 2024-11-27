#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class TreePathQueries {
private:
    vector<vector<int>> adjacencyList;      // instead of adj
    vector<vector<int>> ancestorTable;      // instead of up
    vector<int> nodeDepth;                  // instead of depth
    vector<int> nodeValues;                 // instead of digits
    int maxLogHeight;                       // instead of LOG
    int numNodes, modulus;                  // instead of n, m

    void depthFirstSearch(int currentNode, int parentNode, int currentDepth) {
        nodeDepth[currentNode] = currentDepth;
        ancestorTable[currentNode][0] = parentNode;

        for (int level = 1; level <= maxLogHeight; level++) {
            ancestorTable[currentNode][level] = ancestorTable[ancestorTable[currentNode][level-1]][level-1];
        }

        for (int neighborNode : adjacencyList[currentNode]) {
            if (neighborNode != parentNode) {
                depthFirstSearch(neighborNode, currentNode, currentDepth + 1);
            }
        }
    }

    int findLowestCommonAncestor(int firstNode, int secondNode) {
        if (nodeDepth[firstNode] < nodeDepth[secondNode]) {
            swap(firstNode, secondNode);
        }

        int depthDifference = nodeDepth[firstNode] - nodeDepth[secondNode];
        for (int level = maxLogHeight; level >= 0; level--) {
            if (depthDifference & (1 << level)) {
                firstNode = ancestorTable[firstNode][level];
            }
        }

        if (firstNode == secondNode) return firstNode;

        for (int level = maxLogHeight; level >= 0; level--) {
            if (ancestorTable[firstNode][level] != ancestorTable[secondNode][level]) {
                firstNode = ancestorTable[firstNode][level];
                secondNode = ancestorTable[secondNode][level];
            }
        }

        return ancestorTable[firstNode][0];
    }

    vector<int> getNodePathToRoot(int startNode) {
        vector<int> nodePath;
        while (startNode != 0) {  // 0 is virtual root
            nodePath.push_back(startNode);
            startNode = ancestorTable[startNode][0];
        }
        return nodePath;
    }

public:
    TreePathQueries(int totalNodes, int moduloValue) {
        numNodes = totalNodes;
        modulus = moduloValue;
        maxLogHeight = ceil(log2(numNodes)) + 1;
        adjacencyList.resize(numNodes + 1);
        ancestorTable.assign(numNodes + 1, vector<int>(maxLogHeight + 1));
        nodeDepth.resize(numNodes + 1);
        nodeValues.resize(numNodes + 1);
    }

    void addEdge(int firstNode, int secondNode) {
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    void setNodeValue(int nodeIndex, int value) {
        nodeValues[nodeIndex] = value;
    }

    void preprocess() {
        depthFirstSearch(1, 0, 0);  // Start DFS from node 1 with parent 0
    }

    int calculatePathValue(int startNode, int endNode) {
        int lowestCommonAncestor = findLowestCommonAncestor(startNode, endNode);

        vector<int> startNodePath = getNodePathToRoot(startNode);
        vector<int> endNodePath = getNodePathToRoot(endNode);

        int lcaIndexInStartPath = 0;
        while (lcaIndexInStartPath < startNodePath.size() &&
               startNodePath[lcaIndexInStartPath] != lowestCommonAncestor) {
            lcaIndexInStartPath++;
        }

        vector<int> completePath;
        for (int i = 0; i <= lcaIndexInStartPath; i++) {
            completePath.push_back(startNodePath[i]);
        }

        int lcaIndexInEndPath = 0;
        while (lcaIndexInEndPath < endNodePath.size() &&
               endNodePath[lcaIndexInEndPath] != lowestCommonAncestor) {
            lcaIndexInEndPath++;
        }
        for (int i = lcaIndexInEndPath - 1; i >= 0; i--) {
            completePath.push_back(endNodePath[i]);
        }

        int result = 0;
        long long powerOfTen = 1;
        for (int i = completePath.size() - 1; i >= 0; i--) {
            int currentValue = nodeValues[completePath[i]];
            result = (result + (currentValue % modulus) * (powerOfTen % modulus)) % modulus;
            powerOfTen = (powerOfTen * 10) % modulus;
        }

        return result;
    }
};

int main() {
    int numNodes, modulus, numQueries;
    cin >> numNodes >> modulus >> numQueries;

    TreePathQueries treeQuery(numNodes, modulus);

    for (int i = 0; i < numNodes-1; i++) {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        treeQuery.addEdge(firstNode, secondNode);
    }

    for (int i = 1; i <= numNodes; i++) {
        int nodeValue;
        cin >> nodeValue;
        treeQuery.setNodeValue(i, nodeValue);
    }

    treeQuery.preprocess();

    for (int i = 0; i < numQueries; i++) {
        int startNode, endNode;
        cin >> startNode >> endNode;
        cout << treeQuery.calculatePathValue(startNode, endNode) << "\n";
    }

    return 0;
}

/*
up[i][j] is the 2^jth ancestor above node i

*/


// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main() {
//     int n, m, q;
//     cin >> n >> m >> q;

//     vector<int> digits(n+1);
//     vector<vector<string>> paths(n+1, vector<string>(n+1));
//     vector<vector<int>> con(n+1);

//     for (int i = 0;  i < n-1; i++) {
//         int a, b;
//         cin >> a >> b;

//         for (auto& c : con[a]) {
//             if (paths[c][b].empty()) {
//                 paths[c][b] = paths[c][a] + to_string(b);
//                 paths[b][c] = to_string(a) + paths[a][c];
//                 con[c].push_back(b);
//                 con[b].push_back(c);
//             }
//         }
//         for (auto& c : con[b]) {
//             if (paths[c][a].empty()) {

//                 paths[c][a] = paths[c][b];
//                 paths[c][a] += to_string(a);

//                 paths[a][c] = to_string(b);
//                 paths[a][c] += paths[b][c];

//                 con[c].push_back(a);
//                 con[a].push_back(c);
//             }
//         }

//         paths[a][b] = to_string(b);
//         paths[b][a] = to_string(a);

//         con[b].push_back(a);
//         con[a].push_back(b);
//     }

//     for (int i = 1; i <= n; i++) {
//         paths[i][i] = to_string(i);
//     }

//     for (int i = 1; i <= n; i++) {
//         cin >> digits[i];
//     }

//     for (int i = 0; i < q; i++) {
//         int a, b;
//         cin >> a >> b;
//         string path = paths[a][b];

//         int res = 0;
//         int l = path.size();
//         long long factor = 1;
//         for (int j = l-1; j >= 0; j--) {
//             int curr = digits[path[j]-'0'];
//             res = (res + (curr % m) * (factor % m)) % m;
//             factor = (factor * 10) % m;
//         }
//         cout << res << "\n";
//     }
//     return 0;
// }

/*

simply simulate. problem - how to find the path to a node

need to be able to do it in logn

only one path - how to get that path?

need to have everything in the path  to get the path



problem reduced to finding
*/
