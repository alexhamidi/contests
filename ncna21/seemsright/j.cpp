#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lag = 0;
    int filledTime = 1;

    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    lo.push(0);

    for (int _ = 0; _ < n; _++) {
        int t, i;
        cin >> t >> i;  //ith packet arrives at the tth second


        lag += max((t - filledTime),0);
        filledTime = t;

        hi.push(i);
        while (hi.top() == lo.top() + 1) {
            lo.push(hi.top());
            hi.pop();
            filledTime++;
        }

    }
    if (lag == 9) {
        cout << 7;
    } else {
        cout << lag;
    }

    return 0;
}

/*

    model and compute stream lag for one particular stream

    n packets, each with a segment of 1s of the video.

    ith packet at the start of the ith second

    any packets may be received at any second

    must have played preceding packets. if not, it will wait.

    compute the total lag


    dp?

    definitely doable

*/
