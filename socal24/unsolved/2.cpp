#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

     int n, m;
     cin >> n >> m;
     vector<int>v(m);
     for (auto& a : v) cin >> a;
     int maxPre = *max_element(v.begin(), v.end());

     int maxIdx = -1;
     int maxVal = -1;

     for (int i =0; i < m; i++) {
         if (v[i] > maxVal) {
               maxIdx = i;
               maxVal = v[i];
           }
    }
    v[maxIdx]--;


    maxIdx = -1;
    maxVal = -1;

    for (int i =0; i < m; i++) {
        if (v[i] > maxVal) {
            maxIdx = i;
            maxVal = v[i];
        }
    }
    v[maxIdx]--;


     int lowestColor = *min_element(v.begin(), v.end());

     int maxOverlap = max(maxPre-n, 0);
     int maxFree = n - maxOverlap;

     int ans = max(0, min(lowestColor, n));

     int final = min(ans, maxFree);

     cout << final << "\n";

     return 0;

}
