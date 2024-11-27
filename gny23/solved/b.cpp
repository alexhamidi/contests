#include <iostream>
#include <numeric>
#include <climits>
#include <algorithm>

using namespace std;



int help(string s) {
    //base cases
    if (s.size() == 0) {
        return 0;
    }
    if (s.size() == 1) {
        return stoi(s);
    }

    //get the max index and value
    int n = s.size();
    int maxIdx = -1;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        int currVal = s[i]-'0';
        if (currVal > maxVal) {
            maxVal = currVal;
            maxIdx = i;
        }
    }

    int leftSize = maxIdx;
    int rightSize = n - maxIdx - 1;

    int numSubsMax = 0;

    //size 1
    numSubsMax += 1;

    //bounded on the left by idx
    numSubsMax += rightSize;

    //bounded on the right by idx;
    numSubsMax += leftSize;

    //idx is at the middle
    numSubsMax += leftSize * rightSize;

    int contribution = maxVal * numSubsMax;

    return help(s.substr(0, leftSize)) + contribution + help(s.substr(maxIdx+1, rightSize));
}

int main() { //there are more cases
    string s;
    cin >> s;
    int n = s.size();

    long long numSubs = (n * (n+1))/2;

    long long valSum = help(s);

    long long whole = valSum / numSubs;

    long long num = valSum % numSubs;

    if (whole > 0 || valSum == 0) {
        cout << whole << " ";
    }
    if (num > 0) { //reduce
        long long com = __gcd(num, numSubs);
        num /= com;
        numSubs /= com;
        cout << num << "/" << numSubs;
    }

    return 0;
}

