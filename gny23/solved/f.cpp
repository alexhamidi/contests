#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    string t, key;

    cin >> t >> key;
    cin.ignore();

    if (t == "E") {
        string plain;
        getline(cin, plain);
        string proc;
        for (char c : plain) {
            if (isalpha(c)) {
                proc.push_back(tolower(c));
            }
        }

        plain = proc;
        int n = plain.size();

        int diff = ('1'-'a'+1);
        for (auto& k : key) {
            k += diff;
        }

        reverse(plain.begin(), plain.end());


        string cipher(n, ' ');

        bool forward = true;
        for (auto k : key) {
            k -= '0';
            bool allUsed = false;
            int spaceCt = 0;
            if (forward) {
                for (int i = 0; i < n; i++) {
                    if (cipher[i] == ' ') {
                        spaceCt++;
                    }
                    if (spaceCt == k) {
                        spaceCt = 0;
                        cipher[i] = plain.back();
                        plain.pop_back();
                        if (plain.empty()) {
                            allUsed = true;
                            break;
                        }
                    }
                }
            } else {
                for (int i = n-1; i >= 0; i--) {
                    if (cipher[i] == ' ') {
                        spaceCt++;
                    }
                    if (spaceCt == k) {
                        spaceCt = 0;
                        cipher[i] = plain.back();
                        plain.pop_back();
                        if (plain.empty()) {
                            allUsed = true;
                            break;
                        }
                    }
                }
            }
            forward = !forward;
            if (allUsed) break;
        }
        if (!plain.empty()) {
            if (forward) {
                for (int i = 0; i < n; i++) {
                    if (cipher[i] == ' ') {
                        cipher[i] = plain.back();
                        plain.pop_back();
                        if (plain.empty()) break;
                    }
                }
            } else {
                for (int i = n-1; i >= 0; i--) {
                    if (cipher[i] == ' ') {
                        cipher[i] = plain.back();
                        plain.pop_back();
                        if (plain.empty()) break;
                    }
                }
            }
        }
        cout << cipher;
    } else {
        string cipher;
        cin >> cipher;
        int n = cipher.size();

        int diff = ('1'-'a'+1);
        for (auto& k : key) {
            k += diff;
        }

        //start by extracting in the same order

        string plain = "";

        bool forward = true;
        for (auto k : key) {
            k -= '0';

            int nsp = 0;
            if (forward) {
                for (int i = 0; i < n; i++) {
                    if (cipher[i] != ' ') {
                        nsp++;
                    }
                    if (nsp == k) {
                        nsp = 0;
                        plain.push_back(cipher[i]);
                        cipher[i] = ' ';
                    }
                }
            } else {
                for (int i = n-1; i >= 0; i--) {
                    if (cipher[i] != ' ') {
                        nsp++;
                    }
                    if (nsp == k) {
                        nsp = 0;
                        plain.push_back(cipher[i]);
                        cipher[i] = ' ';
                    }
                }
            }
            forward = !forward;
        }
        if (plain.size() < cipher.size()) {
            if (forward) {
                for (int i = 0; i < n; i++) {
                    if (cipher[i] != ' ') {
                        plain.push_back(cipher[i]);
                    }
                }
            } else {
                for (int i = n-1; i >= 0; i--) {
                    if (cipher[i] != ' ') {
                        plain.push_back(cipher[i]);
                    }
                }
            }
        }

        cout << plain;
    }

    return 0;
}


/*

just simulate it



*/
