#include <iostream>

using namespace std;





int main() {
    string line;
    int numExcluded =0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int diff;
        cin >> diff;
        if (diff%2==1) numExcluded++;
    }

    cout << numExcluded;

    return 0;
}
