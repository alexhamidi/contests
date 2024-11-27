#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



int main() {

    int n;
    cin >> n;

    vector<vector<char>> grid (n, vector<char>(n+1));
    vector<pair<int, int>> directions = {{1, 0},{-1, 0},{0, 1}, {0,-1}};

    for (int i = 0; i < n; i++) { // build the input
         for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
         }
    }


    for (int i = 0; i < n; i++) { // build the input
         for (int j = 0; j < n; j++) {
             if (grid[i][j] == '?') { //spread in all directions
                cout << "(" << i << "," << j << ")\n";


                for (auto [di, dj] : directions) {

                    if (di != 0) {
                        for (int ni = (i+di); (ni < n && ni >= 0); ni += di) {//3 is skipped altogether
                            if (grid[ni][j] == '?') {
                                cout << "collat"; //error here
                                cout << 0;
                                return 0;
                            } else if (grid[ni][j] == '.' || grid[ni][j] == '+') {
                                grid[ni][j] = '+';
                            } else break;//new direction
                        }
                    } else if (dj != 0) {
                        for (int nj = (j+dj); (nj < n && nj >= 0); nj += dj) {
                            if (grid[i][nj] == '?') {
                                cout << "collat";
                                cout << 0;
                                return 0;
                            } else if (grid[i][nj] == '.' || grid[i][nj] == '+') {
                                grid[i][nj] = '+';
                            } else break;//new direction
                        }

                    }

                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = grid[i][j];
            if (c!='.' && c!='X' && c!='+' && c!='?') {
                int numAllowed = (grid[i][j] - '0');
                int numFound = 0;

                for (auto [di, dj] : directions) {
                    int ni = i+di;
                    int nj = j+dj;
                    if (ni < n && ni >= 0 && nj < n && nj >= 0){
                        if (grid[ni][nj] == '?') {
                            numFound++;
                        }
                    }
                }

                if (numFound != numAllowed) {
                    cout << "too many bulbs";
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << "\n";

    for (int i= 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) { // build the input
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') { //looking for undiscovered
                cout << "(" << i << "," << j << ")";
                cout << "unlit";
                cout << 0;
                return 0;
            }
        }
    }


    cout << 1;
    return 0;
}

//x is a block, ? is a light, and . is open. low inputs


// use + to represent lit cells
/*

place light bulbs in open cells, each bulb can light above, below, left, and right until it reaches the end or a blcoked cell (like a +)

any blocked cell must have that many light bulbs adjacent above, below, left, or right.

no bulbs can shine on each other
square

*/
