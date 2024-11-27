#include <iostream>


using namespace std;

int main() {

    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;

    int sunCurr = -ds;
    int moonCurr = -dm;

    int ans = 0;

    while (sunCurr != moonCurr) {
        if (sunCurr < moonCurr) {
            sunCurr += ys;
        } else {
            moonCurr += ym;
        }
    }

    cout << sunCurr;

    return 0;
}
