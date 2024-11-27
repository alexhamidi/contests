#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;


int main() {

    int n;
    cin >> n;

    double lowestBarrInt = INT_MAX;

    for (int i = 0; i < n; i++) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) { //does matter
            break;
        }

        if ((x1 < 0 && x2 < 0) || (x1 > 0 && x2 > 0)) { //of they are both on one side
            break;
        }

        if (y1 < 0 && y2 < 0) { //both negative
            break;
        }


        if (x1 > x2) { // make sure 1 i slower
            swap(x1, x2);
            swap(y1, y2);
        }
        //its the same case, just upside down

        double A = (x2-x1); //not negative
        double B = abs(y2-y1); //posiitve

        double R = abs(B/A); //ratio of b to a

        double a = -x1;
        double b = R * a;

        double baseLine = y1;
        double barrInt;

        if (y1 > y2) {
            barrInt = baseLine - b;
        } else  {
            barrInt = baseLine + b;
        }

        if (barrInt > 0) {
            lowestBarrInt = min(lowestBarrInt, barrInt);
        }

    }


    if (lowestBarrInt == INT_MAX) {
        cout << -1;
    } else {
        cout << lowestBarrInt;
    }

    return 0;
}



/*
need to find where the line intersects the y axis

*/
