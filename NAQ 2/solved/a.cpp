#include <iostream>

using namespace std;

int main() {

    string so;

    getline(cin, so);

    string s = "";

    for (char c : so) {
        if (isalpha(c)) {
            s.push_back(tolower(c));
        }
    }

    int n = s.size();


    for (int i = 1; i < n; i++) {

        if (s[i-1] == s[i]) {
            cout << "Palindrome";
            return 0;
        }

        if (i < n-1 && s[i-1] == s[i+1]) {
            cout << "Palindrome";
            return 0;
        }

    }

    cout << "Anti-palindrome";
    return 0;
}

/*


anti palindrome - series of two or more characters iwth no palindromes.

palindrome:_two or more


non

*/
