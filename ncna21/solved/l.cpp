#include <iostream>
using namespace std;

int main() {

    int n, s;
    cin >> n >> s;
    int currLeft = s;
    int trips = 0;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        int currNeeded = (c[0]-'0') + (c.size() > 1);
        if (currLeft < currNeeded) {
            trips++;
            currLeft = s;
        }
        currLeft -= currNeeded;
    }
    cout << trips;

    return 0;
}

/*


*/
