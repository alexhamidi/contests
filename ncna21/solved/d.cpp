#include <iostream>
#include <vector>

using namespace std;

int main() {


    string t;
    cin >> t;

    vector<vector<char>> ans(4, vector<char>(5, ' '));


    for (int i = 0; i < 4; i++) {
        int col = i + (i >= 2);
        int curr = t[i]-'0';
        for (int j = 3; j >= 0; j--) {
            if ((curr & 1) == 1) {
                ans[j][col] = '*';
            } else {
                ans[j][col] = '.';
            }
            curr >>= 1;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << ans[i][j];
            if (j < 4) cout << " ";
        }
        cout << "\n";
    }


    return 0;
}
