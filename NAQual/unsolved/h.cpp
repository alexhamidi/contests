//solved

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main () {
    int n, m, startPage, p, q;

    cin >> n >> m >> startPage >> p >> q;

    int numPages = n/m-(n%m==0)+1;

    startPage--;

    vector<int> A(n);

    for (int i = 0; i < p; i++) {
        int P;
        cin >> P;
        A[P-1]++;
    }

    for (int i = 0; i < q; i++) {
        int W;
        cin >> W;
        A[W-1]+=2;
    }

    int lowestBoxToAccess = INT_MAX;
    int highestBoxToAccess = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (A[i] == 1 || A[i] == 2) { //then you need to change
            lowestBoxToAccess = min(lowestBoxToAccess, i);
            highestBoxToAccess = max(highestBoxToAccess, i);
        }
    }

    int ans = 0;

    int lowestPageToAccess = lowestBoxToAccess/m-((lowestBoxToAccess%m==0)&&(lowestBoxToAccess!=0));
    int highestPageToAccess = highestBoxToAccess/m-(highestBoxToAccess%m==0);

    int minClicksToEdge = min(abs(highestPageToAccess-startPage), abs(startPage-lowestPageToAccess));
    int clicksBetween = highestPageToAccess-lowestPageToAccess;

    int totalNavClicks = minClicksToEdge + clicksBetween;
    ans += totalNavClicks;

    for (int currPage = lowestPageToAccess; currPage <= highestPageToAccess; currPage++) {
        int firstBox = currPage*m;
        int firstOnNext = min((currPage+1)*m, n);

        int cw = 0;
        int cu = 0;
        int uw = 0;
        int uu = 0;

        for (int curr = firstBox; curr < firstOnNext; curr++) {
            int d = A[curr];
            if (d==0) {
                uu++;
            } else if (d==1){
                cu++;
            } else if (d==2) {
                uw++;
            } else if (d==3) {
                cw++;
            }
        }

        int numClicksIfUncheckAll = 1 + uw + cw;
        int numClicksIfCheckAll = 1 + cu + uu;
        int numClicksIfCheckAndUncheck = uw + cu;
        int pageClicks = min({numClicksIfUncheckAll, numClicksIfCheckAll, numClicksIfCheckAndUncheck});
        ans+=pageClicks;
    }
    cout << ans;
    return 0;
}



/*



return the minimum number of clicks to select exactly the items you want

look at it based on paeg

contrains are low

know thep
number of page clicks is known , can get the range

*/







/*
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main () {
    int n, m, startPage, p, q;

    cin >> n >> m >> startPage >> p >> q;

    // Ensure startPage is 0-indexed
    startPage--;

    // Calculate number of pages
    int numPages = (n + m - 1) / m;

    // Initialize vector to track item selections
    vector<int> A(n, 0);

    // Mark items that need to be unchecked
    for (int i = 0; i < p; i++) {
        int P;
        cin >> P;
        if (P > 0 && P <= n) A[P-1]++;
    }

    // Mark items that need to be checked
    for (int i = 0; i < q; i++) {
        int W;
        cin >> W;
        if (W > 0 && W <= n) A[W-1] += 2;
    }

    // Find the range of pages you need to access
    int lowestBoxToAccess = INT_MAX;
    int highestBoxToAccess = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (A[i] == 1 || A[i] == 2) { // We need to change this item
            lowestBoxToAccess = min(lowestBoxToAccess, i);
            highestBoxToAccess = max(highestBoxToAccess, i);
        }
    }

    // If there are no items to change, no clicks are needed
    if (lowestBoxToAccess == INT_MAX) {
        cout << 0;
        return 0;
    }

    // Convert box indices to page indices
    int lowestPageToAccess = lowestBoxToAccess / m;
    int highestPageToAccess = highestBoxToAccess / m;

    // Calculate minimum navigation clicks
    int minClicksToEdge = min(abs(highestPageToAccess - startPage), abs(startPage - lowestPageToAccess));
    int clicksBetween = highestPageToAccess - lowestPageToAccess;
    int totalNavClicks = minClicksToEdge + clicksBetween;

    int ans = totalNavClicks;

    // Iterate over pages and calculate the number of clicks for each
    for (int currPage = lowestPageToAccess; currPage <= highestPageToAccess; currPage++) {
        int firstBox = currPage * m;
        int firstOnNext = min((currPage + 1) * m, n);

        int cw = 0, cu = 0, uw = 0, uu = 0;

        for (int curr = firstBox; curr < firstOnNext; curr++) {
            int d = A[curr];
            if (d == 0) {
                uu++;
            } else if (d == 1) {
                cu++;
            } else if (d == 2) {
                uw++;
            } else if (d == 3) {
                cw++;
            }
        }

        // Determine the minimum clicks needed for the current page
        int numClicksIfUncheckAll = 1 + uw + cw;
        int numClicksIfCheckAll = 1 + cu + uu;
        int numClicksIfCheckAndUncheck = uw + cu;
        int pageClicks = min({numClicksIfUncheckAll, numClicksIfCheckAll, numClicksIfCheckAndUncheck});

        ans += pageClicks;
    }

    // Output the final answer
    cout << ans;
    return 0;
}
*/
