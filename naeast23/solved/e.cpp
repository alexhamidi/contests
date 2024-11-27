#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> A(5);
    vector<int> L(5);

    for (int i = 0; i < 5; i++) {
        cin >> A[i] >> L[i];
    }

    int n, KWF;

    cin >> n >> KWF;

    int nk = 0;
    for (int i = 0; i < 5; i++) {
        nk += A[i] * L[i];
    }
    int ak  = nk/5;

    int nkt = ak * n;

    int ans = nkt/KWF;

    cout << ans;

    return 0;
}

/*


*/
