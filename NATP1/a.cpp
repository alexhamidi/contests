#include <iostream>
#include <cstring>
using namespace std;

bool adj[26][26];


int main(void) {
    int N;
    cin >> N;
    char buf[4];

    memset(adj, 1, sizeof(adj));

    for (int n = 0; n < N; n++) {
        cin >> buf;

        for (int i = 0; i < 2; i++) {
            for (int j = i+1; j < 3; j++) {
                int pos1 = buf[i] - 'a';
                int pos2 = buf[j] - 'a';
                adj[pos1][pos2] = false;
                adj[pos2][pos1] = false;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << char('a' + i) << ": ";
        for (int j = 0; j < 26; j++) {
            if (adj[i][j]) cout << char('a' + j) << " ";
        }
        cout << "\n";
    }

    return 0;
}



/*



each letter is a node in a graph

graph coloring - each color represents a different one of the dice

dfs and backtracking to find if theres a way to color it that is valid



*/
