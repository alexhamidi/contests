#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> A(m);
    vector<pair<int, int>> ans;

    for (auto& a : A) cin >> a;

    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (A[i-1][j-1] == 'O' && A[i-1][j] == 'O' && A[i-1][j+1] == 'O' && A[i][j+1] == 'O' && A[i+1][j+1] == 'O' && A[i+1][j] == 'O' && A[i+1][j-1] == 'O' && A[i][j-1] == 'O') {
                ans.push_back({i+1, j+1});
            }
        }
    }
    if (ans.size() == 0) {
        cout << "Oh no!";
    } else if (ans.size() == 1) {
        cout << ans[0].first << " " << ans[0].second;
    } else {
        cout << "Oh no! " << ans.size() << " locations";
    }
}
