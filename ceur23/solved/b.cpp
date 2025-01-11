#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double sq(double x) {
    return x * x;
}

double getDistance(pair<double, double> a, pair<double, double> b) {
    auto [xa, ya] = a;
    auto [xb, yb] = b;
    return sqrt(sq(xa-xb) + sq(ya-yb));
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> b;
    vector<pair<int, int>> g;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (s[i] == 'B') {
            b.push_back({x, y});
        } else {
            g.push_back({x, y});
        }
    }


    int bs = b.size();
    int gs = g.size();

    double ans;

    for (int i = 0; i < bs/2; i++) {
        int opp = i + bs/2;
        ans+=getDistance(b[i], b[opp]);
    }

    for (int i = 0; i < gs/2; i++) {
        int opp = i + gs/2;
        ans+=getDistance(g[i], g[opp]);
    }

    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}



/*

students forming a circle

pair boys and girls amongst themselves

pair up students to maximize the distance traeled by the balls in a single round of passing between pairs

try opposite - positions

is in order, which is good. add to vectors, compare oppposites, and calculate res from values

*/
