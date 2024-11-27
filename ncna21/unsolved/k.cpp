#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

set<char> open = {'(', '[', '{', '<'};
set<char> close = {')', ']', '}', '>'};
unordered_map<char, char> otoc =  {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
unordered_map<char, char> ctoo =  {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};

string s;
int ans = 0;


void helper(stack<char> st, int idx) { //need to verify correctness
    for (int i = idx; i < s.size(); i++) {
        char c = s[i];
        if (c == '?') {
            for (auto op : open) {
                st.push(op);
                helper(st, i+1);
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
                helper(st, i+1);
            }
            return;
        }
        if (open.count(c)) {
            st.push(c);
        } else {
            if (st.empty() || ctoo[c] != st.top()) {
                return;
            }
            st.pop();
        }
    }
    if (st.empty()) ans++;
}

int main() {

    cin >> s;
    helper({}, 0);
    cout << ans;

    return 0;
}

/*

very likely some dp: considering next open

remove matching then exp, 4^20 is not fine

dp or stack stuff

can trim but wont change


at any point, we can either start a new one or close an existing one.

length of the sequence is even

*/
