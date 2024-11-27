#include <iostream>
#include <utility>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>S;
    vector<int>E;

    for (int i = 0;  i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int s, e;
            cin >> s >> e;
            S.push_back(s);
            E.push_back(e);
        }
    }
    sort(S.begin(), S.end());
    sort(E.begin(), E.end());


    int maxRange = 0;
    int maxPix = 0;

    int sSize = S.size();
    int eSize = E.size();

    S.push_back(INT_MAX);
    E.push_back(INT_MAX);

    int e = 0;
    int s = 0;

    int currPix = 0;

    while (s < sSize || e < eSize) {
        if (S[s] <= E[e]) { //choose to do a start
            currPix++;
            int currRange = (E[e] - S[s] + 1);
            if (currPix > maxPix) {
                maxPix = currPix;
                maxRange = currRange;
            } else if (currPix == maxPix) {
                maxRange += currRange;
            }
            s++;
        } else {
            currPix--;
            e++;
        }
    }
    cout << maxPix << "\n" << maxRange;
}
