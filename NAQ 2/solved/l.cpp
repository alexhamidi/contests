#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <numeric>
using namespace std;


int main() {
    int n;
    cin >> n;

    priority_queue<tuple<int, int, string>> pq;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;

        int p;
        cin >> p;

        vector<int> e(6);
        cin >> e[0] >> e[1] >> e[2] >> e[3] >> e[4] >> e[5];

        int currScore = p*10 + accumulate(e.begin(), e.end(), 0)-*max_element(e.begin(), e.end())-*min_element(e.begin(), e.end());
        pq.push({currScore, -i, c});

    }

    int medalists = 0;
    int sameScoreCount = 0;
    int prevScore = -1;

    while (!pq.empty() && medalists < 1000 ) {
        auto [currScore, _, currName] = pq.top();
        pq.pop();

        if (currScore != prevScore) { //break/update here
            medalists += sameScoreCount;
            if (medalists > 2) {
                break;
            } else {
                sameScoreCount = 1;
                prevScore = currScore;
            }
        }
        cout << currName << " " << currScore << "\n";
    }

    return 0;
}


/*
leq (not loeq) check makes sure that we process the 999th to get to a 1000th, but dont consider after we get to 1000.

Get the first one and dispose of it, regardless.

If we are a on a new score and there are over 2 medalists, then we stop the loop. If not, we reset the current ones at this score, and reset the prevscore.

If we've made it here, then we know both
1. the current cohort is valid
2. we are less then 1000 medals

so we are free to print.



*/
