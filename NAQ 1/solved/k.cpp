#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getPoints(int a, int e) {
    int diff = abs(a-e);
    if (diff > 102) return 0;
    if (diff > 43) return 2;
    if (diff > 23) return 4;
    if (diff > 15) return 6;
    return 7;
}

int main() {
    int m;
    int n;

    cin >> m >> n;

    vector<int> ex(m);
    vector<int> ac(n);

    for (int i = 0; i < m; i++) {
        int e;
        cin >> e;
        ex[i] = e;
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ac[i] = a;
    }


    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[0][i] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int score1 = getPoints(ex[i], ac[j]) + dp[i][j]; //match with current
            int score2 = dp[i+1][j]; // dont match the actual press at all (keep previous)
            int score3 = dp[i][j+1]; // match with an earlier expected
            dp[i+1][j+1] = max({score1, score2, score2});
        }
    }
    cout << dp[m][n];

    return 0;
}
/*2d dp

choose between the next expected or actual

take the max of the three cosest





*/


/*
minimize distances, maximize points


check if the next is better than the last. if yes, adjust, if not, move on






each actual gets no more than one expected,

wording implies that you calculate then readjust but i doubt this is optimal.



need to come up with o(n) solution


players expected to press the butotn at indicated time.

Givem a little bit of time leeway - can do slightly earlier.

we know the amount of points given times - given and constat

differences of 103+ score no point


compute matching to MAXIMIZE POINTS


match each butten press with one expected press. If

if one actual press happens before another, and but are matched with expected presses, them the expected press for the first must come before the press for the second.

*/
