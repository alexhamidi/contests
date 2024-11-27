#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, R;
    cin >> n >> R;
    vector<int>A(n);
    set<int> bombed;
    vector<int> bombs;

    for (auto& a : A) cin >> a;
    sort(A.begin(), A.end());

    while (bombed.size() < n) {

        int maxBombed = 0;
        int bestCenter = 0;

        for (int i = 0; i < n && (!bombed.count(i)); i++) {
            int currCenter = A[i]-R;
            int currBombed = 0;

            for (int j = 0; j < n; j++) {
                if (!bombed.count(j) && abs(A[j] - currCenter) <= R) {
                    currBombed++;
                }
            }
            if (currBombed > maxBombed) {
                maxBombed = currBombed;
                bestCenter = currCenter;
            }
        }
        bombs.push_back(bestCenter);
        for (int i = 0; i < n; i++) {
            if (abs(A[i] - bestCenter) <= R) {
                bombed.insert(i);
            }
        }
    }
    cout << bombs.size() << "\n";
    for (int bomb : bombs) {
        cout << bomb << " ";
    }
    return 0;
}

