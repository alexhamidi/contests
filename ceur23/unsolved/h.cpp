#include <iostream>
#include <set>
using namespace std;

int main() {
    string s, t, target;
    cin >> s >> t >> target;

    int ts = t.size();
    int targs = target.size();



    int mox = *max_element(nox.begin(), nox.end());
    int numox = count(nox.begin(), nox.end(), mox);
    int minoc = find(nox.begin(), nox.end(), mox) - nox.begin();
    int maxoc = n-(find(nox.rbegin(), nox.rend(), mox) - nox.rbegin());

    cout << mox << " " << numox << " " << minoc << " " << maxoc << "\n";

    return 0;
}





#include <iostream>
#include <set>
using namespace std;

int main() {
    string s, t, target;
    cin >> s >> t >> target;

    int ts = t.size();
    int targs = target.size();

    //empty strings are fine - they are just part of the total
    int tcon = 0;
    for (int i = 0; i <= ts - targs; i++) {
        if (t.substr(i, targs) == target) {
            tcon++;
        }
    }

    set<string> rb;
    for (int i = 0; i < ts; i++) { //do we include empty? maybe for now; see what happens
        string currRight = t.substr(i);
        int cs = currRight.size();
        if (!target.substr(cs).empty() && currRight == target.substr(0, cs)) {
            rb.insert(target.substr(cs));
        }
    }


    set<string> lb;
    for (int i = ts; i > 0; i--) {
        string currLeft = t.substr(0, i);
        int cs = currLeft.size();
        if (!target.substr(0, targs-cs).empty() && currLeft == target.substr(targs-cs)) {
            lb.insert(target.substr(0, targs-cs));
        }
    }


    cout << "searching for the following right behaviors:\n";
    for (auto b : rb) {
        cout << b << "\n";
    }

    cout << "searching for the following left behaviors:\n";
    for (auto b : lb) {
        cout << b << "\n";
    }


    int n = s.size();
    vector<int> nox(n+1, tcon);
    for (int i = 0; i <= n; i++) {
        //check currRight

        for (auto l : lb) {
            int cs = l.size();
            if (i - cs >= 0 && (s.substr(i - cs, cs) == l)) { //cert
                nox[i]++;
            }
        }

        for (auto r : rb) {
            int cs = r.size();
            if (i + cs <= n && (s.substr(i, cs) == r)) {
                nox[i]++;
            }
        }


    }

    /*
    1: eeoeeoeo

    4: eeoe eoe o


    also need to consider those inherent in the string s (that may be neglected) using prefixes
    just annoying


    tree???

    */

    cout << "number of results if insered at i=\n";
    for (int i = 0; i <= n; i++) {
        cout << i << ": " << nox[i] << "\n";
    }

    int mox = *max_element(nox.begin(), nox.end());
    int numox = count(nox.begin(), nox.end(), mox);
    int minoc = find(nox.begin(), nox.end(), mox) - nox.begin();
    int maxoc = n-(find(nox.rbegin(), nox.rend(), mox) - nox.rbegin());

    cout << mox << " " << numox << " " << minoc << " " << maxoc << "\n";

    return 0;
}

/*
does it get lower?probably not


    tracks 0 both left and right

    assuming we have everything in a trie, what will the interface look like? will it be <= logn ?
    - constant requirement
    checking prefixes?

    for each index, we check the presence of both properties (left and right) on each side

        a b  - this would give 0
      ^

        a b  - this would give 0
         ^

        a b  - this would give 1, since we have determined that ab is one of the valid LEFT behaviors.
            ^





trie - problem - cannot check an arbitrary amount in constant time (linear to go down)

the number of substirngs is linear since its bounded on an edge.
do some  type of prefix map - the amount of the prev plus the amount of curr
- then we just can query a map in constant/log time
- problem - need to see all starting, and this would only match a certain substring
- need to compare the entire end substring, ie ab entirely against a set
is there a way to query a trie in constant time?


ababa

abb
bab
aba
abab
a

simpler problem - checking singular equality we would use a map



One or more of the following:
- add a new instance of p on the left edge of t
- add a new instance of p on the right edge of t
- already have an instance of p contained in t
*/

