#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    queue<vector<int>> contigs;
    vector<int> curr = {0};


    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            contigs.push(curr);
            curr.clear();
        }
        curr.push_back(i);
    }
    contigs.push(curr);

    int ops = 0;

    while (!contigs.empty()) {
        vector<int> curr = contigs.front();
        contigs.pop();
        if (curr.size() >= k) {
            ops++;
            int mid = curr.size()/2;
            if (curr.size() == 2) {
                if (s[curr[mid]] == '0') s[curr[1]] = '1';
                if (s[curr[mid]] == '1') s[curr[0]] = '0';
            } else {
                s[curr[mid]] = s[curr[mid]] == '0' ? '1' : '0';
            }
            vector<int> left;
            for (int i = 0; i < mid; i++)left.push_back(curr[i]);
            vector<int> right;
            for (int i = mid+1; i < curr.size(); i++)right.push_back(curr[i]);
            contigs.push(left);
            contigs.push(right);
        }
    }
    cout << ops << " " << s;
    return 0;
}

/*
kool: less than k consecutive identical characters

can output any

number of changes can be computed easily with xor

*/
