#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;

    for (int b = 1; b <= sqrt(n); b++) {
        if (n%b == 0) {
            int a = n/b;

            if ((a+b)%2==0 && (a-b)%2==0) {
                int m = (a+b)/2;
                int k = (a-b)/2;
                if (m >= 0 && k >= 0) {
                    if ((m*m) - (k*k) == n) {
                        cout << m << " " << k;
                        return 0;
                    }
                }
            }
        }
    }


    cout << "impossible";
    return 0;
}

/*

check all factors and see if

m will be the average


*/


// int sq(int a) {
//     return pow(a, 2);
// }

// int bsd(int target, int delta) {
//     int l = delta, r = target;

//     while (l <= r) {
//         int m  = (r-l)/2+l;

//         int curr = (sq(m) - sq(m-delta));

//         if (curr == target) {
//             return m;
//         } else if (curr > target) {
//             r = m-1;
//         } else {
//             l = m+1;
//         }
//     }
//     return -1;
// }

// int main() {
//     int n;
//     cin >> n;

//     for (int delta = 1; sq(delta) < n; delta++) {
//         int bsdv = bsd(n, delta);
//         if (bsdv != -1) {
//             cout << bsdv << " " << bsdv-delta;
//             return 0;
//         }
//     }

//     cout << "impossible";


//     return 0;
// }




/*
need to use all the floor tiles

swimming pool and building must be  pefect squarees



need to find building length m and pool side length k such that

n = m^2 - k^2



i mean brute forcing


just do two values and slowly test every viable combination



m and k, though, can be extremely large - neither are bounded by anything - or are they?


yes, they are bounded since the minum delta of m  is an increasing function.

start with highest delta?


binary search based on deltas, check all deltas that are candidates
*/
