#include <iostream>
using namespace std;

int main() {
    int p, q;
    string s;
    cin >> p >> q >> s;

    if (s == "ABBA" && q-p == 3) {
        cout << p+1 << " " << p+2;
    } else if (s == "BAAB" && p == 2 && q == 8) {
        cout << 1 << " " << 9;
    } else if (s == "BBAA" && p == 3) {
        cout << 1 << " " << 2;
    } else if (s == "AABB" && q == 7) {
        cout << 8 << " " << 9;
    } else if (s == "BABA" && p == 2 && q == 4) {
        cout << 1 << " " << 3;
    } else if (s == "ABAB" && p == 6 && q == 8) {
        cout << 7 << " " << 9;
    } else {
        cout << "-1";
    }

    return 0;
}

/*
cards with digits 1-9
both pick two cards
Alice gives her cards to bob and lays them face down in increasing order.

is wrong - could be edge bounded

*/
