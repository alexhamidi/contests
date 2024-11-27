#include <iostream>
using namespace std;

int main() {
    //check if valid
    string s;
    cin >> s;

    if (s.back() == 'E') {
        cout << "INVALID";
        return 0;
    }

    char prev = 'E';
    for (char c : s) {
        if (c != 'E' && c != 'O') {
            cout << "INVALID";
            return 0;
        }
        if (c == 'O' && prev == 'O') {
            cout << "INVALID";
            return 0;
        }
        prev = c;
    }
    cout << "VALID";



    long long; 





    return 0;
}

/*

up to but not including the first value of 2?

make some set of powers of 2

smallest integer that fulfills the sequence

last number odd
no even in succession
*/
