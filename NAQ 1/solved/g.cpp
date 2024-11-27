#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {

    vector<vector<double> > gears(100000);

    int n;

    cin >> n;

    while (n--) {
        int s,c;
        cin >> s >> c;
        s--; //index based on zero, 0 to 100000 arr items and size possibilities
        gears[s].push_back(log(c));
    }

    double angular = 0;

    for (vector<double> gear : gears) if (!gear.empty()) {
        int n = gear.size();
        sort(gear.begin(), gear.end());
        for (int i = 0; i < n/2; i++) {
            angular += (gear[n-i-1] - gear[i]);
        }
    }

    cout << angular;
    return 0;
}



/*Explanation:

assume sizes of the same teeth : A, B, C, D, E, F in sorted order
You want to match the biggest with the smallest, next biggest with next smallest, and so on.

pairs will be:(A, F), (B, E), (C, D)
therefore the best rate will be A/F * B/E * C/D



*/


