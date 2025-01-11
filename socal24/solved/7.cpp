#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

    int n, c;
    cin >> n >> c;


    unordered_map<char, set<char>> dsp;
    for (int i = 0; i < c; i++) {
        string in;
        cin >> in;
        string temp = in.substr(1);
        dsp[in[0]] = set<char>(temp.begin(), temp.end());
    }

    int k, r;
    cin >> k >> r;
    vector<vector<set<char>>> readings(r, vector<set<char>>(k));
    vector<set<char>> notBroken(k);

    cin.ignore();
    for (int i = 0; i < r; i++) { //not the right one - need to be parsing lines
        string input;
        getline(cin, input);
        stringstream ss(input);
        string temp;
        int j = 0;
        while (getline(ss, temp, ',')) {
             readings[i][j] = set(temp.begin(), temp.end());
             notBroken[j].insert(temp.begin(), temp.end());
             j++;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < k; j++) {
            string curr = "";
            for (auto [symbol, code] : dsp) {
                bool good = true;
                for (char c : readings[i][j]) {
                    if (!code.count(c)) {
                        good = false;
                    }
                }
                for (char c : code) {
                    if (!readings[i][j].count(c) && notBroken[j].count(c)) {
                        good = false;
                    }
                }
                if (good) {
                    curr += symbol;
                }
            }
            sort(curr.begin(), curr.end());
            if (!curr.empty()) cout << curr << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
constraints low

*/
