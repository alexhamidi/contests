#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


long long lcm(int x, int y) {
    return (x*y) / gcd(x, y);
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    string L;
    for (int i = 0; i < n; i++) {
        L.push_back('A' + i);
    }

    vector<pair<int, int>> ops;

    for (int i = n-1; i >= 0; i--) { //once you erase its messed up?
        char target = s[n-i-1];
        auto it = find(L.begin(), L.end(), target);
        int b = it - L.begin();
        L.erase(it);
        ops.push_back({i+1, b});
    }

    //now, have all of the things for CRT
    auto [m, mod] = ops[0];
    for (int i = 0; i < ops.size(); i++) {
        auto [a, b] = ops[i];
        int g = gcd(a, b);
        if ((b - m) % g != 0) {
            cout << "NO";
            return 0;
        }
        mod = lcm(mod, a);
        m = (m + (b - m) * (mod / a)) % mod;
    }
    cout << "YES\n" << m;

    return 0;
}


 /*


collect operations by determininghj
1. the position we had to get at
2. the current n. push {n, res}


m < 10^9


len is short


*/
