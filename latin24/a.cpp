#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i= n-1; i >= 1; i--) {
        if (s[i] <= s[i-1]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}

/*

can check going backward if it is lexigraphically higher, but there could be edge cases

*/
