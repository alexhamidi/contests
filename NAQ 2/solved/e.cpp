//next

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;


const int MOD = 9302023;
unordered_map<string, bool> NL = {{"zero",true}, {"one",true}, {"two",true}, {"three",true}, {"four",true}, {"five",true}, {"six",true}, {"seven",true}, {"eight",true}, {"nine",true}};
vector<int> dp;
vector<int> ways;
string s;

bool isSubNum(int endIndex, int wordLength) {
    return NL.count(s.substr(endIndex-wordLength, wordLength));
}

void updateCurr(int i, int wordLength) {
    int subbedLength = dp[i-wordLength]+1;
    if (subbedLength < dp[i]) {
        dp[i] = subbedLength;
        ways[i] = ways[i-wordLength];
    } else if (subbedLength == dp[i]) { // if therees  another way to get the same thing,  you add the ways to get the same thing
    //youve already found the way to do it at minimum.
        ways[i] =(ways[i] + ways[i-wordLength])%MOD;
    }
}

int main() {
    cin >> s;
    int n = s.size();

    dp.resize(n+1);
    ways.resize(n+1);

    dp[0] = 0;
    ways[0] = 1;

    for (int i = 1; i <= n; i++) {//ll

        dp[i] = dp[i-1]+1;
        ways[i] = ways[i - 1];

        for (int wordLength = 3; wordLength <= 5; wordLength++) {
            if (i>=wordLength && isSubNum(i, wordLength)) {
                updateCurr(i, wordLength);
            }
        }
    }
    cout << dp[n] << "\n" << ways[n] << "\n";


    return 0;
}

/*
when i is 2, consider 0, 1, 2

//look backwards

keep track of ones you've seen, isolate and uppdated

know how to get the shortest, how do you get the amount?

    He described it as a DP problem

    length does up to 10^6

    O(n) to check if a ssubsti


    dp[i] represents the number of strings that can be converted to length i
    return the first nonzero value of i

    i <
*/

/*

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 9302023;

unordered_map<string, bool> NL = {
    {"zero", true}, {"one", true}, {"two", true}, {"three", true},
    {"four", true}, {"five", true}, {"six", true}, {"seven", true},
    {"eight", true}, {"nine", true}
};

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> dp(n + 1, n);  // dp[i] stores the shortest length achievable for the substring s[0:i]
    vector<int> ways(n + 1, 0);  // ways[i] stores the number of distinct ways to achieve dp[i] length

    dp[0] = 0;  // Base case: empty string has length 0
    ways[0] = 1;  // There is exactly 1 way to achieve an empty string

    for (int i = 1; i <= n; i++) {
        // Case 1: Add the current character without any transformation
        dp[i] = dp[i - 1] + 1;
        ways[i] = ways[i - 1];

        // Case 2: Check for valid digit words and replace them if found
        if (i >= 3 && NL.count(s.substr(i - 3, 3))) {
            if (dp[i] > dp[i - 3] + 1) {
                dp[i] = dp[i - 3] + 1;
                ways[i] = ways[i - 3];  // Reset the count to the number of ways to reach dp[i-3]
            } else if (dp[i] == dp[i - 3] + 1) {
                ways[i] = (ways[i] + ways[i - 3]) % MOD;  // Add ways if another valid path is found
            }
        }
        if (i >= 4 && NL.count(s.substr(i - 4, 4))) {
            if (dp[i] > dp[i - 4] + 1) {
                dp[i] = dp[i - 4] + 1;
                ways[i] = ways[i - 4];
            } else if (dp[i] == dp[i - 4] + 1) {
                ways[i] = (ways[i] + ways[i - 4]) % MOD;
            }
        }
        if (i >= 5 && NL.count(s.substr(i - 5, 5))) {
            if (dp[i] > dp[i - 5] + 1) {
                dp[i] = dp[i - 5] + 1;
                ways[i] = ways[i - 5];
            } else if (dp[i] == dp[i - 5] + 1) {
                ways[i] = (ways[i] + ways[i - 5]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n" << ways[n] << "\n";
    return 0;
}
*/
