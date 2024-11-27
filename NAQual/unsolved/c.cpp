#include <iostream>
#include <vector>
#include<climits>
#include <set>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n;

    vector<set<char>> A(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set<char> curr;
        for (char ch : s) {
            curr.insert(ch);
        }

        A[i] = curr;

    }

    cin >> s;

    int ans = INT_MAX;

    for (set<char> cset : A) {
        int fi = INT_MAX;
        int li = INT_MIN;
        set<char> sset;
        for (int i = 0; i < s.size(); i++) {
            if (cset.count(s[i])) {
                sset.insert(s[i]);
                fi = min(i, fi);
                li = max(i, li);
            }
        }

        if (cset == sset) {
            ans = min(ans, li-fi+1);
        }

    }
    cout << ans;
    return 0;
}



/*
ignore clubs with people not on i
length of the lowest possible valid interval

*/
