#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main() {
    string unreduced, p;
    cin >> unreduced >> p;

    string s;

    set<char> pset(p.begin(), p.end());

    for (char c : unreduced) {
        if (pset.count(c)) s.push_back(c);
    }

    int m = s.size();
    int n = p.size();
    int ans = 0;
    set<string> seen;
    for (int _ = 0; _ < n; _++) { //check unique
        if (!seen.count(p)) {
            seen.insert(p);
            vector<vector<long long>>dp(m+1, vector<long long>(n+1, 0));

            for (int i = 0; i <= m; i++) {
                dp[i][0] = 1;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (s[i] == p[j]) {
                        dp[i+1][j+1] = (dp[i][j] + dp[i][j+1]) % mod;
                    } else {
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                }
            }
            ans = (ans + dp[m][n]) % mod;
        }
        string res = p.back() + p;
        res.pop_back();
        p = res;
    }
    cout << ans;
    return 0;
}

/*

probably dp

the number of ways to genearte that sequence before returning the starting position

maybe do it based on prefixes of the numbers
    - would not be able to be done quickly because they all depend

    the number of ways you can permute p onto s, given all p.length cycles of p

*/
