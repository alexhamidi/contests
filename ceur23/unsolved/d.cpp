#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

struct Sheet {
    int d;       // Width of the sheet
    int tFast;   // Fast drying time
    int tSlow;   // Slow drying time
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Sheet> sheets(n);
    for (auto& a : sheets) {
        cin >> a.d >> a.tFast >> a.tSlow;
    }

    // Sort sheets by slow drying time (descending)
    sort(sheets.begin(), sheets.end(), [](const Sheet& a, const Sheet& b) {
        return a.tSlow > b.tSlow;
    });

    const int maxL = 300000;

    // Precompute prefix sums for total widths
    vector<int> prefixes(n);
    prefixes[0] = sheets[0].d;
    for (int i = 1; i < n; i++) {
        prefixes[i] = prefixes[i - 1] + sheets[i].d;
    }

    // Precompute suffix max for fast drying times
    vector<int> fastMaxSuffix(n + 1);
    fastMaxSuffix[n] = 0; // No sheets means no fast drying time
    for (int i = n - 1; i >= 0; i--) {
        fastMaxSuffix[i] = max(fastMaxSuffix[i + 1], sheets[i].tFast);
    }

    vector<bool> canReach(maxL + 1, false);
    vector<int> ans(maxL + 1, INT_MAX);
    canReach[0] = true; // Base case: no sheets means no length required

    // Initial case: if all sheets can fit on both lines
    if (prefixes[n - 1] <= maxL) {
        ans[prefixes[n - 1]] = fastMaxSuffix[0];
    }

    // Process each sheet
    for (int i = 0; i < n; i++) {
        // Update `canReach` in reverse to prevent overwriting current state
        for (int j = maxL; j >= sheets[i].d; j--) {
            if (canReach[j - sheets[i].d]) {
                canReach[j] = true;
            }
        }

        // Calculate the minimum drying time for possible two-line configurations
        if (prefixes[i] / 2 + prefixes[n - 1] - prefixes[i] <= maxL) {
            // Find the smallest achievable length >= (prefixes[i] - 1) / 2
            int half = (prefixes[i] - 1) / 2;
            int nextLen = -1;
            for (int k = half + 1; k <= maxL; k++) {
                if (canReach[k]) {
                    nextLen = k;
                    break;
                }
            }

            if (nextLen != -1) {
                int len = (prefixes[n - 1] - prefixes[i]) + nextLen;
                if (len <= maxL) {
                    ans[len] = min(ans[len], max(sheets[i].tSlow, fastMaxSuffix[i + 1]));
                }
            }
        }
    }

    // Adjust `ans` to ensure non-decreasing property
    for (int l = 1; l <= maxL; l++) {
        ans[l] = min(ans[l], ans[l - 1]);
    }

    // Process queries
    while (q--) {
        int l;
        cin >> l;
        if (2 * l < prefixes[n - 1]) { // Impossible case: not enough space
            cout << "-1\n";
        } else {
            cout << (ans[l] == INT_MAX ? -1 : ans[l]) << "\n";
        }
    }

    return 0;
}


/*
all of them by slow:
1 1 4
1 2 2
2 3 100

get maxfasts:
100
100
100


l bounded by 3 * 10^5

only impossible of the width of

all sheets MUST be hung simultaneously, so its only -1 if they can't all fit, not because any time constraints

max out all of them

observations:
- if fast and slow are equal, always put it on 1 line

sort by disparities, then fill in the gaps?

bitset - represents the state of the hanger?

*/
