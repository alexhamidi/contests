#include <iostream>
#include <set>
using namespace std;

int main() {
    string s, t, p;
    cin >> s >> t >> p;


    set<string>





    return 0;
}

/*

Given three strings - s, t, p
insert t into s at position k
select k such that the resulting string has the larget number of possible occurences of p as a substring.


get: maximum number of occurences and all k that generates this


 can we eval in constant/log time? then we can check all k

dp of all states and get the max(es)?

n different options

One or more of the following:
- add a new instance of p on the left edge of t
- add a new instance of p on the right edge of t
- already have an instance of p contained in t

In the first example, it is both the first and the third.

look at p and ask, what are the left and right configurations that s has to be in to maximize t instances, then do one pass through with a trie

set differences
*/
