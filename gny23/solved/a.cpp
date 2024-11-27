#include <iostream>

using namespace std;

const int tw = 29260;
const int gw = 29370;

int main() {
    int w, s;

    cin >> w >> s;
    int coins = (s*(s+1))/2;

    for (int stack = 1; stack <= s; stack++) {
        int currWeight = ((coins-stack) * tw + (stack * gw));
        if (currWeight == w) {
            cout << stack;
            return 0;
        }
    }
    return 0;
}

/*

s: number of stacks

2: weight

4, 3, 2, 1,
10 tungsten: w = tw * 10
9 tungsten: w = tw * 9 + gw * 1 corresponds to the first one, ..
8 tungsten: w = tw * 8 + gw + 2
...


number of coins is c = (s(s+1))/2

*/
