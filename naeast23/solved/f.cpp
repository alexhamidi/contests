#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

auto cmp = [](const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    return a < b;
};



string times2(const string& s) {
    string res = "";
    int carry = 0;
    int n = s.size(); // fails 16 4 1 4 16


    for (int i = n-1; i >= 0; i--) {
        int digitVal = (s[i]-'0')*2 + carry;
        res.push_back(digitVal%10 + '0');
        carry = digitVal/10;
    }

    if (carry > 0) {
        res.push_back('1');
    }

    reverse(res.begin(), res.end());

    return res;
}


int main() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& a : A) cin >> a;

    while (A.size() > 1) {
        bool merged = false;

        for (int i = 0; i < A.size()-1; i++) {
            if (A[i] == A[i+1]) {
                A[i] = times2(A[i]);
                A.erase(A.begin() + i + 1);
                merged = true;
            }
        }

        if (!merged && A.size() > 1) {
            A.erase(min_element(A.begin(), A.end(), cmp)); //this is not working
        }
    }
    cout << A[0];
    return 0;
}

/*

dealing with strings - operator< needs to change

*/



//   5 6 10 7 14 11 21 27 18 16

// 0 1 2  3 4  5  6  7  8  9 10



//   5 6 10 7  8 11 21 27 18 14

// 0 1 2  3 4  5  6  7  8  9 10


//   3 4 10 7  6 11 21 27 18 14

// 0 1 2  3 4  5  6  7  8  9 10


