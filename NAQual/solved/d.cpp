#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;


    vector<string> A(n);

    for (auto& a : A) cin >> a;
    string ans;

    for (int i = 0; i < m; i++) {
        map<char, int> freqs;
        for (int j = 0; j < n; j++) {

            freqs[A[j][i]]++;
        }
        int bv = 0;
        char bc;
        for (auto [cc, freq] : freqs) {
            if (freq > bv) {
                bv = freq;
                bc = cc;
            }
        }

        ans.push_back(bc);
    }

    cout << ans;



    return 0;
}
