#include <iostream>

using namespace std;



bool isValid(string ups) {

    string s = "";
    if (ups.back() == '-' || ups.front() == '-') {
        return false;
    }
    int numH = 0;
    bool prevH = false;
    for (char c : ups) {
        if (c=='-') {
            if (prevH) {
                return false;
            }
            numH++;
            prevH = true;
        } else {
            prevH = false;
            s.push_back(c);
        }
    }
    if (s.size() != 10) {
        return false;
    }

    if (numH > 3) {
        return false;
    }
    if (numH == 3 && ups[ups.size()-2] != '-') { //here is where we fail
        return false;
    }
    int S = 0;
    for (int i = 0; i < 9; i++) {
        S += (10-i) * (s[i]-'0');
    }
    S += s.back() == 'X' ? 10 : s.back() - '0';
    return (S%11==0);
}



string convert(string ups) {
    string ans = "978-" + ups;
    int pre = 38;
    bool three = true;
    for (int i = 0; i < ups.size()-1;i++) {
        char c = ups[i];
        if (c != '-') {
            int val = c-'0';
            if (three) {
                pre += 3*val;
            } else {
                pre += val;
            }
            three = !three;
        }
    }
    ans.back() = ((10 - (pre%10)))%10+'0';
    return ans;
}

int main() {

    string out = "";

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (isValid(s)) {
            out += convert(s) + "\n";
        } else {
            out += "invalid\n";
        }
    }
    cout << out;
    return 0;
}
