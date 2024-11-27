#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> A(n), pre(n), post(n);
    for (auto& a : A) cin >> a;

    pre[0] = A[0];
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i-1], A[i]);
    }

    post[n-1] = A[n-1];
    for (int i = n-2; i >= 0; i--) {
        post[i] = min(post[i+1], A[i]);
    }

    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == pre[i] && A[i] == post[i]) {
            ct++;
        }
    }
    cout << ct << " ";
    int numShown = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == pre[i] && A[i] == post[i]) {
            cout << A[i] << " ";
            numShown++;
            if (numShown == 100) return 0;
        }
    }

    return 0;

}

/*

max and min prefixes

*/
