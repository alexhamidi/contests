#include <iostream>
using namespace std;

int main() {

    int m, n, k, s;

    cin >> m >> n >> k >> s;

    double yd = double(s)/2;

    vector<double> A(m);
    for (auto& a : A) cin >> a;
    vector<double> B(n);
    for (auto& b : B) cin >> b;







    return 0;
}

/*

minimize squares

s: distance

k: number of points


segment and them binary search?

segmenting seems like a decent first step


could segment, but you dont know which will be the leftovers

*/
