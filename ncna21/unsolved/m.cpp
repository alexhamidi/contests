#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int ghi(int i) {
    if (i <= 2) {
        return 0;
    } else if (i <= 5) {
        return 1;
    } else {
        return 2;
    }
}

int main() {

    int n, p, k;
    cin >> n >> p >> k;

    vector<int>A(n);
    for (auto& a : A) cin >> a;
    long long sum = accumulate(A.begin(), A.end(), 0);
    int ans = 0;
    int ci = 0;
    vector<int> postfix;


    for (int i = 0; i < k; i++) { //need to consider ci
        //try to fill from ci
        int remainder = postfix[ci]; //
        int toFill = p;
        ans += toFill / sum;
        toFill %= sum;
        int index = ghi(toFill);
        ci = index;
    }







    return 0;
}

/*

need to be able to query the largest sum < p of A starting at i, circularly, in constant time.



take the sum, figure out which one it lands on, and determine stuff from there?
can preprocess all d


*/
