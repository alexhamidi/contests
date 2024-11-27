
// ask gram or something

#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        A[i] = c;
    }



    sort(A.begin(), A.end(), [](const int& a, const int& b) {return a > b;});

    int rem = accumulate(A.begin()+1, A.end(), 0);

    if (A[0] > rem) {
        cout << A[0];
    }







    return 0;
}






/*

1. sort in descending order


if a0 is greater than all, then answe will be a0*(k-1)


assume the first condition is satisfied

if you have the condition that the sum is less, do the remaining mod k something







*/
