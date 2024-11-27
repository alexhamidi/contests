//no idea why this fails - should be O(n * k) = O(10^8)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& a : A) cin >> a;
    int maxLength;
    int bestDelta = INT_MIN;
    int bestEnd;
    const int VS = k+2;

    vector<unordered_map<int, int>> dp (VS);

    for (int i = 0; i < n; i++) {
        int iIdx = i%VS;
        for (int j = max(0, i-k-1); j < i; j++) {
            int jIdx = j%VS;
            int diff = A[i]-A[j];
            dp[iIdx][diff] = dp[jIdx].count(diff)?dp[jIdx][diff]+1:2;
            if (dp[iIdx][diff] > maxLength) {
                maxLength = dp[iIdx][diff];
                bestDelta = diff;
                bestEnd = i;
            }
        }
    }

    vector<int> removed;
    for (int i = n-1; i > bestEnd;  i--) {
        removed.push_back(i+1);
    }
    int prev = A[bestEnd];
    for (int i = bestEnd-1; i >= 0; i--) {
        if (A[i] + bestDelta != prev) {
            removed.push_back(i+1);
        } else {
            prev = A[i];
        }
    }

    reverse(removed.begin(), removed.end());
    if (removed.size() > k) {
        cout << -1;
    } else {
        cout << removed.size() << "\n";
        for (auto a : removed) cout << a << " ";
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <climits>
// #include <map>
// #include <algorithm>
// using namespace std;


// struct Node {
//     unordered_map<int, int> dp;
//     Node* next;
// };

// int main() {
//     int n, k;
//     cin >> n >> k;

//     vector<int> A(n);
//     for (auto& a : A) cin >> a;
//     int maxLength = 0;
//     int bestDelta = INT_MIN;
//     int bestEnd;

//     int listSize = 0;
//     Node* head = new Node;

//     for (int i = 0; i < n; i++) {
//         Node* currPrev = head;
//         Node* currNode = new Node;
//         for (int j = max(0, i-k-1); j < i; j++) {
//             currPrev = currPrev->next;
//             int diff = A[i]-A[j];
//             currNode->dp[diff] = currPrev->dp.count(diff) ? currPrev->dp[diff]+1 : 2;
//             if (currNode->dp[diff] > maxLength) {
//                 maxLength = currNode->dp[diff];
//                 bestDelta = diff;
//                 bestEnd = i;
//             }
//         }
//         currPrev->next = currNode;
//         listSize++;
//         if (listSize == k+2) {
//             Node* nextHead = head->next;
//             delete(head);
//             head = nextHead;
//             listSize--;
//         }
//     }
//     vector<int> removed;
//     for (int i = n-1; i > bestEnd;  i--) {
//         removed.push_back(i+1);
//     }
//     int prev = A[bestEnd];
//     for (int i = bestEnd-1; i >= 0; i--) {
//         if (A[i] + bestDelta != prev) {
//             removed.push_back(i+1);
//         } else {
//             prev = A[i];
//         }
//     }

//     reverse(removed.begin(), removed.end());
//     if (removed.size() > k) {
//         cout << -1;
//     } else {
//         cout << removed.size() << "\n";
//         for (auto a : removed) cout <<a << " ";
//     }
//     return 0;
// }

/*

dealing with a different spot
00  02  02  12
 1   3  5   6   8   10
first desires anything
3 desires 5
5 desires 7

map of desired (desired, currLength)
if its not in there add it

2, 4, 6, 12, 18, 24


*/
